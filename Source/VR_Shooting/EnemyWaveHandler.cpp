// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWaveHandler.h"

// Sets default values
AEnemyWaveHandler::AEnemyWaveHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyWaveHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyWaveHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//
void AEnemyWaveHandler::MakeWave(const FWaveDispositionInfo2 info)
{
	CurrentWaveCount = info.Length;
	float angleDelta = info.MaxDegreeAngle / (info.Length - 1);
	float curAngle = (info.MaxDegreeAngle*.5f) - info.MaxDegreeAngle;
	FVector curLoc = info.StartLocationOffset +
		FVector(info.MaxRadius, 0, 0).RotateAngleAxis(curAngle, {0, 0, 1});
	FRotator curRot(0, curAngle, 0);

	for (int32 i = 0; i < info.Length; i++)
	{
		auto _tmp = ESpawnerRef->SpawnLast_Implementation();
		curLoc = info.StartLocationOffset +
			FVector(info.MaxRadius, 0, 0).RotateAngleAxis(curAngle, {0, 0, 1});
		curRot = {0, curAngle, 0};
		FQuat newQuat = FQuat(curRot);
		curAngle += angleDelta;
		_tmp->SetActorLocationAndRotation(curLoc, newQuat, false, 0, ETeleportType::None);
	}
}

void AEnemyWaveHandler::OnWaveEmpty_Implementation()
{
	
}

void AEnemyWaveHandler::UpdateCurrentWaveStats_Implementation(AEnemyBall* const &ball)
{
	ESpawnerRef->DespawnLast(ball);
	CurrentWaveCount--;
	if (!CurrentWaveCount) OnWaveEmpty();
}