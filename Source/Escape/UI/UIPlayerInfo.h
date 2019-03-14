// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIPlayerInfo.generated.h"

/**
 플레이어의 정보를 나타내는 UI 클래스 
 */
class APawn;
class UProgressBar;
class UImage;

struct FSlateBrush;

UCLASS()
class ESCAPE_API UUIPlayerInfo : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetCharIcon(APawn* NewPawn);
	void SetHPProgressBar(float NewValue);
	void SetStaminaProgressBar(float NewValue);

private:
	UPROPERTY(EditInstanceOnly)
	FSlateBrush Char1Icon;
	UPROPERTY(EditInstanceOnly)
	FSlateBrush Char2Icon;
	UPROPERTY(EditInstanceOnly)
	FSlateBrush Char3Icon;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* CharIcon;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HP_Bar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* Stamina_Bar;
};
