﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeGameCharacter.h"

// Sets default values
AEscapeGameCharacter::AEscapeGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscapeGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEscapeGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

