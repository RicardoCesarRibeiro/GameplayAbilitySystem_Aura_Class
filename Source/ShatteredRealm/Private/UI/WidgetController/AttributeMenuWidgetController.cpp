// Copyright Spellbound Studios.

#include <UI/WidgetController/AttributeMenuWidgetController.h>
#include <AbilitySystem/SR_AttributeSet.h>
#include <AbilitySystem/Data/AttributeInfo.h>



void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	USR_AttributeSet* AS = CastChecked<USR_AttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
	);	
	}
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	USR_AttributeSet* AS = CastChecked<USR_AttributeSet>(AttributeSet);
	
	check(AttributeInfo);
	
	for (auto& Pair : AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FSr_AttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}

