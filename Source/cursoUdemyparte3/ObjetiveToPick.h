// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjetiveToPick.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API AObjetiveToPick : public AActor
{
	GENERATED_BODY()
	

private:
	
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	AObjetiveToPick();
};
