// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Spawner = NewObject<UEnemyUnitSpawner>();
	WaveGenerator = NewObject<UEnemyWaveGenerator>();
}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	
	Spawner = NewObject<UEnemyUnitSpawner>();
	Spawner->ManagerRef = this;
	WaveGenerator = NewObject<UEnemyWaveGenerator>();
	WaveGenerator->ManagerRef = this;

	EnemyMap.Add(EEnemyType::Base, NewObject<UEnemyContainer>(this));
	EnemyMap.Add(EEnemyType::Bad, NewObject<UEnemyContainer>(this));
	
	Super::BeginPlay();
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemyManager::PrintInfo()
{
	UE_LOG(LogTemp, Warning, TEXT("Base Enemies in stock: %d"), EnemyMap[EEnemyType::Base]->EnemyQueue.Count());
	UE_LOG(LogTemp, Warning, TEXT("Bad Enemies in stock: %d"), EnemyMap[EEnemyType::Bad]->EnemyQueue.Count());
}