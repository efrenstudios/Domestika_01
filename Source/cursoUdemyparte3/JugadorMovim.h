// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "JugadorMovim.generated.h"


UCLASS()
class CURSOUDEMYPARTE3_API AJugadorMovim : public APawn
{
	GENERATED_BODY()


protected:
	
	virtual void BeginPlay() override;

public:	
	
	FVector initialPosition;

	
	FRotator initialRotate;

	
	float initialLife;

	
	int keys;
	
	UPROPERTY(EditAnywhere)
	int respawns;

	UPROPERTY(EditAnywhere)
	float life;

	UPROPERTY(EditAnywhere)
	float velocity;

	UPROPERTY(EditAnywhere)
	float rotateVelocity;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void ForwardAxis(float axis);
	void SideAxis(float axis);
	
	AJugadorMovim();
};
