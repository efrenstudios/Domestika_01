// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"
#include "JugadorMovim.h"

ACheckpoint::ACheckpoint()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverlap);
}


void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckpoint::OnOverlap(AActor* me, AActor* other)
{
	AJugadorMovim* player = Cast<AJugadorMovim>(other);

	if (player != nullptr && player->currentCheckpoint != this)
	{
		player->initialPosition = GetActorLocation();
		player->initialRotate = GetActorRotation();

		if (player->currentCheckpoint != nullptr)
		player->currentCheckpoint->AddActorLocalOffset(FVector(0, 0, 20));

		player->currentCheckpoint = this;
		AddActorLocalOffset(FVector(0, 0, -20));
	}
}