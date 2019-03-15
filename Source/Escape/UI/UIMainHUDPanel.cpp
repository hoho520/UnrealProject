// Fill out your copyright notice in the Description page of Project Settings.

#include "UIMainHUDPanel.h"
#include "UIPlayerInfo.h"

TWeakObjectPtr<UUIMainHUDPanel> UUIMainHUDPanel::MainHUD_Instance = nullptr;

void UUIMainHUDPanel::NativeConstruct()
{
	Super::NativeConstruct();

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

void UUIMainHUDPanel::SetMainHUDInstance(UUserWidget * NewWidget)
{
	if (NewWidget)
	{
		MainHUD_Instance = Cast<UUIMainHUDPanel>(NewWidget);
	}
}
