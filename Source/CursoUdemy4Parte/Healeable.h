// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Healeable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHealeable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CURSOUDEMY4PARTE_API IHealeable
{
	GENERATED_BODY()

	
public:
	virtual void Heal(float amount) = 0;
	
};
