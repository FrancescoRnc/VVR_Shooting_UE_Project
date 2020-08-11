// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Templates/SharedPointer.h"
#include "EnemyBall.generated.h"

class AEnemySpawner;

UCLASS()
class VR_SHOOTING_API AEnemyBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealthValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurHealthValue;

	//UPROPERTY()
	//TWeakPtr<> Owner

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//----------------------------------------//
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ScoreValue;

	UFUNCTION(BlueprintCallable)
	void DoAction();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Despawn();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Respawn();
	
	UFUNCTION(BlueprintCallable)
	void Locate(const FVector& vec);

	UFUNCTION(BlueprintCallable)
	void RestoreHealth();
};
