// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/CircularQueue.h"
#include "EnemyBall.h"
#include "EnemyContainer.generated.h"

/**
 * 
 */
UCLASS()
class VR_SHOOTING_API UEnemyContainer : public UObject
{
	GENERATED_BODY()

	public:

	// Type of enemies contained here
	UPROPERTY()
	TSubclassOf<AEnemyBall> EnemyType;

	// Queue that contains enemies of one type
	TCircularQueue<AEnemyBall*> EnemyQueue{32};

	// Add new items to the queue given a built array
	UFUNCTION(BlueprintCallable)
	void AddNewItems(TArray<AEnemyBall*> items);

	// Handles the spawn of the dequeued item
	UFUNCTION(BlueprintCallable)
	AEnemyBall* SpawnNewEnemy();

	// handles the despawn of the given enemy, and enqueues it
	UFUNCTION(BlueprintCallable)
	void DespawnLast(AEnemyBall* const &enemy);
};
