// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

AJugador::AJugador()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void AJugador::BeginPlay()
{
	Super::BeginPlay();
	
}


void AJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	InputComponent->BindAxis("Vertical", this, &AJugador::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &AJugador::HorizontalAxis);

	InputComponent->BindAction("Fire", IE_Pressed, this, &AJugador::FirePressed);
	InputComponent->BindAction("Fire", IE_Released, this, &AJugador::FireReleased);

	InputComponent->BindAction("Forward", IE_Pressed, this, &AJugador::ForwardPressed);
	InputComponent->BindAction("Forward", IE_Released, this, &AJugador::ForwardReleased);
}

void AJugador::VerticalAxis(float value)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(value* Velocity* deltaTime, 0, 0));

}

void AJugador::HorizontalAxis(float value)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(0, value * rotatorVelocity * deltaTime, 0));
}



void AJugador::FirePressed()
{
		GetWorldTimerManager().SetTimer(fireTimer, this, &AJugador::Fire, fireRate, true);
}

void AJugador::FireReleased()
{
	GetWorldTimerManager().ClearTimer(fireTimer);
}

void AJugador::Fire()
{
	GetWorld()->SpawnActor<AActor>(bulletBlueprint, GetActorLocation(), GetActorRotation());
}



void AJugador::ForwardPressed()
{
	forwardPressed = true;
}

void AJugador::ForwardReleased()
{
	forwardPressed = false;
}



void AJugador::Tick(float deltaSeconds)
{
	if (forwardPressed)
	{
		
		float deltaTime = GetWorld()->GetDeltaSeconds();
		AddActorLocalOffset(FVector(Velocity * deltaTime, 0, 0));
	}
}
