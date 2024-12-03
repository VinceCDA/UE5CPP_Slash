// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "CharacterTypes.h"
#include "BaseCharacter.generated.h"

UCLASS()
class UE5CPP_SLASH_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	TObjectPtr<AActor> CombatTarget;
	UPROPERTY(EditAnywhere, Category = "Combat")
	double WarpTargetDistance = 75.0f;
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	TObjectPtr<class AWeapon> EquippedWeapon;
	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	TObjectPtr<class UAttributeComponent> Attributes;
	UPROPERTY(BlueprintReadOnly)
	TEnumAsByte<EDeathPose> DeathPose;

	UFUNCTION(BlueprintCallable)
	virtual void AttackEnd();
	UFUNCTION(BlueprintCallable)
	virtual void DodgeEnd();
	UFUNCTION(BlueprintCallable)
	void SetWeaponCollision(ECollisionEnabled::Type CollisionType);
	void DisableMeshCollision();
	

	virtual void PlayHitReactMontage(const FName& SectionName);
	virtual int32 PlayAttackMontage();
	virtual int32 PlayDeathMontage();
	virtual void PlayDodgeMontage();
	void StopAttackMontage();
	UFUNCTION(BlueprintCallable)
	FVector GetTranslationWarpTarget();
	UFUNCTION(BlueprintCallable)
	FVector GetRotationWarpTarget();
	virtual bool CanAttack();
	bool IsAlive();
	UFUNCTION(BlueprintNativeEvent)
	void Die();
	void PlayHitSound(const FVector& ImpactPoint);
	void PlayHitNiagara(const FVector& ImpactPoint);
	void DirectionalHitReact(const FVector& ImpactPoint);
	virtual void HandleDamage(float DamageAmount);

	void DisableCapsule();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	FORCEINLINE TEnumAsByte<EDeathPose> GetDeathPose() const { return DeathPose; }

	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr<class UAnimMontage> AttackMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TArray<FName> AttackMontageSections;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr<class UAnimMontage> HitReactMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr<class UAnimMontage> DeathMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TArray<FName> DeathMontageSections;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr<class UAnimMontage> DodgeMontage;
	UPROPERTY(EditAnywhere, Category = "Sounds")
	TObjectPtr<class USoundBase> HitSound;
	UPROPERTY(EditAnywhere, Category = "Sounds")
	TObjectPtr<class UNiagaraSystem> HitNiagara;

	void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName);
	int32 PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames);
};
