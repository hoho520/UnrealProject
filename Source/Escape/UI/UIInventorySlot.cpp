// Fill out your copyright notice in the Description page of Project Settings.

#include "UIInventorySlot.h"
#include "Button.h"
#include "Image.h"

void UUIInventorySlot::NativeConstruct()
{
	Super::NativeConstruct();

}

void UUIInventorySlot::SetItemSlot(int32 NewItemID)
{
	ItemID = NewItemID;

	SlotBtn->SetVisibility(ESlateVisibility::Visible);
	ItemImg->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UUIInventorySlot::SetEmptySlot()
{
	SlotBtn->SetVisibility(ESlateVisibility::HitTestInvisible);
	ItemImg->SetVisibility(ESlateVisibility::Collapsed);
}
