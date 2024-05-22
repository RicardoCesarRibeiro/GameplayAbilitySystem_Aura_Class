// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SR_DropPoolDataAsset.generated.h"

/**
 * 
 */


class USR_DropItemRarityListDataAsset;

UCLASS()
class SHATTEREDREALM_API USR_DropPoolDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	TArray<USR_DropItemRarityListDataAsset*> DropItemRarityList;
};
