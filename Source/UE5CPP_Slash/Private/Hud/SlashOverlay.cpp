// Fill out your copyright notice in the Description page of Project Settings.


#include "Hud/SlashOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USlashOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetGoldText(int32 Gold)
{
	if (GoldCountText)
	{
		const FText GoldText = FText::FromString(FString::Printf(TEXT("%d"), Gold));
		GoldCountText->SetText(GoldText);
	}
}

void USlashOverlay::SetSoulsText(int32 Souls)
{
	if (SoulsCountText)
	{
		const FText SoulsText = FText::FromString(FString::Printf(TEXT("%d"), Souls));
		SoulsCountText->SetText(SoulsText);
	}
}
