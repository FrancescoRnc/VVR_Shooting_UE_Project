// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiInputPlayerController.h"

void AMultiInputPlayerController::BeginPlay()
{
	Super::BeginPlay();

	MakeMap();
}

void AMultiInputPlayerController::MakeMap()
{
	for (uint8 i = 0; i < (uint8)EInputButtonType::TOTAL; i++)
	{
		InputMap.Add(NewObject<UInputContainerDispatcher>());
		InputMap[i]->PushFunction({});
	}
}

// Push / Pop
void AMultiInputPlayerController::PushNewFunction(const EInputButtonType type, const FFuncParam binder)
{
	auto container = InputMap[(uint8)type];
	container->PushFunction(binder);
	container->BindLastFunction();
}

void AMultiInputPlayerController::PushNullFunction(const EInputButtonType type)
{
	auto container = InputMap[(uint8)type];
	container->PushEmptyFunction();
	container->UnbindFunction();
}

FFuncParam AMultiInputPlayerController::PopLastFunction(const EInputButtonType type)
{
	auto container = InputMap[(uint8)type];
	auto func = container->PopFunction();
	container->BindLastFunction();
	return func;
}

// Binding
void AMultiInputPlayerController::BindLastFunction(const EInputButtonType type)
{
	auto container = InputMap[(uint8)type];
	container->BindLastFunction();	
}

void AMultiInputPlayerController::UnbindFunction(const EInputButtonType type)
{
	auto container = InputMap[(uint8)type];
	container->UnbindFunction();
}

// Execution
void AMultiInputPlayerController::Execute(const EInputButtonType type)
{
	auto container = InputMap[(uint8)type];
	container->Execute();
}

// Exclusion
void AMultiInputPlayerController::SetExclusion(const TSet< EInputButtonType> map)
{
	ButtonExclusionMap = map;
}

void AMultiInputPlayerController::AddExclusion(const TSet< EInputButtonType> map)
{
	for (auto item : map)
		ButtonExclusionMap.Add(item);
}

void AMultiInputPlayerController::ShrinkExclusion(const TSet< EInputButtonType> map)
{
	for (auto item : map)
		ButtonExclusionMap.Remove(item);
}

void AMultiInputPlayerController::ResetExclusion()
{
	int32 tmp = ButtonExclusionMap.Num();
	ButtonExclusionMap.Empty(tmp);
}

void AMultiInputPlayerController::UpdateMapAvaliability()
{
	for (uint8 i = 0; i < (uint8)EInputButtonType::TOTAL; i++)
	{
		if (ButtonExclusionMap.Contains((EInputButtonType)i))
			InputMap[i]->DisableBinding();
		else InputMap[i]->AbleBinding();
	}
}