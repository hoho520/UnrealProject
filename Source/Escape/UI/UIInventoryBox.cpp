// Fill out your copyright notice in the Description page of Project Settings.

#include "UIInventoryBox.h"
#include "UIInventorySlot.h"
#include <list>
#include <map>
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
		SlotArray.Emplace(ItemSlot);
	}

	TArray<int> a;
	a.Add(1);
	std::list<int> b;
	b.push_back(1);
	b.push_front(2);

	auto MyLambda = [MySize = InvenMaxSize](int a) { return a > MySize; };
	decltype(auto) DeclLambda = MyLambda;
}

void UUIInventoryBox::RefreshTileView()
{
	InvenTileView->RegenerateAllEntries();
}

void UUIInventoryBox::Close()
{
	CloseEventDelegate.ExecuteIfBound();
	InvenTileView->ScrollToTop();
}

UUIInventorySlot * UUIInventoryBox::GetSelectedInventorySlot(int32 index)
{
	if (SlotArray.Num() > 0)
	{
		for (const auto & SlotData : SlotArray)
		{
			if (SlotData->GetItemID() == index)
				return SlotData;
		}
	}
	return nullptr;
}
