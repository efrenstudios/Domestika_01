// Fill out your copyright notice in the Description page of Project Settings.


#include "destructor.h"
#include "Engine/World.h"
#include "TimerManager.h"




void Adestructor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timer, this, &Adestructor::Timer, 1.0f, true);
}

void Adestructor::Timer()
{
	Destroy();
}


