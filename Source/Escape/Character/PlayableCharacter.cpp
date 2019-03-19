// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayableCharacter.h"
#include "EscapeHUD.h"
#include "UI/UIPlayerInfo.h"
#include "UI/UIDeathPanel.h"
#include "GameFramework/GameModeBase.h"

// Sets default values
APlayableCharacter::APlayableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//SpringArm->SetupAttachment(GetCapsuleComponent());
	//Camera->SetupAttachment(SpringArm);
}

APlayableCharacter::~APlayableCharacter()
{
	PlayerInfoUI = nullptr;
	DeathPanelUI = nullptr;
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

void APlayableCharacter::Jump()
{
	Super::Jump();

	//DecreaseStamina(5.f);
}

// Called every frame
void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStamina < MaxStamina)
	{
		RecoverStamina(0.01f);
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
		Jump();
	}
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
