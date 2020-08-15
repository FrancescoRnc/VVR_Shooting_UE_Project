// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Templates/SharedPointer.h"
//#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyBall.generated.h"

class UEnemyContainer;

UENUM(Blueprintable)
enum class EEnemyType : uint8
{
	Base = 0 UMETA(DisplayName = "Base"),
	Bad = 1 UMETA(DisplayName = "Bad"),
	Quick = 2 UMETA(DisplayName = "Quick"),
	Boss = 3 UMETA(DisplayName = "Boss"),
	TOTAL = 4 UMETA(DisplayName = "None - Do not Use!")
};

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

	// Mesh assigned from blueprint defaults
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Edit")
	UStaticMesh* Mesh;

	UPROPERTY(BlueprintReadWrite)
	UMaterialInstanceDynamic* Material;

	// Used to determine the right material, assigned from blueprint defaults
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Edit")
	UMaterialInterface* MatInterface;

	// Enemy type, assigned from blueprint defaults
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Edit")
	EEnemyType Type;

	// Max amount of health points, assigned from blueprint defaults
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Edit")
	float MaxHealthValue;
	UPROPERTY(BlueprintReadWrite)
	float CurHealthValue;

	// Local score value for the Score System (future use), assigned from blueprint defaults
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Edit")
	int32 ScoreValue;

	// Reference to the native container
	UPROPERTY(BlueprintReadOnly)
	UEnemyContainer* ManagerOwner;
	

	UFUNCTION(BlueprintCallable)
	void DoAction();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Despawn();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Respawn();
	
	// Used to set actor location
	UFUNCTION(BlueprintCallable)
	void Locate(const FVector& vec);

	UFUNCTION(BlueprintCallable)
	void RestoreHealth();
};
