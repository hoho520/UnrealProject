// Fill out your copyright notice in the Description page of Project Settings.

#include "DamagingActor.h"
#include "Character/PlayableCharacter.h"

// Sets default values
ADamagingActor::ADamagingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADamagingActor::TakeDamage(APawn * NewCharacter)
{
	APlayableCharacter * MyChar = Cast<APlayableCharacter>(NewCharacter);
	if (MyChar == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no player."));
		return;
	}
	MyChar->DecreaseHP(Damage);
}

// Called when the game starts or when spawned
void ADamagingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamagingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

