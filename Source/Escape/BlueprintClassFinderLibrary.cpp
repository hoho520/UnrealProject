// Fill out your copyright notice in the Description page of Project Settings.

#include "BlueprintClassFinderLibrary.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UClass* UBlueprintClassFinderLibrary::HUD_Instance = nullptr;
TSubclassOf<APawn> UBlueprintClassFinderLibrary::Char_Instance = nullptr;

UBlueprintClassFinderLibrary::UBlueprintClassFinderLibrary()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> HUDClass(TEXT("/Game/GameContents/GUI/Blueprint/BP_UIHUD.BP_UIHUD_C"));
	if (HUDClass.Succeeded())
		HUD_Instance = HUDClass.Class;
	static ConstructorHelpers::FClassFinder<APawn> CharacterClass(TEXT("/Game/GameContents/ParagonShinbi/Characters/Heroes/Shinbi/ShinbiPlayerCharacter.ShinbiPlayerCharacter_C"));
	if (CharacterClass.Succeeded())
		Char_Instance = CharacterClass.Class;
}

UBlueprintClassFinderLibrary::~UBlueprintClassFinderLibrary()
{
	HUD_Instance = nullptr;
	Char_Instance = nullptr;
}

UClass * UBlueprintClassFinderLibrary::GetHUDClass()
{
	if (HUD_Instance)
		return HUD_Instance;
	return nullptr;
}

TSubclassOf<APawn> UBlueprintClassFinderLibrary::GetPlayableCharacterClass()
{
	if (Char_Instance)
		return Char_Instance;
	return nullptr;
}
