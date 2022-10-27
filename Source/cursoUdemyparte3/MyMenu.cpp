// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMenu.h"
#include "Engine/World.h"


AMyMenu::AMyMenu()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void AMyMenu::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyMenu::Play()
{
	GetWorld()->ServerTravel("nivel2");
}

void AMyMenu::Quit()
{

}


void AMyMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

