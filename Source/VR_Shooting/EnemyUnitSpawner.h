// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/CircularQueue.h"
#include "Engine/World.h"
#include "EnemyBall.h"
#include "EnemyUnitSpawner.generated.h"

/**
 * 
 */

class AEnemyManager;

UCLASS()
class VR_SHOOTING_API UEnemyUnitSpawner : public UObject
{
	GENERATED_BODY()
	public:

	// Reference to the Manager that owns this instance
	UPROPERTY()
	AEnemyManager* ManagerRef;

	// Function that instantiates new enemies, given a type and length
	UFUNCTION(BlueprintCallable)
	TArray<AEnemyBall*> Create(TSubclassOf<AEnemyBall> ballType, const int32 amount);
};
