// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SR_ItemDataAsset.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum  EItemSlot 
{
	IS_None		UMETA(DisplayName = "None"), 
	IS_Helmet	UMETA(DisplayName = "Helmet"),
	IS_Chest	UMETA(DisplayName = "Chest"),
	IS_Legs		UMETA(DisplayName = "Legs"),
	IS_Gloves	UMETA(DisplayName = "Gloves"),
	IS_Belt		UMETA(DisplayName = "Belt"),
	IS_Ring		UMETA(DisplayName = "Ring"),
	IS_Amulet	UMETA(DisplayName = "Amulet"),
	IS_MainHand	UMETA(DisplayName = "MainHand"),
	IS_OffHand	UMETA(DisplayName = "OffHand")
};

UENUM(BlueprintType)
enum  EItemType
{
// Armor
	IT_None				UMETA(DisplayName = "None"), 
	IT_Helmet_Light		UMETA(DisplayName = "Helmet (Light)"),
	IT_Helmet_Medium	UMETA(DisplayName = "Helmet (Medium)"),
	IT_Helmet_Heavy		UMETA(DisplayName = "Helmet (Heavy)"),
	IT_Gloves_Light		UMETA(DisplayName = "Gloves (Light)"),
	IT_Gloves_Medium	UMETA(DisplayName = "Gloves (Medium)"),
	IT_Gloves_Heavy		UMETA(DisplayName = "Gloves (Heavy)"),
	IT_Armor_Light		UMETA(DisplayName = "Armor (Light)"),
	IT_Armor_Medium		UMETA(DisplayName = "Armor (Medium)"),
	IT_Armor_Heavy		UMETA(DisplayName = "Armor (Heavy)"),
	IT_Boots_Light		UMETA(DisplayName = "Boots (Light)"),
	IT_Boots_Medium		UMETA(DisplayName = "Boots (Medium)"),
	IT_Boots_Heavy		UMETA(DisplayName = "Boots (Heavy)"),
// Weapons
	IT_Staff			UMETA(DisplayName = "Staff"),
	IT_ShortSword		UMETA(DisplayName = "Short Sword"),
	IT_TwoHanded_Sword	UMETA(DisplayName = "TwoHanded Sword"),
	IT_Axe				UMETA(DisplayName = "Axe"),
	IT_TwoHanded_Axe	UMETA(DisplayName = "TwoHanded Axe"),
	IT_Shortbow			UMETA(DisplayName = "Shortbow"),
	IT_Longbow			UMETA(DisplayName = "Longbow"),
	IT_Shield_Medium	UMETA(DisplayName = "Shield (Medium)"),
	IT_Shield_Heavy		UMETA(DisplayName = "Shield (Heavy)"),
	IT_Tome				UMETA(DisplayName = "Tome"),
	IT_Quiver			UMETA(DisplayName = "Quiver"),
	
// Jewellery and Belt
	IT_Amulet			UMETA(DisplayName = "Amulet"),
	IT_Ring				UMETA(DisplayName = "Ring"),
	IT_Belt				UMETA(DisplayName = "Belt")

};


UENUM(BlueprintType)
enum EItemRarity 
{
	IR_None			UMETA(DisplayName = "None"), 
	IR_Common		UMETA(DisplayName = "Common"),
	IR_Uncommon		UMETA(DisplayName = "Uncommon"),
	IR_Rare			UMETA(DisplayName = "Rare"),
	IR_Legendary	UMETA(DisplayName = "Legendary"),
	IR_Unique		UMETA(DisplayName = "Unique")
};


USTRUCT(BlueprintType)
struct FRarityData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* ItemMesh = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* ItemIcon = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MinArmorValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxArmorValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MinMinDamageValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxMinDamageValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MinMaxDamageValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxMaxDamageValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MinBlockValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxBlockValue = 0;
};

USTRUCT(BlueprintType)
struct FRollItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EItemType> ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EItemSlot> ItemSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<TEnumAsByte<EItemRarity>, FRarityData> ItemRarityMap;
	
};


USTRUCT(BlueprintType)
struct FResultItemData
{
	GENERATED_BODY()

//TODO: Generate Random Item Name
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EItemType> ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EItemSlot> ItemSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EItemRarity> ItemRarity;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ArmorValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MinDamageValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxDamageValue = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 BlockValue = 0;
	
};

UCLASS()
class SHATTEREDREALM_API USR_ItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	FRollItemData ItemData;
	
};
