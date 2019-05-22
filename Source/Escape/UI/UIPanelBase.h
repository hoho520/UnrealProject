// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIPanelBase.generated.h"

/**
 * 
 */
UENUM()
enum class E_PanelLayer : uint8
{
	HUD = 0,
	Basic,
	Death,
	Popup,
	System,
};

UCLASS()
class ESCAPE_API UUIPanelBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FORCEINLINE E_PanelLayer GetPanelLayer() const { return PanelLayer; }

protected:
	E_PanelLayer PanelLayer;
};
