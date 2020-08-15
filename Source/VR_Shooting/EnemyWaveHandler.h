// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.h"
//#include "EnemyContainer.h"
#include "EnemyManager.h"
#include "EnemyWaveHandler.generated.h"

UCLASS()
class VR_SHOOTING_API AEnemyWaveHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyWaveHandler();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEnemySpawner* ESpawnerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentWaveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentWaveIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector storageLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void MakeWave(const FWaveDispositionInfo2 info);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartWaving();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateCurrentWaveStats(AEnemyBall* const &ball);
	void UpdateCurrentWaveStats_Implementation(AEnemyBall* const &ball);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnWaveEmpty();
	void OnWaveEmpty_Implementation();
};
