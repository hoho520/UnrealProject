// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIMainHUDPanel.generated.h"

/**
 ∏ﬁ¿Œ HUD
 */
class UImage;
class UUIPlayerInfo;
class UUIDeathPanel;
class UUIAttackSkill;

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
	UFUNCTION(BlueprintCallable)
	UUIDeathPanel* GetDeathPanel();
	UFUNCTION(BlueprintCallable)
	UUIAttackSkill* GetAttackSkill();

	void SetCrosshairVisibility(bool bTrue);
	static void SetMainHUDInstance(UUserWidget* NewWidget);

private:
	static TWeakObjectPtr<UUIMainHUDPanel> MainHUD_Instance;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUIPlayerInfo* PlayerInfo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUIDeathPanel* DeathPanel;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUIAttackSkill* AttackSkill;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* Crosshair;
};
