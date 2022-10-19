// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API ADoor : public AActor
{
	GENERATED_BODY()

public:

	float variable;

	ADoor();

	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void OnOverlap(AActor* me, AActor* other);

protected:
	
	virtual void BeginPlay() override;

	

};
