// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SR_WidgetController.h"
#include "AttributeMenuWidgetController.generated.h"



class UAttributeInfo;
struct FSr_AttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FSr_AttributeInfo&, Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SHATTEREDREALM_API UAttributeMenuWidgetController : public USR_WidgetController
{
	GENERATED_BODY()

public:
	
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;


	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;

private:

	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const;
};
