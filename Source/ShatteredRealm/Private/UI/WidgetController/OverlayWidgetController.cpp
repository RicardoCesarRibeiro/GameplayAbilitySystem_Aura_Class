// Copyright Spellbound Studios.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SR_AbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(Usr_AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(Usr_AttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(Usr_AttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(Usr_AttributeSet->GetMaxMana());
	
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Usr_AttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	Usr_AttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Usr_AttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	Usr_AttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);
	

	Cast<USR_AbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for(const FGameplayTag& Tag: AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if(Tag.MatchesTag(MessageTag))
				{
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
				
			}
		}
	);
}

