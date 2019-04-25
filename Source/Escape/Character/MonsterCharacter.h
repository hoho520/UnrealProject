// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGameCharacter.h"
#include "MonsterCharacter.generated.h"

UCLASS()
class ESCAPE_API AMonsterCharacter : public AEscapeGameCharacter
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	AMonsterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

};
