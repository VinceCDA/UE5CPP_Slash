// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/PickupInterface.h"
#include "BaseCharacter.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class UGroomComponent;
class UInputAction;



UCLASS()
class UE5CPP_SLASH_API ASlashCharacter : public ABaseCharacter,public IPickupInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlashCharacter();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/*
	Components
	*/
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> Camera;

	/*
	Inputs Actions
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<class UInputMappingContext> SlashCharacterMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> ZoomCameraAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> AttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> InteractAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> DodgeAction;

	/*
	Input Callbacks
	*/
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void ZoomCamera(const FInputActionValue& Value);

	/*
	Anim Notify
	*/
	virtual void AttackEnd() override;
	virtual void DodgeEnd() override;
	FORCEINLINE virtual bool CanAttack() override { return ActionState == EActionState::EAS_Unoccupied && CharacterState != ECharacterState::ECS_Unequipped; }
	FORCEINLINE bool CanDisarm() const { return ActionState == EActionState::EAS_Unoccupied && CharacterState != ECharacterState::ECS_Unequipped; }
	FORCEINLINE bool CanArm() const { return ActionState == EActionState::EAS_Unoccupied && CharacterState == ECharacterState::ECS_Unequipped && EquippedWeapon; }

	
	void EquipWeapon(AWeapon* Weapon);
	void PlayEquipMontage(FName SectionName);
	virtual void Die_Implementation() override;

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();
	void Disarm();
	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();
	void Arm();
	UFUNCTION(BlueprintCallable)
	void FinishEquipping();
	UFUNCTION(BlueprintCallable)
	void HitReactEnd();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	void virtual Jump() override;
private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	EActionState ActionState = EActionState::EAS_Unoccupied;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCapsuleComponent> Capsule;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> EchoMesh;
	UPROPERTY()
	TObjectPtr<class USlashOverlay> SlashOverlay;
	UPROPERTY(VisibleAnywhere, Category = "Hair")
	TObjectPtr<UGroomComponent> Hair;
	UPROPERTY(VisibleAnywhere, Category = "Hair")
	TObjectPtr<UGroomComponent> Eyebrows;
	UPROPERTY(VisibleInstanceOnly)
	TObjectPtr<class AItem> OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr<class UAnimMontage> EquipMontage;

	void InitializeSlashOverlay(APlayerController* PlayerController);
	void SetHUDHealth();
	bool HasEnoughStamina();
	FORCEINLINE bool IsUnoccupied() const { return ActionState == EActionState::EAS_Unoccupied; }

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
	virtual void SetOverlappingItem(AItem* Item) override;
	virtual void AddSouls(ASoul* Soul) override;
	virtual void AddGold(ATreasure* Treasure) override;
};
