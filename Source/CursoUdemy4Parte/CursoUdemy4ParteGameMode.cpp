// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CursoUdemy4ParteGameMode.h"
#include "CursoUdemy4ParteCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACursoUdemy4ParteGameMode::ACursoUdemy4ParteGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
