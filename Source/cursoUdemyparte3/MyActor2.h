// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float numero;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float vida;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float tiempoEntreBalas;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int cantidadBalas;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator rotacion;
	



public:
	AMyActor2();
	virtual void Tick(float DeltaTime)override;
};
