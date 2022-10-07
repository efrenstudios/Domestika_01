// Fill out your copyright notice in the Description page of Project Settings.


#include "Condiciones.h"
#include "TimerManager.h"
#include "Engine/World.h"

ACondiciones::ACondiciones()
{
	vida = 100;
	danoPorSegundo = 10;
	PrimaryActorTick.bCanEverTick = true;

}

void ACondiciones::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandle, this, &ACondiciones::Disparar, tiempoDisparos, true);


}

void ACondiciones::Disparar()
{
	
	GetWorld()->SpawnActor<AActor>(blueprintBala, GetActorLocation(), GetActorRotation());
	cantidadDisparos++;
	if (cantidadDisparos >= cantidadMaxDisparos)
	{
		GetWorldTimerManager().ClearTimer(timerHandle);
	}
}


// Called every frame
void ACondiciones::Tick(float DeltaTime)
{
	vida = vida - danoPorSegundo * DeltaTime;
	
	if (vida <= 0)
	{
		Destroy();
	}
}

