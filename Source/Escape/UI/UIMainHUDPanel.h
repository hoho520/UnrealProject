// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIMainHUDPanel.generated.h"

/**
 ∏ﬁ¿Œ HUD
 */
class UUIPlayerInfo;

UCLASS()
class ESCAPE_API UUIMainHUDPanel : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	static TWeakObjectPtr<UUIMainHUDPanel> GetMainHUDPanel();
	UFUNCTION(BlueprintCallable)
	UUIPlayerInfo* GetPlayerInfoUI();

	static void SetMainHUDInstance(UUserWidget* NewWidget);

private:
	static TWeakObjectPtr<UUIMainHUDPanel> MainHUD_Instance;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUIPlayerInfo* PlayerInfo;
};
