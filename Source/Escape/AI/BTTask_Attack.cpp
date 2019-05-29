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
	MySelf->OnAttackEnd.AddLambda([this]() -> void { // 반환형 명시 (-> void) : void 형 반환
		SetIsAttacking(false); // 현재 객체를 this로 캡쳐해 참조함로써 객체의 멤버를 가져 옴
		// [=] : this와 마찬가지로 객체를 참조로 가져오고, context 내 모든 변수를 복사로 캡쳐
		// [&] : this와 마찬가지로 객체를 참조로 가져오고, context 내 모든 변수를 참조로 캡쳐
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
