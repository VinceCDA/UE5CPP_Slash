// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"

/**
 *
 */
UCLASS()
class UE5CPP_SLASH_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
	AWeapon();
	void Equip(USceneComponent* InParent, FName InSocketName, AActor* NewOwner, APawn* NewInstigater);
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);
	void DisableParticlesEffect();
	void DisableSphereCollision();
	void PlayEquipSound();
	UPROPERTY()
	TArray<AActor*> IgnoreActors;
protected:
	virtual void BeginPlay() override;
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	bool ActorIsSameType(AActor* OtherActor);
	void ExecuteGetHit(FHitResult& BoxHit);
	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& FieldLocation);

private:
	
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr<class UBoxComponent> WeaponBox;
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr<class USceneComponent> BoxTraceStart;
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr<class USceneComponent> BoxTraceEnd;
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	FVector BoxTraceExtent = FVector(5.0f);
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	bool bShowBoxDebug = false;
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	TObjectPtr<class USoundBase> EquipSound;
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
    float Damage = 20.0f;

	void BoxTrace(FHitResult& BoxHit);
	
public:
	FORCEINLINE class UBoxComponent* GetWeaponBox() const { return WeaponBox; }
};
