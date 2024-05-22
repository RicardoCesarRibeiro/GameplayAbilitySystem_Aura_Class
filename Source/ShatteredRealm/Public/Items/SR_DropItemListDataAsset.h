// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SR_DropItemListDataAsset.generated.h"

class USR_ItemDataAsset;
/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API USR_DropItemListDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TMap<float, USR_ItemDataAsset*> ItemRollMap;
};
