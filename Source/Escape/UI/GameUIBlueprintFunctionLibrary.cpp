// Fill out your copyright notice in the Description page of Project Settings.

#include "GameUIBlueprintFunctionLibrary.h"
#include "EscapeHUD.h"

void UGameUIBlueprintFunctionLibrary::SetInventoryPanelVisibility(ESlateVisibility InVisibility)
{
	AEscapeHUD::SetInventoryPanelVisibility(InVisibility);
}
