// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CmpUpDownInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCmpUpDownInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VR_SHOOTING_API ICmpUpDownInterface
{
	GENERATED_BODY()

	// Interface used to move the actor how you want
	public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Move();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Stop();
};
