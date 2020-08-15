// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include "EnemyContainer.h"
#include "EnemyBall.h"
//#include "EnemyManager.h"
#include "EnemyWaveGenerator.generated.h"

/**
 * 
 */

// Struct that contains infos for a wave to generate
USTRUCT(BlueprintType)
struct VR_SHOOTING_API FWaveDispositionInfo
{
	GENERATED_USTRUCT_BODY()

	public:

	// How many items you want to spawn and use
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Length;

	// Offset which base the location of every used item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector StartLocationOffset = FVector(0, 0, 50);

	// USED FOR CIRCULAR DISPOSITION
	// how many degrees around the start position
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDegreeAngle = 90.f;

	// The Max distance from the start location
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxRadius = 500.f;
};

class AEnemyManager;
//class UEnemyContainer;

UCLASS()
class VR_SHOOTING_API UEnemyWaveGenerator : public UObject
{
	GENERATED_BODY()
	
	public:

	// Count used to track how many enemies are alive in field
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentWaveCount;

	// Index used to track the current active wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentWaveIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector storageLocation;

	// Reference to the Manager owner
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEnemyManager* ManagerRef;

	// Function used to generate the new wave, 
	// given a container, which it dequeues items, 
	// and a wave info, used to locate items properly
	UFUNCTION(BlueprintCallable)
	void LocateNewWave(UEnemyContainer * enemies, const FWaveDispositionInfo info);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartWaving();

	// Function that updates the current wave's status. 
	UFUNCTION(BlueprintCallable)
	void UpdateCurrentWaveStats(AEnemyBall* const &ball);

	// function called when CurrentWaveCount is 0
	UFUNCTION(BlueprintCallable)
	void OnWaveEmpty();
};
