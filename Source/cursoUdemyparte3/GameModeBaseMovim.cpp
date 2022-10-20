// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBaseMovim.h"
#include "Engine/World.h"

AGameModeBaseMovim::AGameModeBaseMovim()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameModeBaseMovim::Tick(float deltaSeconds)
{
	if (pickedObjetives >= ObjetivesToPick)
	{
		GetWorld()->ServerTravel("nivel2");

	}

}