// Fill out your copyright notice in the Description page of Project Settings.

#include "UIMainHUDPanel.h"
#include "Image.h"

TWeakObjectPtr<UUIMainHUDPanel> UUIMainHUDPanel::MainHUD_Instance = nullptr;

void UUIMainHUDPanel::NativeConstruct()
{
	Super::NativeConstruct();
	
	PanelLayer = E_PanelLayer::HUD;
}

TWeakObjectPtr<UUIMainHUDPanel> UUIMainHUDPanel::GetMainHUDPanel()
{
	if (MainHUD_Instance.IsValid())
		return MainHUD_Instance;
	return nullptr;
}

UUIPlayerInfo * UUIMainHUDPanel::GetPlayerInfoUI()
{
	if (PlayerInfo)
		return PlayerInfo;
	return nullptr;
}

UUIDeathPanel * UUIMainHUDPanel::GetDeathPanel()
{
	if (DeathPanel)
		return DeathPanel;
	return nullptr;
}

UUIAttackSkill * UUIMainHUDPanel::GetAttackSkill()
{
	if (AttackSkill)
		return AttackSkill;
	return nullptr;
}

void UUIMainHUDPanel::SetCrosshairVisibility(bool bTrue)
{
	if (Crosshair)
		Crosshair->SetVisibility(bTrue ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
}

void UUIMainHUDPanel::SetMainHUDInstance(UUserWidget * NewWidget)
{
	if (NewWidget)
	{
		MainHUD_Instance = Cast<UUIMainHUDPanel>(NewWidget);
	}
}
