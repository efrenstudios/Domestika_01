// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/World.h"
#include "TimerManager.h"



void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//ejecute Stop Shoot cada cantidad de tiempo
	GetWorldTimerManager().SetTimer(
		timerStopShootHandle,    //el handle que se guarda para despues parar el timer
		this,                    //se indica que yo soy el dueño del timer
		&AMyActor::StopShoot,    //se indica la funcion que ejecutara ek timer
		tiempoPararDisparo);     //se indica el tiempo que va a tardar en ejecutarse la funcion

	//ejecuta Shoot cada cierta cantidad de tiempo y se repita indefinidamente
	GetWorldTimerManager().SetTimer(timerShootHandle, this, &AMyActor::Shoot, tiempoEntreDisparo, true);
}

void AMyActor::Shoot()
{
	//obtengo mi posicion y rotacion
	FVector pos = GetActorLocation();
	FRotator rot = GetActorRotation();

	//creo una instancia de un objeto en mi posicion y rotacion
	GetWorld()->SpawnActor<AActor>(objetoASpawnear, pos, rot);
}

void AMyActor::StopShoot()
{
	//detengo los disparos
	GetWorldTimerManager().ClearTimer(timerShootHandle);
	//llamo a Rotate cada cierto tiempo
	GetWorldTimerManager().SetTimer(timerStopRotateHandle, this, &AMyActor::StopRotate, tiempoPararRotate);
	//llamo a StopRotate despues frena a determinado tiempo a Rotate
	GetWorldTimerManager().SetTimer(timerRotateHandle, this, &AMyActor::Rotate, tiempoEntreRotate, true);
}

void AMyActor::Rotate()
{
	AddActorLocalRotation(velocidadRotate);
}

void AMyActor::StopRotate()
{
	//detengo la rotacion
	GetWorldTimerManager().ClearTimer(timerRotateHandle);
	//vuelvo a programar Stop Shoot para frenar los disparos
	GetWorldTimerManager().SetTimer(timerStopShootHandle, this, &AMyActor::StopShoot, tiempoPararDisparo);
	//vuelvo a programar Shoot cada cierta cantidad de tiempo y se repita indefinidamente
	GetWorldTimerManager().SetTimer(timerShootHandle, this, &AMyActor::Shoot, tiempoEntreDisparo, true);
}
