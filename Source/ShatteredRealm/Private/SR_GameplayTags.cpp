// Copyright Spellbound Studios.


#include "SR_GameplayTags.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagsManager.h"

FSr_GameplayTags FSr_GameplayTags::GameplayTags;

void FSr_GameplayTags::InitializeNativeGameplayTags()
{
	/*
	// Primary Attributes
	*/
	
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Increases Physical Damage, Chance to Block and Physical Armor "));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Increases Magical Damage, Special Ability Regen and Magic Armor"));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Dexterity"), FString("Increases Attack Speed, Movement Speed and Chance to Evade"));
	GameplayTags.Attributes_Primary_Vitality = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vitality"), FString("Increases Maximum Health, Health Regen and Healing Effectiveness"));

	/*
	// Secondary Attributes
	*/
	
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Maximum Amount of Health"));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Maximum Amount of Mana"));
	GameplayTags.Attributes_Secondary_HealthRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegen"), FString("Amount of Health Regenerated every second"));
	GameplayTags.Attributes_Secondary_SpecialAbilityRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.SpecialAbilityRegen"), FString("Special Ability points Regenerated every second"));
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces Damage Taken from Physical Sources"));
	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Chance to ignore Enemy Armor"));
	GameplayTags.Attributes_Secondary_MagicArmor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MagicArmor"), FString("Reduces Damage Taken from Magical Sources"));
	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), FString("Chance to reduce damage taken by 75%"));
	GameplayTags.Attributes_Secondary_EvadeChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.EvadeChance"), FString("Chance to avoid damage taken"));
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("Chance to get a Critical Hit"));
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("Critical Hit Damage increase"));
	GameplayTags.Attributes_Secondary_MovementSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MovementSpeed"), FString("Increases Character movement speed"));
	GameplayTags.Attributes_Secondary_AttackSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.AttackSpeed"), FString("Increases how often the Character Attacks"));
	GameplayTags.Attributes_Secondary_CooldownReduction = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CooldownReduction"), FString("Reduces Global Cooldown"));
	GameplayTags.Attributes_Secondary_PhysicalDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PhysicalDamage"), FString("Increases your Physical Damage"));
	GameplayTags.Attributes_Secondary_MagicDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MagicDamage"), FString("Increases your Magic Damage"));
	GameplayTags.Attributes_Secondary_FireDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.FireDamage"), FString("Increases your Fire Damage"));
	GameplayTags.Attributes_Secondary_LightningDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.LightningDamage"), FString("Increases your Lightning Damage"));
	GameplayTags.Attributes_Secondary_ColdDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ColdDamage"), FString("Increases your Cold Damage"));
	GameplayTags.Attributes_Secondary_PickupRadius = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PickupRadius"), FString("Increases the distance to pick up Object"));
	GameplayTags.Attributes_Secondary_ExperienceGain = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ExperienceGain"), FString("Increases the amount of experience acquired"));
	GameplayTags.Attributes_Secondary_DashDistance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.DashDistance"), FString("Increases how far you can Dash"));
	GameplayTags.Attributes_Secondary_DashCount = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.DashCount"), FString("Increases how many times you can Dash in a row"));
	GameplayTags.Attributes_Secondary_DashCooldown = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.DashCooldown"), FString("Reduces the Dash recovery cooldown"));
	GameplayTags.Attributes_Secondary_AreaOfEffect = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.AreaOfEffect"), FString("Increases your Global Area of Effect"));
	GameplayTags.Attributes_Secondary_HealingEffectiveness = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealingEffectiveness"), FString("Increases your Global Healing Effectiveness"));



}
