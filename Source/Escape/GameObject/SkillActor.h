// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SkillActor.generated.h"

UCLASS()
class ESCAPE_API ASkillActor : public AActor
{
	GENERATED_BODY()
	
private:
	// Sets default values for this actor's properties
	ASkillActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	void OnCollision(AActor* NewActor);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor_Option")
	float MoveSpeed = 2000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor_Option")
	float ActorLifeSpan = 3.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* ProjectileMovement;
};
