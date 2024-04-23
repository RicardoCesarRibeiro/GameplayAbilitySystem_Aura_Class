// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "SR_CharacterBase.h"
#include "SR_Character.generated.h"

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API ASR_Character : public ASR_CharacterBase
{
	GENERATED_BODY()

public:
	ASR_Character();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
private:
	void InitAbilityActorInfo() override;
};
