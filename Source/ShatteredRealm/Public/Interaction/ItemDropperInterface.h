// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemDropperInterface.generated.h"

class USR_ItemDataAsset;
class USR_DropPoolDataAsset;

enum EItemRarity : int;
struct FRollItemData;
struct FResultItemData;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USR_ItemDropperInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHATTEREDREALM_API ISR_ItemDropperInterface
{
	GENERATED_BODY()

public:

	virtual USR_DropPoolDataAsset* GetDropPoolDataAsset() = 0;
	void DropItems(FVector ItemSpawnLocation, AActor* ItemSpawner);

private:
	
	FResultItemData GetResultItemData(USR_ItemDataAsset* ItemDataAsset, TEnumAsByte<EItemRarity> ItemRarity);
	void SpawnItems(TArray<FResultItemData> SpawnItems, FVector ItemSpawnLocation, AActor* ItemSpawner);
	
};
