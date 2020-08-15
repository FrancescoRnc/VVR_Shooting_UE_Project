// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyUnitSpawner.h"
#include "EnemyManager.h"


TArray<AEnemyBall*> UEnemyUnitSpawner::Create(TSubclassOf<AEnemyBall> ballType, const int32 amount)
{
	TArray<AEnemyBall*> balls;

	FVector _startLoc(0, 0, 0);
	FRotator _startRot(0, 0, 0);

	for (int32 i = 0; i < amount; i++)
	{
		if (ManagerRef->GetWorld())
		{

			FActorSpawnParameters spawnParams;
			auto ball = ManagerRef->GetWorld()->SpawnActor<AEnemyBall>(ballType, spawnParams);
			
			ball->Despawn();
			ball->Locate({0, 0, -500.f});
			balls.Push(ball);
		}
	}

	return balls;
}
