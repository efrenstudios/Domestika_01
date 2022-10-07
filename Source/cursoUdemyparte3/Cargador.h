// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cargador.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API ACargador : public AActor
{
	GENERATED_BODY()
	
private:
	
	

	UPROPERTY(EditAnywhere)
		int cantidadMaxCargador;

	UPROPERTY(EditAnywhere)
		int cantidadActCargador;

	UPROPERTY(EditAnywhere)
		int cantidadParaCargar;

	void Recargar();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	ACargador();

	virtual void Tick(float DeltaTime) override;

};
