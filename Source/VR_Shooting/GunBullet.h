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
	AGunBullet();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float DamageValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxCustomLifeSpan;
	UPROPERTY(BlueprintReadWrite)
	float CustomLifeSpan;
	

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	// This function handles the actor's opacity, tick and collision enability
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetNewAvailability(const bool value);

	// BulletInterface functions
	virtual void SpawnOnShoot_Implementation(FVector const &startLoc, FRotator const &startRot);

	virtual void Regenerate_Implementation();

	virtual void OnEndLifespan_Implementation();
};
