// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintClassFinderLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API UBlueprintClassFinderLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UBlueprintClassFinderLibrary();
	~UBlueprintClassFinderLibrary();

public:
	static UClass* GetHUDClass();
	static UClass* GetInventoryPanelClass();
	static TSubclassOf<APawn> GetPlayableCharacterClass();

private:
	static UClass* HUD_Instance;
	static UClass* InvenPanel_Instance;
	static TSubclassOf<APawn> Char_Instance;
};
