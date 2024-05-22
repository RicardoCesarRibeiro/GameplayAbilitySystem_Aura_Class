// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SR_DropItemRarityListDataAsset.generated.h"

enum EItemRarity : int;
class USR_DropItemListDataAsset;

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API USR_DropItemRarityListDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	USR_DropItemListDataAsset* DropItemList;
	
	UPROPERTY(EditAnywhere)
	TMap<float, TEnumAsByte<EItemRarity>> RarityRollMap;

};
