// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EscapeHUD.generated.h"

/**
 HUD System
 */
class UUIMainHUDPanel;
class UUIInventoryPanel;
class UUIPlayerInfo;
class UUIDeathPanel;
class UUIAttackSkill;

enum class ESlateVisibility : uint8;

UCLASS()
class ESCAPE_API AEscapeHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	AEscapeHUD();

protected:
	virtual void BeginPlay() override;

public:
	static TWeakObjectPtr<UUIMainHUDPanel> GetHUDPanelUI();
	static TWeakObjectPtr<UUIInventoryPanel> GetInventoryPanel();
	static UUIPlayerInfo* GetPlayerInfo();
	static UUIDeathPanel* GetDeathPanel();
	static UUIAttackSkill* GetAttackSkill();

	static void SetInventoryPanelVisibility(ESlateVisibility InVisibility);

protected:
	UPROPERTY()
	UClass* HUDUI;

private:
	static TWeakObjectPtr<UUIInventoryPanel> InvenPanel;

};
