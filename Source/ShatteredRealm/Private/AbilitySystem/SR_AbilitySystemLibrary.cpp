// Copyright Spellbound Studios.


#include "AbilitySystem/SR_AbilitySystemLibrary.h"

#include "Game/SR_GameModeBase.h"
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

void USR_AbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC)
{
	AShatteredRealmGameModeBase* Sr_GameMode = Cast<AShatteredRealmGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (Sr_GameMode == nullptr) return;

	AActor* AvatarActor = ASC->GetAvatarActor();
	
	UCharacterClassInfo* CharacterClassInfo = Sr_GameMode->CharacterClassInfo;
	FCharacterClassDefaultInfo ClassDefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

	FGameplayEffectContextHandle PrimaryAttributesContextHandle = ASC->MakeEffectContext();
	PrimaryAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle PrimaryAttributesSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributesSpecHandle.Data.Get());
	
	FGameplayEffectContextHandle SecondaryAttributesContextHandle = ASC->MakeEffectContext();
	SecondaryAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle SecondaryAttributesSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.SecondaryAttributes, Level, SecondaryAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttributesSpecHandle.Data.Get());

	FGameplayEffectContextHandle VitalAttributesContextHandle = ASC->MakeEffectContext();
	VitalAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle VitalAttributesSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.VitalAttributes, Level, VitalAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributesSpecHandle.Data.Get());
}

void USR_AbilitySystemLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC)
{
	AShatteredRealmGameModeBase* Sr_GameMode = Cast<AShatteredRealmGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (Sr_GameMode == nullptr) return;

	UCharacterClassInfo* CharacterClassInfo = Sr_GameMode->CharacterClassInfo;
	for ( TSubclassOf<UGameplayAbility> AbilityClass : CharacterClassInfo->CommonAbilities)
	{
		FGameplayAbilitySpec AbilitySpec =  FGameplayAbilitySpec(AbilityClass, 1);
		ASC->GiveAbility(AbilitySpec);
	}
}
