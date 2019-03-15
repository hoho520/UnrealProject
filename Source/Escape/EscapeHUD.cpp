// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/UIMainHUDPanel.h"

AEscapeHUD::AEscapeHUD()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UUIMainHUDPanel> HUDClass(TEXT("/Game/GameContents/GUI/Blueprint/BP_UIHUD.BP_UIHUD_C"));
	if (HUDClass.Succeeded())
		HUDUI = HUDClass.Class;
}

void AEscapeHUD::BeginPlay()
{
	Super::BeginPlay();

	check(HUDUI);

	auto HudUi = CreateWidget<UUIMainHUDPanel>(GetWorld(), HUDUI);
	if (HudUi)
	{
		HudUi->AddToViewport();
		UUIMainHUDPanel::SetMainHUDInstance(HudUi);
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
