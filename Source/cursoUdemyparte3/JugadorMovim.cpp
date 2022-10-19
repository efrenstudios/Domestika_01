// Fill out your copyright notice in the Description page of Project Settings.


#include "JugadorMovim.h"
#include "Engine/World.h"                                   
#include "Components/InputComponent.h"


AJugadorMovim::AJugadorMovim()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AJugadorMovim::BeginPlay()
{
	Super::BeginPlay();
	initialPosition = GetActorLocation();
	initialLife = life;
	initialRotate = GetActorRotation();
}

void AJugadorMovim::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (life <= 0)
	{
		if (respawns > 0)
		{
		SetActorLocation(initialPosition);
		SetActorRotation(initialRotate);
		life = initialLife;
		respawns--;
		}
		else
		{
			Destroy();
		}
	}
}


void AJugadorMovim::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("Forward", this, &AJugadorMovim::ForwardAxis);
	InputComponent->BindAxis("Side", this, &AJugadorMovim::SideAxis);
}

void AJugadorMovim::ForwardAxis(float axis)
{
	FVector movement(0, 0, 0);
	movement.X= axis * velocity * GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(movement, true);
}

void AJugadorMovim::SideAxis(float axis)
{
	FRotator rotate(0, 0, 0);
	rotate.Yaw=axis*rotateVelocity* GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(rotate, true);
}

