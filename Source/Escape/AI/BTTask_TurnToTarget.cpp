// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_TurnToTarget.h"
#include "MonsterAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/MonsterCharacter.h"
#include "Character/PlayableCharacter.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	AMonsterCharacter* MySelf = Cast<AMonsterCharacter>(
		OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == MySelf) return EBTNodeResult::Failed;

	APlayableCharacter* Target = Cast<APlayableCharacter>(
		OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMonsterAIController::TargetKey));
	if (nullptr == Target) return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - MySelf->GetActorLocation();
	LookVector.Z = 0.f;

	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	MySelf->SetActorRotation(FMath::RInterpTo(MySelf->GetActorRotation(),
	TargetRot, GetWorld()->GetDeltaSeconds(), 2.f));

	return EBTNodeResult::Succeeded;
}
