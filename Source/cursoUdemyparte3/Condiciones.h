// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Condiciones.generated.h"

UCLASS()
class CURSOUDEMYPARTE3_API ACondiciones : public AActor
{
	GENERATED_BODY()



private:

	FTimerHandle timerHandle;

	UPROPERTY(EditAnywhere)
		int cantidadMaxDisparos;

	UPROPERTY(VisibleAnywhere)
		int cantidadDisparos;

	UPROPERTY(EditAnywhere)
		float vida;

	UPROPERTY(EditAnywhere)
		float tiempoDisparos;
	
	UPROPERTY(EditAnywhere)
		float danoPorSegundo;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor>blueprintBala;

	void Disparar();
	

protected:
	virtual void BeginPlay()override;

public:	
	
	ACondiciones();
    virtual void Tick(float DeltaTime) override;

};
