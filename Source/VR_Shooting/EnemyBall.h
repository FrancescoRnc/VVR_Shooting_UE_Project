// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Templates/SharedPointer.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyBall.generated.h"

class AEnemySpawner;

UCLASS()
class VR_SHOOTING_API AEnemyBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//----------------------------------------//
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* Material;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* MatInterface;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealthValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurHealthValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ScoreValue;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//TWeakPtr<> Owner;

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
