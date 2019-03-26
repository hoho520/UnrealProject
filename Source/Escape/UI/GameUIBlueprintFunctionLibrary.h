// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameUIBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
enum class ESlateVisibility : uint8;

UCLASS(meta = (ScriptName = "GameUILibrary"))
class ESCAPE_API UGameUIBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// 인벤토리 패널 가시성 설정
	UFUNCTION(BlueprintCallable, Category = "-Escape|Game UI")
	static void SetInventoryPanelVisibility(ESlateVisibility InVisibility);

};
