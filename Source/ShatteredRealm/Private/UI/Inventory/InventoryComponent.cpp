// Copyright Spellbound Studios.


#include "UI/Inventory/InventoryComponent.h"
#include "Items/SR_ItemDataAsset.h"
#include "UI/Inventory/ItemInventory.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxStorageRows = 3;
	MaxStorageColumns = 5;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventoryComponent::AddItem(FResultItemData NewItem)
{
	FStorageLocation StorageLocation;
	if (FindNextAvailableStorageLocation(StorageLocation))
	{
		return AddItem(NewItem, StorageLocation.Row, StorageLocation.Column);
	}
	return false;
}

bool UInventoryComponent::AddItem(FResultItemData NewItem, int32 Row, int32 Column)
{
	FStorageLocation StorageLocation = FStorageLocation(Row, Column);
	UItemInventory* ItemInventory = NewObject<UItemInventory>();
	ItemInventory->Init(NewItem);
	if (ItemStorageMap.Contains(StorageLocation))
	{
			// Drag and Drop Swap.	
	}
	else
	{
		ItemStorageMap.Add(StorageLocation, ItemInventory);
	}
	return true;
}

bool UInventoryComponent::FindNextAvailableStorageLocation(FStorageLocation& StorageLocation)
{
	for (int32 r = 0; r < MaxStorageRows; r++)
	{
		for (int32 c = 0; c < MaxStorageColumns; c++)
		{
			if (!ItemStorageMap.Contains(FStorageLocation(r, c)) || !ItemStorageMap[FStorageLocation(r, c)])
			{
				StorageLocation.Row = r;
				StorageLocation.Column = c;
				return true;
			}
		}
	}
	return false;
	
	/*for (const TPair<FStorageLocation, UItemInventory*>& StorageSpace : ItemStorageMap)
	{
		
	}*/
}


