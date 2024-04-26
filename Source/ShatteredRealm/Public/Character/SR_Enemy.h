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
class SHATTEREDREALM_API ASr_Enemy : public ASr_CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ASr_Enemy();


	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */

	/**Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/**End Combat Interface */

	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;




};
