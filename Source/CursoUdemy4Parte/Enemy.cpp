// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


AEnemy::AEnemy()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::Damage(float amount, FName boneName)
{
	if (damages.Contains(boneName))
	{
		float damagePercentage = damages[boneName];
		float totalDamage = amount * damagePercentage;
		life -= totalDamage;
		UE_LOG(LogTemp, Warning, TEXT("Total Damage: %f"), totalDamage);

		if (life <= 0)
		{
			Destroy();
		}
	}
}
void AEnemy::Heal(float amount)
{
	life += amount;
	if (life >= maxLife)
	{
		life = maxLife;
	}
}
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

