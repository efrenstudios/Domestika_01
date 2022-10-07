// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "operacionmat.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API Aoperacionmat : public AActor
{
	GENERATED_BODY()

private:
		UPROPERTY(VisibleAnywhere)
		float time;
		
		UPROPERTY(EditAnywhere)
		FVector baseVelocity;

		UPROPERTY(EditAnywhere)
		float velocityMulti;

		UPROPERTY(EditAnywhere)
		float velocityAdd;

		FTimerHandle timerHandle;

		void Timer();
	
protected:

	virtual void BeginPlay()override;

public:

	Aoperacionmat();
	virtual void Tick(float DeltaTime)override;
};
