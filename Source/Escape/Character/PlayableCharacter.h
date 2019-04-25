// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGameCharacter.h"
#include "PlayableCharacter.generated.h"

UCLASS()
class ESCAPE_API APlayableCharacter : public AEscapeGameCharacter
{
	GENERATED_BODY()

private:
	// Sets default values for this character's properties
	APlayableCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// HP 바와 스태미너 바 UI 업데이트
	void SetHPGaugeBar();
	void SetStaminaGaugeBar();

public:
	UFUNCTION(BlueprintCallable)
	void JumpAction();
	UFUNCTION(BlueprintCallable)
	void OnFireSkill(TSubclassOf<AActor> NewActorClass);
	UFUNCTION(BlueprintCallable)
	void ShowAimmingPoint(bool bAimming);
	UFUNCTION(BlueprintCallable)
	void ShowSkillCoolTime(float NewCoolTime);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayDeadAnimation();
	UFUNCTION(BlueprintImplementableEvent)
	void PlayHitAnimation();

	// 현재 플레이어의 HP 또는 스태미너 값을 호출
	FORCEINLINE float GetCurrentHP() const { return CurrentHP; }
	FORCEINLINE float GetCurrentStamina() const { return CurrentStamina; }

	// 플레이어 ID 값 호출
	FORCEINLINE uint8 GetCharID() { return CharID; }

	// 기본 HP와 스태미너를 정의하는 함수
	UFUNCTION(BlueprintCallable)
	void SetHP(float NewValue);
	UFUNCTION(BlueprintCallable)
	void SetStamina(float NewValue);

	// Damage를 입거나 스태미너를 소모한 경우 호툴되는 함수
	UFUNCTION(BlueprintCallable)
	void DecreaseHP(float NewValue);
	UFUNCTION(BlueprintCallable)
	void DecreaseStamina(float NewValue);

	// 체력 및 스태미너 회복할 때 호출되는 함수
	UFUNCTION(BlueprintCallable)
	void RecoverHP(float NewValue);
	UFUNCTION(BlueprintCallable)
	void RecoverStamina(float NewValue);

private:
	UPROPERTY()
	class UUIPlayerInfo* PlayerInfoUI;
	UPROPERTY()
	class UUIDeathPanel* DeathPanelUI;
	UPROPERTY()
	class UUIAttackSkill* AttackSkillUI;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	bool bIsAimming = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	bool bIsCoolTime = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	float SkillCoolTime = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Settings")
	float SkillCost = 20.f;
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