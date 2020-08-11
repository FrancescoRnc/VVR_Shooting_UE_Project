// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemySpawnerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemySpawnerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VR_SHOOTING_API IEnemySpawnerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnSelected(const int32 index);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DespawnSelected(const int32 index);

};
