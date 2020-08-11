// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletQueue.h"


void UBulletQueue::MakeQueue(const int32 length)
{
	for (int32 i = 0; i < length; i++)
	{
		//FActorSpawnParameters spawnParams;
		//auto bullet = GetWorld()->SpawnActor<AGunBullet>(BulletsType, {0, 0, 0}, {0, 0, 0}, spawnParams);
		//EnqueueBullet(bullet);
		CreateAndEnqueueNewBullet();
	}
}

AGunBullet* UBulletQueue::GetFirstBullet()
{
	AGunBullet* bullet;
	if (Bullets.Count() < 1)
	{
		CreateAndEnqueueNewBullet();
	}
	Bullets.Dequeue(bullet);

	//UE_LOG(LogTemp, Warning, TEXT("Dequeue. Stock: %d"), Bullets.Count());

	return bullet;
}

AGunBullet* UBulletQueue::CreateAndEnqueueNewBullet()
{
	FActorSpawnParameters spawnParams;
	auto bullet = GetWorld()->SpawnActor<AGunBullet>
		(BulletsType, {0, 0, 0}, {0, 0, 0}, spawnParams);
	bullet->SetNewAvailability(false);
	EnqueueBullet(bullet);
	return bullet;
}

void UBulletQueue::EnqueueBullet(AGunBullet* const bullet)
{
	bullet->SetNewAvailability(false);
	Bullets.Enqueue(bullet);
	//UE_LOG(LogTemp, Warning, TEXT("Enqueue. Stock: %d"), Bullets.Count());
}