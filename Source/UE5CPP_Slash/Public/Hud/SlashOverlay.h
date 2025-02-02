// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashOverlay.generated.h"

/**
 * 
 */
UCLASS()
class UE5CPP_SLASH_API USlashOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetHealthBarPercent(float Percent);
	void SetStaminaBarPercent(float Percent);
	void SetGoldText(int32 Gold);
	void SetSoulsText(int32 Souls);
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> HealthProgressBar;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> StaminaProgressBar;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> GoldCountText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> SoulsCountText;
};
