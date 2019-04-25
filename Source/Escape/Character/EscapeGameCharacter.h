// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EscapeGameCharacter.generated.h"

/**
 Escape Game용 기본 캐릭터 클래스
 */
UENUM(BlueprintType)
enum class E_CharacterType : uint8
{
	// 플레이어
	Owner = 0,
	// 몬스터
	Enemy, 
	// NPC
	NPC, 
};

UCLASS()
class ESCAPE_API AEscapeGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEscapeGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE E_CharacterType GetCharacterType() const { return MyCharType; }

protected:
	// 캐릭터 타입
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Data")
	E_CharacterType MyCharType = E_CharacterType::Owner;
};
