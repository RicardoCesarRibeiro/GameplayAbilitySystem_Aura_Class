// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SR_GameModeBase.generated.h"

/**
 * 
 */

class UCharacterClassInfo;

UCLASS()
class SHATTEREDREALM_API AShatteredRealmGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TObjectPtr<UCharacterClassInfo> CharacterClassInfo;
	
};
