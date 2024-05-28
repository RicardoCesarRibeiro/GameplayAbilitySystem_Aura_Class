// Copyright Spellbound Studios.


#include "Interaction/ItemDropperInterface.h"

#include "Actor/SR_ItemPickUp.h"
#include "Field/FieldSystemNodes.h"
#include "Items/SR_DropItemListDataAsset.h"
#include "Items/SR_DropItemRarityListDataAsset.h"
#include "Items/SR_DropPoolDataAsset.h"
#include "Items/SR_ItemDataAsset.h"

// Add default functionality here for any ISR_ItemDropper functions that are not pure virtual.


void ISR_ItemDropperInterface::DropItems(AActor* ItemSpawner)
{
	if (GetDropPoolDataAsset() && ItemSpawner)
	{
		TArray<FResultItemData> ResultItems;
		
		for (USR_DropItemRarityListDataAsset* RarityList : GetDropPoolDataAsset()->DropItemRarityList)
		{
			float RarityRoll = FMath::RandRange(0.f,1.0f);
			TEnumAsByte<EItemRarity> Rarity = EItemRarity::IR_None;
			for (const TPair<float, TEnumAsByte<EItemRarity>>& pair : RarityList->RarityRollMap)
			{
				if (RarityRoll <= pair.Key)
				{
					Rarity = pair.Value;
					break;
				}
			}
			if (Rarity != EItemRarity::IR_None)
			{
				float ItemRoll = FMath::RandRange(0.f,1.0f);
				USR_ItemDataAsset* ItemDataAsset = nullptr;
				for (const TPair<float, USR_ItemDataAsset*>& pair : RarityList->DropItemList->ItemRollMap)
				{
					if (ItemRoll <= pair.Key)
					{
						ItemDataAsset = pair.Value;
						break;
					}
				}
				ResultItems.Add(GetResultItemData(ItemDataAsset, Rarity));
			}
		}
		SpawnItems(ResultItems, ItemSpawner);
	}
}

FResultItemData ISR_ItemDropperInterface::GetResultItemData(USR_ItemDataAsset* ItemDataAsset, TEnumAsByte<EItemRarity> ItemRarity)
{
	FResultItemData ResultItemData;
	if (ItemDataAsset)
	{
		ResultItemData.ItemType = ItemDataAsset->ItemData.ItemType;
		ResultItemData.ItemSlot = ItemDataAsset->ItemData.ItemSlot;
		ResultItemData.ItemRarity = ItemRarity;
		ResultItemData.ItemMesh = ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].ItemMesh;
		ResultItemData.ItemIcon = ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].ItemIcon;
		ResultItemData.ArmorValue = FMath::RandRange(ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MinArmorValue,ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MaxArmorValue);
		ResultItemData.MinDamageValue = FMath::RandRange(ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MinMinDamageValue,ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MaxMinDamageValue);
		ResultItemData.MaxDamageValue = FMath::RandRange(ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MinMaxDamageValue,ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MaxMaxDamageValue);
		ResultItemData.BlockValue = FMath::RandRange(ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MinBlockValue,ItemDataAsset->ItemData.ItemRarityMap[ItemRarity].MaxBlockValue);
	}
	return ResultItemData;
}

void ISR_ItemDropperInterface::SpawnItems(TArray<FResultItemData> SpawnItems, AActor* ItemSpawner)
{
	if (ItemSpawner)
	{
		for (FResultItemData& SpawnItem : SpawnItems)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			ASR_ItemPickUp* ItemPickUp = ItemSpawner->GetWorld()->SpawnActor<ASR_ItemPickUp>(GetItemPickUpClass(), GetSpawnLocation(ItemSpawner), FRotator::ZeroRotator, SpawnParams);
			if (ItemPickUp)
			{
				ItemPickUp->Init(SpawnItem,ItemSpawner);
			}
		}
	}
}

FVector ISR_ItemDropperInterface::GetSpawnLocation(AActor* ItemSpawner)
{
	float Radius = FMath::RandRange(150.f,250.f);
	FVector Direction = FMath::VRand();
	Direction.Z = 0.0f;
	Direction = Direction.GetSafeNormal(0.0f);
	return ItemSpawner->GetActorLocation() + (Direction * Radius);
}
