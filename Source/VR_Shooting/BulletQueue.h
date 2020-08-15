// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GunBullet.h"
#include "Containers/CircularQueue.h"
#include "Engine.h"
#include "BulletQueue.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VR_SHOOTING_API UBulletQueue : public UObject
{
	GENERATED_BODY()
	
	public:
	
	UPROPERTY(BlueprintReadWrite, Meta=(ExposeOnSpawn="true"))
	TSubclassOf<AGunBullet> BulletsType;

	TCircularQueue<AGunBullet*> Bullets{64};

	// This function initialize the queue given the length 
	UFUNCTION(BlueprintCallable)
	void MakeQueue(const int32 length);

	// This function returns the first object possible from the queue, to be used for Shoot
	UFUNCTION(BlueprintCallable)
	AGunBullet* GetFirstBullet();

	// This function instantiates a new bullet and enqueues it
	UFUNCTION(BlueprintCallable)
	AGunBullet* CreateAndEnqueueNewBullet();

	UFUNCTION(BlueprintCallable)
	void EnqueueBullet(AGunBullet* const bullet);
};
