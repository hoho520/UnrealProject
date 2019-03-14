// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayableCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/UIPlayerInfo.h"

// Sets default values
APlayableCharacter::APlayableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UUIPlayerInfo> PlayerInfoClass(TEXT("/Game/Content/GameContents/GUI/Blueprint/BP_UIPlayerInfo"));
	if (PlayerInfoClass.Succeeded())
		PlayerInfoUI = PlayerInfoClass.Class;
}

// Called when the game starts or when spawned
void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayableCharacter::SetHP(float NewValue)
{
	CurrentHP = NewValue;
	MaxHP = NewValue;
}

void APlayableCharacter::SetStamina(float NewValue)
{
	CurrentStamina = NewValue;
	MaxStamina = NewValue;
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

	if (PlayerInfoUI)
	{
		auto PlayerInfo = Cast<UUIPlayerInfo>(PlayerInfoUI);
		if (PlayerInfo)
			PlayerInfo->SetHPProgressBar(CurrentHP / MaxHP);
	}
}

void APlayableCharacter::DecreaseStamina(float NewValue)
{
	CurrentStamina -= NewValue;
	if (CurrentStamina <= 0.f)
		CurrentStamina = 0.f;
}

void APlayableCharacter::RecoverHP(float NewValue)
{
	CurrentHP += NewValue;
	if (CurrentHP >= MaxHP)
		CurrentHP = MaxHP;
}

void APlayableCharacter::RecoverStamina(float NewValue)
{
	CurrentStamina += NewValue;
	if (CurrentStamina >= MaxStamina)
		CurrentStamina = MaxStamina;
}
