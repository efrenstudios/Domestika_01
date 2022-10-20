// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBaseMovim.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUDEMYPARTE3_API AGameModeBaseMovim : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AGameModeBaseMovim();

	UPROPERTY(VisibleAnywhere)
		int pickedObjetives;

	UPROPERTY(EditAnywhere)
		int ObjetivesToPick;

	void Tick(float deltaSeconds)override;
};
