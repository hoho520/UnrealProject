// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsInAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API UBTDecorator_IsInAttackRange : public UBTDecorator
{
	GENERATED_BODY()
	
protected:
	UBTDecorator_IsInAttackRange();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, 
		uint8* NodeMemory) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AckDistance = 200.f;
};
