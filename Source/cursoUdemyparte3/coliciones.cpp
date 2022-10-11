// Fill out your copyright notice in the Description page of Project Settings.


#include "coliciones.h"

// Sets default values
Acoliciones::Acoliciones()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void Acoliciones::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acoliciones::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(velocity, 0, 0), true);

	if (vida<=0)
	{
		Destroy();
	}
}

