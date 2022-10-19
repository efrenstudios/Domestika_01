// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include "JugadorMovim.h"




void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADoorKey::OnOverlap);
}




void ADoorKey::OnOverlap(AActor* me, AActor* other)
{
	AJugadorMovim* pb = Cast<AJugadorMovim>(other);
	if (pb != nullptr)
	{
		pb->keys++;
		Destroy();
	}
}