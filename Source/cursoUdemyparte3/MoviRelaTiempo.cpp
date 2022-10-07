// Fill out your copyright notice in the Description page of Project Settings.


#include "MoviRelaTiempo.h"
#include "TimerManager.h"
// Sets default values

AMoviRelaTiempo::AMoviRelaTiempo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called every frame
void AMoviRelaTiempo::Tick(float DeltaTime)
{
	
		AddActorLocalOffset(baseVelocity * DeltaTime);	
	    AddActorLocalRotation(baseRotateVelocity * DeltaTime);
		time = time + DeltaTime;
}
	

	//life =life + lifeHealPerSecond * DeltaTime; "no corre y en el tutorial no lo corre tmp para comprobar"


