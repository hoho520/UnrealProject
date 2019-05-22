// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_Detect.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API UBTService_Detect : public UBTService
{
	GENERATED_BODY()
	
protected:
	UBTService_Detect();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, 
		uint8* NodeMemory, float DeltaSeconds) override;
};
