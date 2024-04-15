// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "SR_CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "SR_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API ASR_Enemy : public ASR_CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ASR_Enemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
};
