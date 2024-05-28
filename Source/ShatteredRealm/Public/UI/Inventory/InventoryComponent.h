// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItemInventory;
struct FResultItemData;
struct FCombinableKey;

USTRUCT(BlueprintType)
struct FStorageLocation
{
	GENERATED_BODY()

	FStorageLocation()
	{
		Row = 0;
		Column = 0;
	}
	
	FStorageLocation(int32 InRow, int32 InColumn)
	{
		Row = InRow;
		Column = InColumn;
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Row;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Column;
	
	bool operator==(const FStorageLocation& Other) const
	{
		return Row == Other.Row && Column == Other.Column;
	}
};

FORCEINLINE uint32 GetTypeHash(const FStorageLocation& Key)
{
	return HashCombine(GetTypeHash(Key.Row), GetTypeHash(Key.Column));
}

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHATTEREDREALM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxStorageRows;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxStorageColumns;

	UPROPERTY(BlueprintReadOnly)
	TMap<FStorageLocation, UItemInventory*> ItemStorageMap;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool AddItem(FResultItemData NewItem);
	bool AddItem(FResultItemData NewItem, int32 Row, int32 Column);
	bool FindNextAvailableStorageLocation(FStorageLocation& StorageLocation);
};
