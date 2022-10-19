// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrampaMovim.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API ATrampaMovim : public AActor
{
	GENERATED_BODY()

	

protected:
	FTimerHandle timerHandle;

	virtual void BeginPlay() override;

	void ChangerDirection();

public:	
	UPROPERTY(EditAnywhere)
		float damage;

	UPROPERTY(EditAnywhere)
	float velocity;

	UPROPERTY(EditAnywhere)
		float changeTime;
	
	virtual void Tick(float DeltaTime) override;
	
	ATrampaMovim();

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

};
