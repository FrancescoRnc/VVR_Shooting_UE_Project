// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWaveGenerator.h"
#include "EnemyManager.h"

void UEnemyWaveGenerator::LocateNewWave(UEnemyContainer * enemies, const FWaveDispositionInfo info)
{
	CurrentWaveCount = info.Length;
	float angleDelta = info.MaxDegreeAngle / (info.Length - 1);
	float curAngle = (info.MaxDegreeAngle*.5f) - info.MaxDegreeAngle;
	FVector curLoc = info.StartLocationOffset +
		FVector(info.MaxRadius, 0, 0).RotateAngleAxis(curAngle, {0, 0, 1});
	FRotator curRot(0, curAngle, 0);

	for (int32 i = 0; i < info.Length; i++)
	{
		AEnemyBall* _tmp = enemies->SpawnNewEnemy();

		curLoc = info.StartLocationOffset +
			FVector(info.MaxRadius, 0, 0).RotateAngleAxis(curAngle, {0, 0, 1});
		curRot = {0, curAngle, 0};
		FQuat newQuat = FQuat(curRot);
		curAngle += angleDelta;

		_tmp->SetActorLocationAndRotation(curLoc, newQuat, false, 0, ETeleportType::None);
	}

	ManagerRef->PrintInfo();
}

void UEnemyWaveGenerator::OnWaveEmpty()
{
	CurrentWaveIndex++;
	if (CurrentWaveIndex < ManagerRef->PreparedWaves.Num())
		ManagerRef->DoAfterWaveEmptyEvent.Broadcast();
}

void UEnemyWaveGenerator::UpdateCurrentWaveStats(AEnemyBall* const &ball)
{
	ManagerRef->EnemyMap[ball->Type]->DespawnLast(ball);
	CurrentWaveCount--;	
	if (!CurrentWaveCount) OnWaveEmpty();

	ManagerRef->PrintInfo();
}