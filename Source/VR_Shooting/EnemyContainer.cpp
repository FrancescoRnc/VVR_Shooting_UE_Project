// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyContainer.h"


void UEnemyContainer::AddNewItems(TArray<AEnemyBall*> items)
{
	for (int32 i = 0; i < items.Num(); i++)
	{
		auto tmp = MoveTemp(items[i]);
		tmp->ManagerOwner = this;
		EnemyQueue.Enqueue(MoveTemp(tmp));
		
	}

}

AEnemyBall* UEnemyContainer::SpawnNewEnemy()
{
	AEnemyBall* enemy = nullptr;
	EnemyQueue.Dequeue(enemy);
	enemy->Respawn();
	return enemy;
}

void UEnemyContainer::DespawnLast(AEnemyBall* const &enemy)
{
	enemy->Despawn();
	EnemyQueue.Enqueue(enemy);
}