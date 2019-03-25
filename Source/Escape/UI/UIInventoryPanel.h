// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UIPanelBase.h"
#include "UIInventoryPanel.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API UUIInventoryPanel : public UUIPanelBase
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
};
