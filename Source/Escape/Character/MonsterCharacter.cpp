// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterCharacter.h"
#include "AI/MonsterAIController.h"

// Sets default values
AMonsterCharacter::AMonsterCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MyCharType = E_CharacterType::Enemy;

	AIControllerClass = AMonsterAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called when the game ends or when destroyed
void AMonsterCharacter::BeginDestroy()
{
	Super::BeginDestroy();

	OnAttackEnd.Clear();
}

// Called every frame
void AMonsterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonsterCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attacking!!!"));
}

