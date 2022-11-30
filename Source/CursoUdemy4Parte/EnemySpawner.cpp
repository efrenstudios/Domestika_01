// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "Engine/World.h"


AEnemySpawner::AEnemySpawner()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0;i < amount;i++)
	{

	int spawnPointIndex = FMath::RandRange(0, spawnPoints.Num() - 1);
	int blueprintIndex = FMath::RandRange(0, blueprintsToSpawn.Num() - 1);

	if (spawnPointIndex >= spawnPoints.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("No hay Spawn Points en el Spawer"));
		return;
	}
	if (blueprintIndex >= blueprintsToSpawn.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("No hay Blueprints Points en el Spawer"));
		return;
	}

	AActor* spawnPoint = spawnPoints[spawnPointIndex];
	TSubclassOf<AActor> blueprintToSpawn = blueprintsToSpawn[blueprintIndex];
	GetWorld()->SpawnActor<AActor>(blueprintToSpawn.Get(), spawnPoint->GetTransform());
	}
	
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

