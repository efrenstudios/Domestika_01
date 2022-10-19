// Fill out your copyright notice in the Description page of Project Settings.


#include "TrampaMovim.h"
#include "TimerManager.h"
#include "JugadorMovim.h"

ATrampaMovim::ATrampaMovim()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATrampaMovim::OnOverlap(AActor* me, AActor* other)
{
	AJugadorMovim* pb = Cast<AJugadorMovim>(other);
	if (pb != nullptr)
	{
		pb->life -= damage;
	}
}


void ATrampaMovim::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandle, this, &ATrampaMovim::ChangerDirection, changeTime, true);
	OnActorBeginOverlap.AddDynamic(this, &ATrampaMovim::OnOverlap);
}

void ATrampaMovim::ChangerDirection()
{
	velocity *= -1;
}


void ATrampaMovim::Tick(float DeltaTime)
{
	FVector movement(0, 0, 0);
	movement.Z = velocity * DeltaTime;
	AddActorLocalOffset(movement, true);
	
}

