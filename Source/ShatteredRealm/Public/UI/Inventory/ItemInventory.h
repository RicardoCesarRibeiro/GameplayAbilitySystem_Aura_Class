// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Items/SR_ItemDataAsset.h"
#include "ItemInventory.generated.h"




/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API UItemInventory : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly)
	FResultItemData ItemData;
	
	void Init(FResultItemData NewItemData);
};