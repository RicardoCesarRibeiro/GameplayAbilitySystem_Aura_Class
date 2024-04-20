// Copyright Spellbound Studios.


#include "UI/WidgetController/OverlayWidgetController.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(Usr_AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(Usr_AttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(Usr_AttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(Usr_AttributeSet->GetMaxMana());
	
	
}

void UOverlayWidgetController::BindCallbackstoDependencies()
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Usr_AttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Usr_AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Usr_AttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Usr_AttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{

	OnHealthChanged.Broadcast(Data.NewValue);

}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{

	OnMaxHealthChanged.Broadcast(Data.NewValue);

}
void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{

	OnManaChanged.Broadcast(Data.NewValue);

}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{

	OnMaxManaChanged.Broadcast(Data.NewValue);

}