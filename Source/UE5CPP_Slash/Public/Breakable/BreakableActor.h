// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"

#include "BreakableActor.generated.h"

UCLASS()
class UE5CPP_SLASH_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UCapsuleComponent> Capsule;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UGeometryCollectionComponent> GeometryCollectionComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	UFUNCTION()
	void Test(const struct FChaosBreakEvent& BreakEvent);

	// Hérité via IHitInterface
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	UPROPERTY(EditAnywhere, Category = "Breakable Properties")
	TArray<TSubclassOf<class ATreasure>>  TreasureClasses;

	bool bBroken = false;

};
