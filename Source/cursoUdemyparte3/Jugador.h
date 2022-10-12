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
	
	AJugador();

protected:
	
	virtual void BeginPlay() override;

public:	
	FTimerHandle fireTimer;

	bool forwardPressed;

	UPROPERTY(EditAnywhere)
	float fireRate;

	UPROPERTY(EditAnywhere)
	float Velocity;
	UPROPERTY(EditAnywhere)
	float rotatorVelocity;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> bulletBlueprint;

	virtual void Tick(float deltaSeconds) override;
		
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void VerticalAxis(float value);
	void HorizontalAxis(float value);
	void FirePressed();
	void FireReleased();
	void Fire();
	void ForwardPressed();
	void ForwardReleased();


};
