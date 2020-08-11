// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputContainerDispatcher.h"
#include "MultiInputPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class VR_SHOOTING_API AMultiInputPlayerController : public APlayerController
{
	GENERATED_BODY()

	protected:

	// BeginPlay
	virtual void BeginPlay() override;
	
	public:

// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UInputContainerDispatcher*> InputMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<EInputButtonType> ButtonExclusionMap;

// Functions
	UFUNCTION(BlueprintCallable)
	void MakeMap();

	// Push / Pop
	UFUNCTION(BlueprintCallable)
	void PushNewFunction(const EInputButtonType type, const FFuncParam binder);

	UFUNCTION(BlueprintCallable)
	void PushNullFunction(const EInputButtonType type);

	UFUNCTION(BlueprintCallable)
	FFuncParam PopLastFunction(const EInputButtonType type);

	// Binding
	UFUNCTION(BlueprintCallable)
	void BindLastFunction(const EInputButtonType type);

	UFUNCTION(BlueprintCallable)
	void UnbindFunction(const EInputButtonType type);

	// Execution
	UFUNCTION(BlueprintCallable)
	void Execute(const EInputButtonType type);

	// Exclusion
	UFUNCTION(BlueprintCallable)
	void SetExclusion(const TSet< EInputButtonType> map);

	UFUNCTION(BlueprintCallable)
	void AddExclusion(const TSet< EInputButtonType> map);

	UFUNCTION(BlueprintCallable)
	void ShrinkExclusion(const TSet< EInputButtonType> map);

	UFUNCTION(BlueprintCallable)
	void ResetExclusion();

	UFUNCTION(BlueprintCallable)
	void UpdateMapAvaliability();
};
