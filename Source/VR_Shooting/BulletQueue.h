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

	//UPROPERTY()
	TCircularQueue<AGunBullet*> Bullets{64};

	UFUNCTION(BlueprintCallable)
	void MakeQueue(const int32 length);

	UFUNCTION(BlueprintCallable)
	AGunBullet* GetFirstBullet();

	UFUNCTION(BlueprintCallable)
	AGunBullet* CreateAndEnqueueNewBullet();

	UFUNCTION(BlueprintCallable)
	void EnqueueBullet(AGunBullet* const bullet);
};
