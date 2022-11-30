// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/IDamageble.h"
#include "Healeable.h"
#include "Enemy.generated.h"

UCLASS()
class CURSOUDEMY4PARTE_API AEnemy : public ACharacter, public IIDamageble, public IHealeable
{
	GENERATED_BODY()



protected:
	
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere) float life=100;
	UPROPERTY(EditAnywhere) float maxLife = 100;
	UPROPERTY(EditAnywhere) TMap<FName, float> damages;

	void Damage(float amount, FName boneName) override;
	void Heal(float amount) override;

	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	AEnemy();
	
};
