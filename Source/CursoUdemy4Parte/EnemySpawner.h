// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class CURSOUDEMY4PARTE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	

protected:
	
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	int amount=1;

	UPROPERTY(EditAnywhere)
	TArray<AActor*>spawnPoints;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>>blueprintsToSpawn;

	virtual void Tick(float DeltaTime) override;
		
	AEnemySpawner();
};
