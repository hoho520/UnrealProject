﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayableCharacter.generated.h"

UCLASS()
class ESCAPE_API APlayableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayableCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void PlayDeadAnimation();
	UFUNCTION(BlueprintImplementableEvent)
	void PlayHitAnimation();

	// 현재 플레이어의 HP 또는 스태미너 값을 호출
	FORCEINLINE float GetCurrentHP() { return CurrentHP; }
	FORCEINLINE float GetCurrentStamina() { return CurrentStamina; }

	// 플레이어 ID 값 호출
	FORCEINLINE uint8 GetCharID() { return CharID; }

	// 기본 HP와 스태미너를 정의하는 함수
	void SetHP(float NewValue);
	void SetStamina(float NewValue);

	// Damage를 입거나 스태미너를 소모한 경우 호툴되는 함수
	void DecreaseHP(float NewValue);
	void DecreaseStamina(float NewValue);

	// 체력 및 스태미너 회복할 때 호출되는 함수
	void RecoverHP(float NewValue);
	void RecoverStamina(float NewValue);

private:
	UPROPERTY()
	UClass* PlayerInfoUI;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	float CurrentHP = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	float MaxHP = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	float CurrentStamina = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	float MaxStamina = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	uint8 CharID = 0;
};