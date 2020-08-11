// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBall.h"
#include "Engine/World.h"
#include "Containers/Queue.h"
#include "Containers/CircularQueue.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Engine.h"
#include "EnemySpawner.generated.h"

USTRUCT(BlueprintType)
struct VR_SHOOTING_API FWaveDispositionInfo
{
	GENERATED_USTRUCT_BODY()
	
	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Length;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector StartLocationOffset = FVector(0, 0, 50);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDegreeAngle = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxRadius = 500.f;

	//FWaveDispositionInfo();
};

UCLASS()
class VR_SHOOTING_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(EditDefaultsOnly, Category = "Edit")
	TSubclassOf<AActor> BallsClass;

	TCircularQueue<AEnemyBall*> BallsQueue{10};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//----------------------------------------//
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	AEnemyBall* SpawnLast();
	AEnemyBall* SpawnLast_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DespawnLast(AEnemyBall* const &ball);
	void DespawnLast_Implementation(AEnemyBall* const &ball);

	UFUNCTION(BlueprintCallable)
	void CreateBalls(const int32 amount);
};
