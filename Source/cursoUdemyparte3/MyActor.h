// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API AMyActor : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay()override;

public:	
	
	FTimerHandle timerRotateHandle;
	FTimerHandle timerStopRotateHandle;

	FTimerHandle timerShootHandle;
	FTimerHandle timerStopShootHandle;



	UPROPERTY(EditAnywhere)
	float tiempoPararRotate;
	UPROPERTY(EditAnywhere)
	float tiempoEntreRotate;
	UPROPERTY(EditAnywhere)
	FRotator velocidadRotate;

	UPROPERTY(EditAnywhere)
	float tiempoEntreDisparo;
	UPROPERTY(EditAnywhere)
	float tiempoPararDisparo;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor>objetoASpawnear;

	
	void Shoot();
	void StopShoot();

	void Rotate();
	void StopRotate();

};
