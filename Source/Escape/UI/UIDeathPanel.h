// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIPanelBase.h"
#include "UIDeathPanel.generated.h"

/**
 * 
 */
class UTextBlock;
class UImage;
UCLASS()
class ESCAPE_API UUIDeathPanel : public UUIPanelBase
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartFadeOutAnimation();
	
public:
	void SetBloodImgAndTextByPlayerHealth(float HealthPercent);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DieText;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* BloodImg;
};
