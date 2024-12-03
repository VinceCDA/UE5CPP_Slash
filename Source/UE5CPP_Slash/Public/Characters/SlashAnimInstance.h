// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "SlashAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class UE5CPP_SLASH_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class ASlashCharacter> SlashCharacter;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	TObjectPtr<class UCharacterMovementComponent> SlashCharacterMovement;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool IsFalling;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	ECharacterState CharacterState;
	UPROPERTY(BlueprintReadOnly, Category = "Action State")
	EActionState ActionState;
	UPROPERTY(BlueprintReadOnly, Category = "Death State")
	TEnumAsByte<EDeathPose> DeathPose;
	
};
