// Fill out your copyright notice in the Description page of Project Settings.

#include "UIDeathPanel.h"
#include "Image.h"
#include "TextBlock.h"

void UUIDeathPanel::NativeConstruct()
{
	Super::NativeConstruct();

	PanelLayer = E_PanelLayer::Death;
}

void UUIDeathPanel::SetBloodImgAndTextByPlayerHealth(float HealthPercent)
{
	float RemainHealthPer = 1 - HealthPercent;
	BloodImg->SetRenderOpacity(RemainHealthPer >= 0.3f ? RemainHealthPer : 0);
	bool bIsDead = HealthPercent == 0.f;
	DieText->SetVisibility(bIsDead ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
	if (bIsDead)
		StartFadeOutAnimation();
}
