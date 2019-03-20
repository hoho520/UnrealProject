// Fill out your copyright notice in the Description page of Project Settings.

#include "UIAttackSkill.h"
#include "Image.h"
#include "TextBlock.h"

#include "TimerManager.h"

void UUIAttackSkill::StartCountDown(float StartTime)
{
	CountDownTime = StartTime;
	GetWorld()->GetTimerManager().SetTimer(CountDownTimerHanlder, this, &UUIAttackSkill::CountDown, 1.f, true, 0.f);
}

void UUIAttackSkill::CountDown()
{
	if (CountDownTime <= 0.0f)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHanlder);
		CoolTimeText->SetVisibility(ESlateVisibility::Collapsed);
		SkillImage->SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f));
	}
	else
	{
		FString TimerTxt = FText::AsNumber(CountDownTime).ToString();
		CoolTimeText->SetText(FText::FromString(TimerTxt));
		CoolTimeText->SetVisibility(ESlateVisibility::HitTestInvisible);
		SkillImage->SetColorAndOpacity(FLinearColor(0.25f, 0.25f, 0.25f));
		CountDownTime -= 1.f;
	}
}

void UUIAttackSkill::SetSkillImageAndText(float NewCoolTime)
{
	StartCountDown(NewCoolTime);
}