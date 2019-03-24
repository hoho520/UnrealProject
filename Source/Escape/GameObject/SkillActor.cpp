// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillActor.h"
#include "Character/EscapeGameCharacter.h"

// Sets default values
ASkillActor::ASkillActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	check(ProjectileMovement);
	this->AddOwnedComponent(ProjectileMovement);
	ProjectileMovement->InitialSpeed = MoveSpeed;
	ProjectileMovement->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void ASkillActor::BeginPlay()
{
	Super::BeginPlay();
	
	this->SetLifeSpan(ActorLifeSpan);
}

// Called every frame
void ASkillActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkillActor::OnCollision(AActor * NewActor)
{
	auto GameChar = Cast<AEscapeGameCharacter>(NewActor);
	if (GameChar)
	{
		E_CharacterType CurType = GameChar->GetCharacterType();
		switch (CurType)
		{
		case E_CharacterType::Owner: // 플레이어와는 충돌해도 없어지지 않음
			return;
		case E_CharacterType::Enemy:
			break;
		case E_CharacterType::NPC:
			break;
		}
		this->Destroy();
	}
	else
	{
		this->Destroy();
	}
}
