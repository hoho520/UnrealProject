// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIInventorySlot.generated.h"

/**
 * 
 */
class UButton;
class UImage;

UCLASS()
class ESCAPE_API UUIInventorySlot : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	void SetItemSlot(int32 NewItemID);
	void SetEmptySlot();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* SlotBtn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ItemImg;
};
