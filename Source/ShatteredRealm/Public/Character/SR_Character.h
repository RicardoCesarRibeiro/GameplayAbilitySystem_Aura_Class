// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "SR_CharacterBase.h"
#include "SR_Character.generated.h"

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API ASr_Character : public ASr_CharacterBase
{
	GENERATED_BODY()

public:
	ASr_Character();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Combat Interface **/
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface **/
private:
	void InitAbilityActorInfo() override;
};
