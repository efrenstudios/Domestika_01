// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HandsAnimationsCpp.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUDEMY4PARTE_API UHandsAnimationsCpp : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float speed;

	void NativeUpdateAnimation(float delta)override;
	
	
};
