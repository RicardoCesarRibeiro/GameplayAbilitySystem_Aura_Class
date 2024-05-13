// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SR_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API USR_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FGameplayTag StartupInputTag;
	
};
