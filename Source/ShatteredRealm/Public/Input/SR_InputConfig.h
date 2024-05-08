// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "SR_InputConfig.generated.h"


USTRUCT(BlueprintType)
struct FSr_InputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
	
};

/**
 * 
 */

UCLASS()
class SHATTEREDREALM_API USR_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FSr_InputAction> AbilityInputActions;

	
};
