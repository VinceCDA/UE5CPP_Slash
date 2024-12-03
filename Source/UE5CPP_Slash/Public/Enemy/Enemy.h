// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

UCLASS()
class UE5CPP_SLASH_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
public:
	/* <AActor> */
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	/* </AActor> */

	/* <IHitInterface */
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	/* </IHitInterface */

protected:
	/* <AActor> */
	virtual void BeginPlay() override;
	
	/* </AActor> */

	/* <ABaseCharacter> */
	virtual void Die_Implementation() override;
	virtual bool CanAttack() override;
	virtual void AttackEnd() override;
	
	virtual void HandleDamage(float DamageAmount) override;
	/* </ABaseCharacter> */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestDelegate, float, Too, float, Taa);
	FTestDelegate OnCange;
	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;
	
private:
	// Component
	UPROPERTY()
	TObjectPtr<class AAIController> EnemyController;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UHealthBarComponent> HealthBarWidget;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class AWeapon> WeaponClass;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class ASoul> SoulClass;
	//AI Behavior Patrol

	UPROPERTY(VisibleAnywhere, Category = "IA Navigation")
	TObjectPtr<class UPawnSensingComponent> PawnSensing;
	UPROPERTY(EditAnywhere, Category = "IA Navigation")
	double AccpetanceRadius = 50.0f;
	UPROPERTY(EditAnywhere, Category = "IA Navigation")
	double CombatRadius = 500.0f;
	UPROPERTY(EditAnywhere, Category = "IA Navigation")
	double AttackRadius = 150.0f;
	UPROPERTY(EditAnywhere, Category = "IA Navigation")
	double PatrolRadius = 200.0f;
	UPROPERTY(EditAnywhere, Category = "IA Navigation")
	float PatrolWaitMin = 5.0f;
	UPROPERTY(EditAnywhere, Category = "IA Navigation")
	float PatrolWaitMax = 10.0f;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float PatrollingSpeed = 125.0f;
	UPROPERTY(EditInstanceOnly, Category = "IA Navigation")
	TObjectPtr<AActor> PatrolTarget;
	UPROPERTY(EditInstanceOnly, Category = "IA Navigation")
	TArray<TObjectPtr<AActor>> PatrolTargets;
	FTimerHandle PatrolTimer;
	//AI Behavior Combat
	FTimerHandle AttackTimer;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackCoolDownMin = 0.5f;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackCoolDownMax = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float DeathLifeSpan = 3.0f;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float ChasingSpeed = 300.0f;

	UFUNCTION()
	void PawnSeen(APawn* SeenPawn); //Callback for OnPawnSeen in UPawnComponent
	void InitializeEnemy();
	void SpawnDefaultWeapon();
	AActor* ChoosePatrolTarget();
	void MoveToTarget(AActor* Target);
	void CkeckPatrolTarget();
	void CheckCombatTarget();
	void StartPatrolling();
	void PatrolTimerFinished();
	void ClearPatrolTimer();
	void StartAttackTimer();
	void ClearAttackTimer();
	void LoseInterest();
	void ChaseTarget();
	void Attack();
	void HideHeatlhBar();
	void ShowHealthBar();
	void SpawnSoul();
	bool IsOutsideCombatRadius();
	bool IsOutsideAttackRadius();
	bool IsInsideAttackRadius();
	bool IsChasing();
	bool IsAttacking();
	bool IsDead();
	bool IsEngaged();
	bool IsInTargetRange(AActor* Target, double Radius);
};
