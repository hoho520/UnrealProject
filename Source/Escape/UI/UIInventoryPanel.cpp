// Fill out your copyright notice in the Description page of Project Settings.

#include "UIInventoryPanel.h"
#include "UIInventoryBox.h"
#include "EscapeHUD.h"

void UUIInventoryPanel::NativeConstruct()
{
	Super::NativeConstruct();

	PanelLayer = E_PanelLayer::Basic;

	InventoryBox->SetCloseEventDelegate(FAction::CreateUObject(this, 
		&UUIInventoryPanel::PanelClose));
}

void UUIInventoryPanel::PanelClose()
{
	AEscapeHUD::SetInventoryPanelVisibility(ESlateVisibility::Collapsed);
}
