// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyBall.h"
#include "InputContainerDispatcher.generated.h"

/**
 * 
 */

UENUM(Blueprintable)
enum class EInputButtonType : uint8
{
	// Here you can add buttons you use for gameplay mechanics
	TriggerRight = 0 UMETA(DisplayName = "Trigger Right"),
	TriggerLeft = 1 UMETA(DisplayName = "Trigger Left"),
	ShoulderRight = 2 UMETA(DisplayName = "Shoulder Right"),
	ShoulderLeft = 3 UMETA(DisplayName = "Shoulder Left"),
	TOTAL = 4 UMETA(DisplayName = "None - Do not Use!")
};

DECLARE_DYNAMIC_DELEGATE(FFuncParam);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAxisAction, float, AxisValue);

//This UObject contains a stack of functions/delegates,
// but ONLY the LAST function (with push) will be called.
// There's even a custom behaviour for dis/enable the execution of the current function

UCLASS(Blueprintable)
class VR_SHOOTING_API UInputContainerDispatcher : public UObject
{
	GENERATED_BODY()
	
	protected:

	UPROPERTY()
	FFuncParam inputPress;

	//UPROPERTY()
	//FAxisAction axisPress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAllowBind = true;


	public:
// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(ExposeOnSpawn="true"))
	EInputButtonType Type;

	// Stack that contains functions/delegates to be called
	UPROPERTY(BlueprintReadOnly)
	TArray<FFuncParam> FunctionStack;

// Functions
	// Push / Pop
	UFUNCTION(BlueprintCallable)
	void PushFunction(const FFuncParam binder);

	UFUNCTION(BlueprintCallable)
	FFuncParam PopFunction();

	// This pushes an empty function to the stack
	UFUNCTION(BlueprintCallable)
	void PushEmptyFunction();

	// Binding
	UFUNCTION(BlueprintCallable)
	void BindLastFunction();

	UFUNCTION(BlueprintCallable)
	void UnbindFunction();

	UFUNCTION(BlueprintCallable)
	void AbleBinding();

	UFUNCTION(BlueprintCallable)
	void DisableBinding();

	// Execution
	UFUNCTION(BlueprintCallable)
	void Execute();
};
