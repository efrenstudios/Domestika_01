// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMenu.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API AMyMenu : public AActor
{
	GENERATED_BODY()
	
protected:
	
	virtual void BeginPlay() override;

public:	
	
	UFUNCTION(BlueprintCallable)
		void Play();

	UFUNCTION(BlueprintCallable)
		void Quit();

	virtual void Tick(float DeltaTime) override;

	AMyMenu();
};
