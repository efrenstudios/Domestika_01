// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjetiveToPick.h"
#include "JugadorMovim.h"
#include "Engine/World.h"
#include "GameModeBaseMovim.h"

AObjetiveToPick::AObjetiveToPick()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void AObjetiveToPick::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AObjetiveToPick::OnOverlap);
}


void AObjetiveToPick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObjetiveToPick::OnOverlap(AActor* me, AActor* other)
{
	AJugadorMovim* pb = Cast<AJugadorMovim>(other);

	if (pb != nullptr )
	{
		AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();
		AGameModeBaseMovim* gameMode = Cast< AGameModeBaseMovim>(gameModeBase);
		if (gameMode != nullptr)
		{
			gameMode->pickedObjetives++;
			Destroy();
		}
	}
}

