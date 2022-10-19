// Copyright Epic Games, Inc. All Rights Reserved.


#include "cursoUdemyparte3GameModeBase.h"
#include "Engine/World.h"
#include "TimerManager.h"



AcursoUdemyparte3GameModeBase::AcursoUdemyparte3GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AcursoUdemyparte3GameModeBase::Tick(float deltaSeconds)
{
	if (puntajeActual >= puntajeDeseado)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Gane"));
		GetWorld()->ServerTravel("nivel2");
	}
}

void AcursoUdemyparte3GameModeBase::TimerPerder()
{
	GetWorld()->ServerTravel("nivel2");
}

void AcursoUdemyparte3GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(perderTimer, this, &AcursoUdemyparte3GameModeBase::TimerPerder, tiempoPerder, true);
}
