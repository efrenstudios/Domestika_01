// Fill out your copyright notice in the Description page of Project Settings.


#include "Cargador.h"

// Sets default values
ACargador::ACargador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACargador::BeginPlay()
{
	Super::BeginPlay();

	int balasARecargar = cantidadMaxCargador - cantidadActCargador;
	
	if (balasARecargar>=cantidadParaCargar)
	{
		balasARecargar = cantidadParaCargar;
	}
	cantidadActCargador += cantidadParaCargar;
	cantidadParaCargar -= balasARecargar;
}

// Called every frame
void ACargador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

