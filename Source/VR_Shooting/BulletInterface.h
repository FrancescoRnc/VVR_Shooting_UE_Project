// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BulletInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UBulletInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VR_SHOOTING_API IBulletInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	// Function called when a Shoot event is triggered
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnOnShoot(FVector const &startLoc, FRotator const &startRot);

	// Function called in order to regenerate stats used to maintain the instance alive
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Regenerate();

	// Event called when the instance runs out of Lifespan
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnEndLifespan();
};
