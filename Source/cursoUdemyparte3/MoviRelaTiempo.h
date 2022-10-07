// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoviRelaTiempo.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API AMoviRelaTiempo : public AActor
{
	GENERATED_BODY()

private:
	
	
	UPROPERTY(EditAnywhere)
	FVector baseVelocity;

	UPROPERTY(EditAnywhere)
	FRotator baseRotateVelocity;

	UPROPERTY(VisibleAnywhere)
	float time;
	
	UPROPERTY(VisibleAnywhere)
	float life;

	UPROPERTY(VisibleAnywhere)
	float lifeHealPerSecond;

public:	
	
	AMoviRelaTiempo();

	virtual void Tick(float DeltaTime) override;

};
