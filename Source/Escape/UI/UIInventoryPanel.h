// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UIPanelBase.h"
#include "UIInventoryPanel.generated.h"

/**
 인벤토리 패널
 */
class UUIInventoryBox;
UCLASS()
class ESCAPE_API UUIInventoryPanel : public UUIPanelBase
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	void PanelClose();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUIInventoryBox* InventoryBox;
};
