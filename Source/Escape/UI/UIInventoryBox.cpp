// Fill out your copyright notice in the Description page of Project Settings.

#include "UIInventoryBox.h"
#include "UIInventorySlot.h"
#include "Button.h"
#include "CustomWidget/EscapeTileView.h"

void UUIInventoryBox::NativeConstruct()
{
	Super::NativeConstruct();

	CloseBtn->OnClicked.AddDynamic(this, &UUIInventoryBox::Close);

	if (InvenSlotClass)
	{
		for (int i = 0; i < InvenMaxSize; ++i)
			AddInventorySlot();
	}
}

void UUIInventoryBox::NativeDestruct()
{
	Super::NativeDestruct();

	CloseEventDelegate.Unbind();
}

void UUIInventoryBox::AddInventorySlot()
{
	auto ItemSlot = CreateWidget<UUIInventorySlot>(GetWorld(), InvenSlotClass);
	if (ItemSlot)
	{
		InvenTileView->AddItem(ItemSlot);
		ItemSlot->SetEmptySlot();
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
