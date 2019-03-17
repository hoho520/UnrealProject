// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamagingActor.generated.h"

class APawn;
UCLASS()
class ESCAPE_API ADamagingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamagingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(APawn* NewCharacter);
	UFUNCTION(BlueprintCallable)
	void SetIsActorEnabled(bool bResult) { bIsEnable = bResult;	}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor_Setting")
	float Damage = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor_Setting")
	bool bIsEnable = true;
};
