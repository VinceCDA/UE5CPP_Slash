// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Soul.generated.h"

/**
 * 
 */
UCLASS()
class UE5CPP_SLASH_API ASoul : public AItem
{
	GENERATED_BODY()
	
protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
private:
	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	int32 SoulsValue;
	double DesiredZ;
	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	float DriftRate = -15.0f;
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE int32 GetSouls() const { return SoulsValue; }
	FORCEINLINE void SetSouls(int32 NumberOfSouls) { SoulsValue = NumberOfSouls; }
};
