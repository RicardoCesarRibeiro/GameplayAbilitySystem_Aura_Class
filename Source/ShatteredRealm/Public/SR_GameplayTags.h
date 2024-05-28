// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include  "GameplayTagContainer.h"


/**
 *  SrGameplayTags
 *
 *  Singleton containing native Gameplay Tags
 */

struct FSr_GameplayTags
{
public:
    static const FSr_GameplayTags& Get() { return GameplayTags; }
    static void InitializeNativeGameplayTags();
	
	/*
	// Primary Attributes
	*/
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Vitality;
	/*
	// Secondary Attributes
	*/
    FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_HealthRegen;
	FGameplayTag Attributes_Secondary_SpecialAbilityRegen;
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_MagicArmor;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_EvadeChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_MovementSpeed;
	FGameplayTag Attributes_Secondary_AttackSpeed;
	FGameplayTag Attributes_Secondary_CooldownReduction;
	FGameplayTag Attributes_Secondary_PhysicalDamage;
	FGameplayTag Attributes_Secondary_MagicDamage;
	FGameplayTag Attributes_Secondary_FireDamage;
	FGameplayTag Attributes_Secondary_LightningDamage;
	FGameplayTag Attributes_Secondary_ColdDamage;
	FGameplayTag Attributes_Secondary_PickupRadius;
	FGameplayTag Attributes_Secondary_ExperienceGain;
	FGameplayTag Attributes_Secondary_DashDistance;
	FGameplayTag Attributes_Secondary_DashCount;
	FGameplayTag Attributes_Secondary_DashCooldown;
	FGameplayTag Attributes_Secondary_AreaOfEffect;
	FGameplayTag Attributes_Secondary_HealingEffectiveness;
	/*
	// Input Tags
	*/
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_SPC;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
	/*
	// Item Slots
	*/
	FGameplayTag Item_Slot_Head;
	FGameplayTag Item_Slot_Chest;
	FGameplayTag Item_Slot_Gloves;
	FGameplayTag Item_Slot_Legs;
	FGameplayTag Item_Slot_Belt;
	FGameplayTag Item_Slot_MainHand;
	FGameplayTag Item_Slot_OffHand;
	FGameplayTag Item_Slot_TwoHanded;
	FGameplayTag Item_Slot_Neck;
	FGameplayTag Item_Slot_Ring;
	/*
	// Item FX
	*/
	FGameplayTag Item_FX_Fire;
	FGameplayTag Item_FX_Ice;
	FGameplayTag Item_FX_Lightning;
	FGameplayTag Item_FX_Magic;
	/*
	// Game Tags
	*/
	FGameplayTag Damage;
	FGameplayTag Effects_HitReact;
	FGameplayTag Effects_Death;


private:
	
    static FSr_GameplayTags GameplayTags;
 
};