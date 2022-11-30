// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDamageble.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIDamageble : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CURSOUDEMY4PARTE_API IIDamageble
{
	GENERATED_BODY()

public:
	virtual void Damage(float amount, FName boneName)=0;
	
};
