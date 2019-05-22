// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"
#include "MonsterAIController.h"

#include "Character/MonsterCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	
	AMonsterCharacter* MySelf = Cast<AMonsterCharacter>(
		OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == MySelf) return EBTNodeResult::Failed;
	
	MySelf->Attack();
	bIsAttacking = true;
	MySelf->OnAttackEnd.AddLambda([this]() -> void {
		bIsAttacking = false;
	});

	return Result;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (!bIsAttacking)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
