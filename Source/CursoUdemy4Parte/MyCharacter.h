// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class CURSOUDEMY4PARTE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	void BeginPlay() override;

private:

	void MoveForward(float value);
	void MoveRight(float value);
	void RotateYaw(float value);
	void RotatePich(float value);
	void StartJump();
	void StopJump();
	void StartShoot();
	void ShootTimer();
	void StopShoot();

	void StartShoot2();
	void ShootTimer2();
	void StopShoot2();

	void Shoot(int amount, float shake);

	void Heal();

public:	
	
	FTimerHandle shootTimer;
	FTimerHandle shootTimer2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)class UCameraComponent* cam;
	UPROPERTY(VisibleAnywhere)class USkeletalMeshComponent* arms;
	UPROPERTY(VisibleAnywhere)class USkeletalMeshComponent* weapon;
	UPROPERTY(EditAnywhere)float rotationSpeed = 45;
	UPROPERTY(EditAnywhere)float baseDamage = 100;
	UPROPERTY(EditAnywhere)float healAmount = 30;

	void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	AMyCharacter();
};
