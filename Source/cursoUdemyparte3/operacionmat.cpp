// Fill out your copyright notice in the Description page of Project Settings.


#include "operacionmat.h"
#include "TimerManager.h"



void Aoperacionmat::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandle, this, &Aoperacionmat::Timer, 1, true);
}

Aoperacionmat::Aoperacionmat()
{
	time = 0;
	velocityMulti = 1;
	PrimaryActorTick.bCanEverTick = true;
}


void Aoperacionmat::Timer()
{
	time = time + 1;
	velocityMulti = velocityMulti + velocityAdd;
}

void Aoperacionmat::Tick(float DeltaTime)
{
	AddActorLocalOffset(baseVelocity * velocityMulti);	
}

