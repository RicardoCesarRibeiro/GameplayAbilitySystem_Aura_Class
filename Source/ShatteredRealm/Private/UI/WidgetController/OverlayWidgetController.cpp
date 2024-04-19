// Copyright Spellbound Studios.


#include "UI/WidgetController/OverlayWidgetController.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(Usr_AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(Usr_AttributeSet->GetMaxHealth());

	
	
}

void UOverlayWidgetController::BindCallbackstoDependencies()
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);
	
	
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
	const USR_AttributeSet* Usr_AttributeSet = CastChecked<USR_AttributeSet>(AttributeSet);

	
	
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	
}
