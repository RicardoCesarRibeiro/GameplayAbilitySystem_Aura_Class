// Copyright Spellbound Studios.


#include "UI/Inventory/ItemInventory.h"
#include "Items/SR_ItemDataAsset.h"


UItemInventory::UItemInventory()
{
	
}

void UItemInventory::Init(FResultItemData NewItemData)
{
	ItemData = NewItemData;
}
