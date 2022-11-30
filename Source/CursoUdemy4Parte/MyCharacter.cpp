// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Interfaces/IDamageble.h"
#include "Healeable.h"
#include "TimerManager.h"
#include "Enemy.h"
#include "pared.h"


AMyCharacter::AMyCharacter()
{
	cam = CreateDefaultSubobject<UCameraComponent>("Cam");
	cam->bUsePawnControlRotation = true;
	cam->SetupAttachment(GetRootComponent());

	arms = CreateDefaultSubobject<USkeletalMeshComponent>("Arms");
	arms->SetupAttachment(cam);

	weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	weapon->SetupAttachment(arms, "GripPoint");
	
}


void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::RotateYaw);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::RotatePich);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::StartShoot);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AMyCharacter::StopShoot);
	PlayerInputComponent->BindAction("Fire2", IE_Pressed, this, &AMyCharacter::StartShoot2);
	PlayerInputComponent->BindAction("Fire2", IE_Released, this, &AMyCharacter::StopShoot2);
}



void AMyCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AMyCharacter::RotateYaw(float value)
{
	AddControllerYawInput(value * rotationSpeed*GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::RotatePich(float value)
{
	AddControllerPitchInput(value * rotationSpeed * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::StartJump()
{
	Jump();
}

void AMyCharacter::StopJump()
{
	StopJumping();
}

void AMyCharacter::StartShoot()
{
	GetWorldTimerManager().SetTimer(shootTimer, this, &AMyCharacter::ShootTimer, 0.267, true);
}

void AMyCharacter::ShootTimer()
{
	Shoot(1,0);
}

void AMyCharacter::StopShoot()
{
	GetWorldTimerManager().ClearTimer(shootTimer);
}

void AMyCharacter::StartShoot2()
{
	GetWorldTimerManager().SetTimer(shootTimer2, this, &AMyCharacter::ShootTimer2, 0.267, true);
}

void AMyCharacter::ShootTimer2()
{
	//Shoot(10, 1000);
	Heal();
}

void AMyCharacter::StopShoot2()
{
	GetWorldTimerManager().ClearTimer(shootTimer2);
}

void AMyCharacter::Shoot(int amount, float shake)
{
	for (int i=0;i<amount;i++)
	{

	TArray<FHitResult> hits;
	float currentDamage = baseDamage;

	FVector shakeVector;
	shakeVector.X = FMath::RandRange(-shake, shake);
	shakeVector.Y = FMath::RandRange(-shake, shake);
	shakeVector.Z = FMath::RandRange(-shake, shake);

	GetWorld()->LineTraceMultiByChannel(
		hits,
		cam->GetComponentLocation(),
		cam->GetComponentLocation() + cam->GetForwardVector() * 10000+ shakeVector,
		ECC_GameTraceChannel3);

	DrawDebugLine(
		GetWorld(),
		cam->GetComponentLocation(),
		cam->GetComponentLocation() + cam->GetForwardVector() * 10000+ shakeVector,
		FColor::Blue,
		false,
		3);

	TArray<AActor*> hittedActors;

	for (int i = 0; i < hits.Num();i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("LOOP"));
		FHitResult hitInfo = hits[i];

		if (hitInfo.GetActor() && !hittedActors.Contains(hitInfo.GetActor()))
		{
			hittedActors.Add(hitInfo.GetActor());
			UE_LOG(LogTemp, Warning, TEXT("Damage Hit"));

			IIDamageble* damageble = Cast<IIDamageble>(hitInfo.GetActor());
			if (damageble)
			{
				damageble->Damage(currentDamage, hitInfo.BoneName);
			}

			Apared* pared = Cast<Apared>(hitInfo.GetActor());
			if (pared)
			{
				currentDamage -= pared->danoAbsorver;
			}
		}
		}
	}
}

void AMyCharacter::Heal()
{
	FHitResult hitInfo;

		GetWorld()->LineTraceSingleByChannel(
			hitInfo,
			cam->GetComponentLocation(),
			cam->GetComponentLocation() + cam->GetForwardVector() * 10000,
			ECC_GameTraceChannel3);

		DrawDebugLine(
			GetWorld(),
			cam->GetComponentLocation(),
			cam->GetComponentLocation() + cam->GetForwardVector() * 10000,
			FColor::Red,
			false,
			3);

	

			if (hitInfo.GetActor())
			{
				UE_LOG(LogTemp, Warning, TEXT("Heal Hit"));

				IHealeable* heleable = Cast<IHealeable>(hitInfo.GetActor());
				if (heleable)
				{
					heleable->Heal(healAmount);
				}

			}
}


