// Copyright Spellbound Studios.


#include "UI/WidgetController/SR_WidgetController.h"

void USR_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
	
}

void USR_WidgetController::BroadcastInitialValues()
{
	
}

void USR_WidgetController::BindCallbacksToDependencies()
{
	
}
