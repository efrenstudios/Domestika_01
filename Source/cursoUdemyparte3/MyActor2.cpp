// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"
#include "Engine/World.h"

AMyActor2::AMyActor2()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor2::Tick(float DeltaTime)
{
	AddActorLocalOffset(velocity,true);
	AddActorLocalRotation(rotacion,true);
}


