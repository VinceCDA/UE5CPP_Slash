// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class UE5CPP_SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USphereComponent> Sphere;
	UPROPERTY(VisibleAnywhere, Category = "Particles")
	TObjectPtr<class UNiagaraComponent> NiagaraParticles;
	UPROPERTY(EditAnywhere, Category = "Pickup Effect")
	TObjectPtr<class UNiagaraSystem> PickupEffect;	
	UPROPERTY(EditAnywhere, Category = "Pickup Effect")
	TObjectPtr<USoundBase> PickupSound;
	UFUNCTION(BlueprintPure)
	float TransformedSin();
	UFUNCTION(BlueprintPure)
	float TransformedCos();
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	template<typename T>
	T Avg(T First, T Second);
	virtual void SpawnPickupSystem();
	virtual void SpawnPickupSound();
	EItemState ItemState = EItemState::EIS_Hovering;
private:
	
	
	UPROPERTY(VisibleAnywhere)
	float RunningTime;
	UPROPERTY(EditAnywhere, Category = "Sine Parameters")
	float Amplitude = 0.25f;
	UPROPERTY(EditAnywhere, Category = "Sine Parameters")
	float TimeConstant = 5.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return T();
}
