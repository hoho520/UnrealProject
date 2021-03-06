﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayableCharacter.h"
#include "EscapeHUD.h"
#include "UI/UIMainHUDPanel.h"
#include "UI/UIPlayerInfo.h"
#include "UI/UIDeathPanel.h"
#include "UI/UIAttackSkill.h"
#include "GameObject/SkillActor.h"
#include "GameFramework/GameModeBase.h"

// Sets default values
APlayableCharacter::APlayableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyCharType = E_CharacterType::Owner;
}

// Called when the game starts or when spawned
void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerInfoUI = AEscapeHUD::GetPlayerInfo();
	if (PlayerInfoUI)
	{
		SetHP(100.f);
		SetStamina(100.f);
	}
}

void APlayableCharacter::BeginDestroy()
{
	Super::BeginDestroy();

	PlayerInfoUI = nullptr;
	DeathPanelUI = nullptr;
	AttackSkillUI = nullptr;
}

// Called every frame
void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStamina < MaxStamina)
	{
		RecoverStamina(0.01f);
	}
	if (CurrentHP < MaxHP && CurrentHP > 0)
	{
		RecoverHP(0.01f);
	}
}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayableCharacter::JumpAction()
{
	if (CurrentStamina >= 10.f)
	{
		Super::Jump();
	}
}

void APlayableCharacter::OnFireSkill(TSubclassOf<AActor> NewActorClass)
{
	if (CurrentStamina >= SkillCost)
	{
		FVector SpawnLocation = GetActorLocation() + FVector(50.f, -100.f, 20.f);
		FRotator SpawnRotation = GetControlRotation();
		FVector WorldLocation;
		FVector WorldDirection;
		GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
		const FRotator Rot(0.f, 0.f, 0.f);
		auto ResultLocation = Rot.RotateVector(WorldDirection) + SpawnLocation;
		if (NewActorClass)
		{
			GetWorld()->SpawnActor<ASkillActor>(NewActorClass, ResultLocation, SpawnRotation);
		}

		ShowSkillCoolTime(SkillCoolTime);
		DecreaseStamina(SkillCost);
	}
}

void APlayableCharacter::ShowAimmingPoint(bool bAimming)
{
	auto HudPanel = AEscapeHUD::GetHUDPanelUI();
	if (HudPanel.IsValid())
		HudPanel->SetCrosshairVisibility(bAimming);
}

void APlayableCharacter::ShowSkillCoolTime(float NewCoolTime)
{
	if (AttackSkillUI == nullptr)
		AttackSkillUI = AEscapeHUD::GetAttackSkill();
	if (AttackSkillUI)
		AttackSkillUI->SetSkillImageAndText(NewCoolTime);
}

void APlayableCharacter::SetHP(float NewValue)
{
	CurrentHP = NewValue;
	MaxHP = NewValue;
	SetHPGaugeBar();
}

void APlayableCharacter::SetStamina(float NewValue)
{
	CurrentStamina = NewValue;
	MaxStamina = NewValue;
	SetStaminaGaugeBar();
}

void APlayableCharacter::SetHPGaugeBar()
{
	float HP_Per = CurrentHP / MaxHP;
	PlayerInfoUI->SetHPProgressBar(HP_Per);
	if (DeathPanelUI == nullptr)
		DeathPanelUI = AEscapeHUD::GetDeathPanel();
	if (DeathPanelUI)
		DeathPanelUI->SetBloodImgAndTextByPlayerHealth(HP_Per);
}

void APlayableCharacter::SetStaminaGaugeBar()
{
	PlayerInfoUI->SetStaminaProgressBar(CurrentStamina / MaxStamina);
}

void APlayableCharacter::DecreaseHP(float NewValue)
{
	CurrentHP -= NewValue;
	if (CurrentHP <= 0.f)
	{
		CurrentHP = 0.f;
		PlayDeadAnimation();
	}
	else
	{
		PlayHitAnimation();
	}

	SetHPGaugeBar();
}

void APlayableCharacter::DecreaseStamina(float NewValue)
{
	CurrentStamina -= NewValue;
	if (CurrentStamina <= 0.f)
		CurrentStamina = 0.f;

	SetStaminaGaugeBar();
}

void APlayableCharacter::RecoverHP(float NewValue)
{
	CurrentHP += NewValue;
	if (CurrentHP >= MaxHP)
		CurrentHP = MaxHP;

	SetHPGaugeBar();
}

void APlayableCharacter::RecoverStamina(float NewValue)
{
	CurrentStamina += NewValue;
	if (CurrentStamina >= MaxStamina)
		CurrentStamina = MaxStamina;

	SetStaminaGaugeBar();
}
