// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeHUD.h"
#include "BlueprintClassFinderLibrary.h"
#include "UI/UIMainHUDPanel.h"
#include "UI/UIInventoryPanel.h"

TWeakObjectPtr<UUIInventoryPanel> AEscapeHUD::InvenPanel = nullptr;

AEscapeHUD::AEscapeHUD()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HUDUI = UBlueprintClassFinderLibrary::GetHUDClass();
}

void AEscapeHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDUI)
	{
		auto HudUi = CreateWidget<UUIMainHUDPanel>(GetWorld(), HUDUI);
		if (HudUi)
		{
			HudUi->AddToViewport((uint8)HudUi->GetPanelLayer());
			UUIMainHUDPanel::SetMainHUDInstance(HudUi);
		}
	}
	auto InvenClass = UBlueprintClassFinderLibrary::GetInventoryPanelClass();
	if (InvenClass)
	{
		InvenPanel = CreateWidget<UUIInventoryPanel>(GetWorld(), InvenClass);
		if (InvenPanel.IsValid())
		{
			InvenPanel->AddToViewport((uint8)InvenPanel->GetPanelLayer());
			InvenPanel->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

TWeakObjectPtr<UUIMainHUDPanel> AEscapeHUD::GetHUDPanelUI()
{
	return UUIMainHUDPanel::GetMainHUDPanel();
}

TWeakObjectPtr<UUIInventoryPanel> AEscapeHUD::GetInventoryPanel()
{
	return InvenPanel;
}

UUIPlayerInfo* AEscapeHUD::GetPlayerInfo()
{
	if (GetHUDPanelUI().IsValid())
		return GetHUDPanelUI()->GetPlayerInfoUI();
	return nullptr;
}

UUIDeathPanel * AEscapeHUD::GetDeathPanel()
{
	if (GetHUDPanelUI().IsValid())
		return GetHUDPanelUI()->GetDeathPanel();
	return nullptr;
}

UUIAttackSkill * AEscapeHUD::GetAttackSkill()
{
	if (GetHUDPanelUI().IsValid())
		return GetHUDPanelUI()->GetAttackSkill();
	return nullptr;
}
