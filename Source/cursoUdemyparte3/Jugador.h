// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Jugador.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API AJugador : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AJugador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(EditAnywhere)
	float Velocity;
	UPROPERTY(EditAnywhere)
	float rotatorVelocity;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> bulletBlueprint;

	virtual void Tick(float DeltaTime) override;
		
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void VerticalAxis(float value);
	void HorizontalAxis(float value);
	void FirePressed();
};
