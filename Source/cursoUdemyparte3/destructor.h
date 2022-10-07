// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "destructor.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API Adestructor : public AActor
{
	GENERATED_BODY()
	



protected:

	virtual void BeginPlay() override;


public:


	FTimerHandle timer;


	void Timer();



};
