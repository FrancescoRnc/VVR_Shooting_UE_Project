// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBall.h"

// Sets default values
AEnemyBall::AEnemyBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScoreValue = 100;
	CurHealthValue = MaxHealthValue;
}

// Called when the game starts or when spawned
void AEnemyBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//----------------------------------------//
void AEnemyBall::DoAction()
{
	UE_LOG(LogTemp, Error, TEXT("Ciao!"));
}

void AEnemyBall::Locate(const FVector& vec)
{
	this->SetActorLocation(vec);
}

void AEnemyBall::RestoreHealth()
{
	CurHealthValue = MaxHealthValue;
}
