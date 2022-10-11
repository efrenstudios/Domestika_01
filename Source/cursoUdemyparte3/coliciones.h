// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "coliciones.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API Acoliciones : public AActor
{
	GENERATED_BODY()


protected:
	
	virtual void BeginPlay() override;

public:	

	Acoliciones();
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	float vida;

	UPROPERTY(EditAnywhere)
	float velocity;

};
