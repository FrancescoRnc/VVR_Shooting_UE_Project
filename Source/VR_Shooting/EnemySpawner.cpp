// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(0, 10.f, FColor::Blue, FString::Printf(TEXT("elements in queue: %d"), BallsQueue.Count()));
}

//----------------------------------------//
AEnemyBall* AEnemySpawner::SpawnLast_Implementation()
{
	AEnemyBall* _tmp = nullptr;
	BallsQueue.Dequeue(_tmp);
	_tmp->Respawn();
	return _tmp;
}

void AEnemySpawner::DespawnLast_Implementation(AEnemyBall* const &ball)
{
	ball->Despawn();
	BallsQueue.Enqueue(ball);
}

void AEnemySpawner::CreateBalls(const int32 amount)
{
	FVector _startLoc(0, 0, 0);
	FRotator _startRot(0, 0, 0);
	for (int32 i = 0; i < amount; i++)
	{
		FActorSpawnParameters spawnParams;
		auto ball = GetWorld()->SpawnActor<AEnemyBall>(BallsClass, _startLoc, _startRot, spawnParams);
		ball->Despawn();
		ball->Locate({0, 0, -500.f});
		BallsQueue.Enqueue(ball);
	}
}
