// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VR_SHOOTING_API IDamageableInterface
{
	GENERATED_BODY()

	// Interface used by objects that simulates damage behaviour
	// Used only by objects that gain damage from other objects
	public:

	// Function that decrease health points ecc.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetDamage(float amount);

	// Called when the object has 0 or less health points left
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Die();

	// Function used to query the current health points
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetHealthValue();
};
