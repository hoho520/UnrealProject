// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	AMonsterAIController();
	virtual void Possess(APawn* InPawn) override;
	virtual void UnPossess() override;

private:
	void OnRepeatTimer();

protected:
	FTimerHandle RepeatTimeHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RepeatInterval = 3.f;

public:
	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;

private:
	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;
};
