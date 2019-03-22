// Fill out your copyright notice in the Description page of Project Settings.

#include "DestroyingActor.h"

// Sets default values
ADestroyingActor::ADestroyingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestroyingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

