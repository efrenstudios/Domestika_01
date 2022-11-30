// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "pared.generated.h"

UCLASS()
class CURSOUDEMY4PARTE_API Apared : public AActor
{
	GENERATED_BODY()
		

protected:
	
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere)
	float danoAbsorver;
	
	virtual void Tick(float DeltaTime) override;

	Apared();
	
};
