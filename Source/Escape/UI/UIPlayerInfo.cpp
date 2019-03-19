// Fill out your copyright notice in the Description page of Project Settings.

#include "UIPlayerInfo.h"
#include "ProgressBar.h"
#include "Image.h"

#include "Character/PlayableCharacter.h"

void UUIPlayerInfo::NativeConstruct()
{
	Super::NativeConstruct();

}

void UUIPlayerInfo::SetCharIcon(APawn * NewPawn)
{
	APlayableCharacter* MyChar = Cast<APlayableCharacter>(NewPawn);
	if (MyChar == nullptr) return;
	uint8 CurCharID = MyChar->GetCharID();
	switch (CurCharID)
	{
	case 1:
		CharIcon->SetBrush(Char1Icon);
		break;
	case 2:
		CharIcon->SetBrush(Char2Icon);
		break;
	case 3:
		CharIcon->SetBrush(Char3Icon);
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("This is invalid ID."));
		break;
	}
}

void UUIPlayerInfo::SetHPProgressBar(float NewValue)
{
	if (HP_Bar)
		HP_Bar->SetPercent(NewValue);
}

void UUIPlayerInfo::SetStaminaProgressBar(float NewValue)
{
	if (Stamina_Bar)
		Stamina_Bar->SetPercent(NewValue);
}
