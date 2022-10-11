// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trampa.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API ATrampa : public AActor
{
	GENERATED_BODY()

private:
	
	UPROPERTY(EditAnywhere)
	float danio;

	UPROPERTY(EditAnywhere)
		float incrementoVelocity;
	
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* Other);
	
public:	
	// Sets default values for this actor's properties
	ATrampa();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
