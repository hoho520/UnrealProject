// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIAttackSkill.generated.h"

/**
 * 
 */
class UTextBlock;
class UImage;
UCLASS()
class ESCAPE_API UUIAttackSkill : public UUserWidget
{
	GENERATED_BODY()

protected:
	void StartCountDown(float StartTime);
	void CountDown();
	
public:
	void SetSkillImageAndText(float NewCoolTime);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CoolTimeText;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* SkillImage;

private:
	FTimerHandle CountDownTimerHanlder;
	float CountDownTime = 0.f;

};
