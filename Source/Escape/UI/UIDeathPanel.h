// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIDeathPanel.generated.h"

/**
 * 
 */
class UTextBlock;
class UImage;
UCLASS()
class ESCAPE_API UUIDeathPanel : public UUserWidget
{
	GENERATED_BODY()

protected:
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
