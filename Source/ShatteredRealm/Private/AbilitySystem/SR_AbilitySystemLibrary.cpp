// Copyright Spellbound Studios.


#include "AbilitySystem/SR_AbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/SR_PlayerState.h"
#include "UI/HUD/SR_HUD.h"
#include "UI/WidgetController/SR_WidgetController.h"

UOverlayWidgetController* USR_AbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if(ASr_HUD* Sr_HUD = Cast<ASr_HUD>(PC->GetHUD()))
		{
			ASr_PlayerState* PS = PC->GetPlayerState<ASr_PlayerState>();
			UAbilitySystemComponent* ASC =  PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams (PC,PS,ASC,AS);
			return Sr_HUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* USR_AbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if(ASr_HUD* Sr_HUD = Cast<ASr_HUD>(PC->GetHUD()))
		{
			ASr_PlayerState* PS = PC->GetPlayerState<ASr_PlayerState>();
			UAbilitySystemComponent* ASC =  PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams (PC,PS,ASC,AS);
			return Sr_HUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
	
}
