// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBall.h"

// Sets default values
AEnemyBall::AEnemyBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Type = EEnemyType::TOTAL;
	ScoreValue = 100;
	CurHealthValue = MaxHealthValue;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	
}


// Called when the game starts or when spawned
void AEnemyBall::BeginPlay()
{
	Super::BeginPlay();
	
	// Creating and setting Material Instance, given an asset from Blueprint
	
	Material = UMaterialInstanceDynamic::Create(MatInterface, this, TEXT("Material"));
	MeshComponent->SetStaticMesh(Mesh);
	MeshComponent->SetMaterial(0, Material);
}

// Called every frame
void AEnemyBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//----------------------------------------//
void AEnemyBall::DoAction()
{
	//UE_LOG(LogTemp, Error, TEXT("Ciao!"));
}

void AEnemyBall::Locate(const FVector& vec)
{
	this->SetActorLocation(vec);
}

void AEnemyBall::RestoreHealth()
{
	CurHealthValue = MaxHealthValue;
}

