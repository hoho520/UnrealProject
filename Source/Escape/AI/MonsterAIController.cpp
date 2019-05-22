// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterAIController.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AMonsterAIController::HomePosKey(TEXT("HomePos"));
const FName AMonsterAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AMonsterAIController::TargetKey(TEXT("Target"));

AMonsterAIController::AMonsterAIController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(
	TEXT("/Game/GameContents/Character/AI/BTT_Troll.BTT_Troll"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(
		TEXT("/Game/GameContents/Character/AI/Blackboard_Monster.Blackboard_Monster"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}
}

void AMonsterAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	if (BBAsset && UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			UE_LOG(LogTemp, Error, TEXT("AIController can't find correct BT."));
		}
	}

	GetWorld()->GetTimerManager().SetTimer(RepeatTimeHandle, this,
		&AMonsterAIController::OnRepeatTimer, RepeatInterval, true);
}

void AMonsterAIController::UnPossess()
{
	Super::UnPossess();

	GetWorld()->GetTimerManager().ClearTimer(RepeatTimeHandle);
}

void AMonsterAIController::OnRepeatTimer()
{
	APawn* MyPawn = GetPawn();
	if (MyPawn == nullptr) return;

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSys == nullptr) return;

	FNavLocation NextLocation;
	if (NavSys->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f,
		NextLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Simple Move doesn't operate."));
	}
}
