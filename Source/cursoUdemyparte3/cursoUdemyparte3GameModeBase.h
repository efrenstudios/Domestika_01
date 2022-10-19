// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "cursoUdemyparte3GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUDEMYPARTE3_API AcursoUdemyparte3GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

	void BeginPlay() override;

public:

	FTimerHandle perderTimer;

		UPROPERTY(VisibleAnywhere)
		int puntajeActual;

	    UPROPERTY(EditAnywhere)
		int puntajeDeseado;

		UPROPERTY(EditAnywhere)
		float tiempoPerder;

		AcursoUdemyparte3GameModeBase();

		void Tick(float deltaSeconds) override;

		void TimerPerder();
};
