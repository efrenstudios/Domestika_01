// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "JugadorMovim.h"




void ADoor::BeginPlay()
{
	Super::BeginPlay();

	variable = 1;
	ADoor::variable = 1;

	OnActorBeginOverlap.AddDynamic(this, &ADoor::OnOverlap);
	
}




ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::OnOverlap(AActor* me, AActor* other)
{
	AJugadorMovim* pb = Cast<AJugadorMovim>(other);

	if (pb != nullptr && pb->keys>0)
	{
		pb->keys--;
		Destroy();
	}
}