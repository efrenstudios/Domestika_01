// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
// Sets default values
AJugador::AJugador()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	InputComponent->BindAxis("Vertical", this, &AJugador::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &AJugador::HorizontalAxis);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AJugador::FirePressed);
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
	GetWorld()->SpawnActor<AActor>(bulletBlueprint, GetActorLocation(), GetActorRotation());
}

