// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeHUD.h"
#include "BlueprintClassFinderLibrary.h"
#include "UI/UIMainHUDPanel.h"

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
			HudUi->AddToViewport();
			UUIMainHUDPanel::SetMainHUDInstance(HudUi);
		}
	}
}

TWeakObjectPtr<UUIMainHUDPanel> AEscapeHUD::GetHUDPanelUI()
{
	return UUIMainHUDPanel::GetMainHUDPanel();
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
