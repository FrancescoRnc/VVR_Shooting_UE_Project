// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBullet.h"

// Sets default values
AGunBullet::AGunBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageValue = 50.f;
	Speed = 1200.f;
	MaxCustomLifeSpan = 3.f;
	CustomLifeSpan = MaxCustomLifeSpan;
}

// Called when the game starts or when spawned
void AGunBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Functions

// BulletInterface
void AGunBullet::SpawnOnShoot_Implementation(FVector const &startLoc, FRotator const &startRot)
{
	SetActorLocationAndRotation(startLoc, startRot);
}

void AGunBullet::Regenerate_Implementation()
{
	CustomLifeSpan = MaxCustomLifeSpan;
}

void AGunBullet::OnEndLifespan_Implementation()
{

}