// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemDropperInterface.generated.h"

class USR_ItemDataAsset;
class USR_DropPoolDataAsset;
class ASR_ItemPickUp;

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
	virtual TSubclassOf<ASR_ItemPickUp> GetItemPickUpClass() = 0;

	void DropItems(AActor* ItemSpawner);

private:
	
	FResultItemData GetResultItemData(USR_ItemDataAsset* ItemDataAsset, TEnumAsByte<EItemRarity> ItemRarity);
	void SpawnItems(TArray<FResultItemData> SpawnItems, AActor* ItemSpawner);
	FVector GetSpawnLocation(AActor* ItemSpawner);
	
};
