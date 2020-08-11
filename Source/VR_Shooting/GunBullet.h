// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletInterface.h"
#include "GunBullet.generated.h"

UCLASS()
class VR_SHOOTING_API AGunBullet : public AActor, public IBulletInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunBullet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxCustomLifeSpan;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CustomLifeSpan;

	//UPROPERTY(BlueprintReadOnly)
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Functions
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetNewAvailability(const bool value);

	// BulletInterface
	virtual void SpawnOnShoot_Implementation(FVector const &startLoc, FRotator const &startRot);

	virtual void Regenerate_Implementation();

	virtual void OnEndLifespan_Implementation();
};
