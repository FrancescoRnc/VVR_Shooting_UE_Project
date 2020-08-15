// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Templates/SharedPointer.h"
#include "EnemyUnitSpawner.h"
#include "EnemyWaveGenerator.h"
#include "EnemyContainer.h"
#include "EnemyManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDoAfterWaveEmpty);

UCLASS()
class VR_SHOOTING_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemyManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//----------------------------------------------------------------//

	// Reference to the Spawner, in order to instantiate enemies to add in the map
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEnemyUnitSpawner* Spawner;

	// Reference to the Wave Generator, that handles the wave system
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEnemyWaveGenerator* WaveGenerator;

	// Map that contains every Enemy instantiated, listed for each type
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EEnemyType, UEnemyContainer*> EnemyMap;
	
	// List that contains infos about the wave stream. 
	// Values should be assigned from Blueprint Defaults
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWaveDispositionInfo> PreparedWaves;

	// Delegates that calls binded functions after a wave is emptied
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable)
	FOnDoAfterWaveEmpty DoAfterWaveEmptyEvent;

	// Function that just prints on console some important infos, like containers status ecc.
	UFUNCTION(BlueprintCallable)
	void PrintInfo();
};
