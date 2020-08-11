// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleActor.generated.h"

UCLASS()
class VR_SHOOTING_API ASampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASampleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Chiama la funzione nella blueprint
	// Necessita di implementazione nel .cpp
	UFUNCTION(BlueprintCallable)
	void DoAction_call();

	// Permette di implementare la funzione nella blueprint proprietaria
	// Non devi implementarla nel .cpp
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void DoAction_impl();

	// Permette di implementare la funzione sulle blueprint indipendentemente
	// Se non è stato implementata in alcuna blueprint,
	//   verrà usata la versione con _Implementation scritta su .cpp
	// La versione principale non deve essere implementata in .cpp, l'altra si
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DoActionNat();
	void DoActionNat_Implementation();

	// Funzione const, quindi non puoi influenzare membri del this
	UFUNCTION(BlueprintCallable)
	void DoActionPure() const;

	//
	UFUNCTION(BlueprintCallable, CallInEditor)
	void DoActionEditor(int32 new_val);
};
