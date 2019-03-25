// Fill out your copyright notice in the Description page of Project Settings.

#include "UIInventoryBox.h"
//#include "UIInventorySlot.h"
#include "Button.h"
#include "TileView.h"

void UUIInventoryBox::NativeConstruct()
{
	Super::NativeConstruct();

	CloseBtn->OnClicked.AddDynamic(this, &UUIInventoryBox::Close);
}

void UUIInventoryBox::AddInventorySlot()
{
	auto ItemSlot = CreateWidget<UUserWidget>(GetWorld(), InvenSlotClass);
	if (ItemSlot)
	{
		InvenTileView->AddItem(ItemSlot);
	}
}

void UUIInventoryBox::RefreshTileView()
{
	InvenTileView->RegenerateAllEntries();
}

void UUIInventoryBox::Close()
{
	CloseEventDelegate.ExecuteIfBound();
}
