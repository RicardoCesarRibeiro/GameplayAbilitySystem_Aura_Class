// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SR_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;

};



/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API USR_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	USR_AttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	

	/* Primary Attributes */
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vitality, Category = "Primary Attributes")
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Vitality);

	/* Secondary Attributes*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, MaxMana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegen, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, HealthRegen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpecialAbility, Category = "Secondary Attributes")
	FGameplayAttributeData SpecialAbility;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, SpecialAbility);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpecialAbilityRegen, Category = "Secondary Attributes")
	FGameplayAttributeData SpecialAbilityRegen;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, SpecialAbilityRegen);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, ArmorPenetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicArmor, Category = "Secondary Attributes")
	FGameplayAttributeData MagicArmor;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, MagicArmor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, BlockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_EvadeChance, Category = "Secondary Attributes")
	FGameplayAttributeData EvadeChance;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, EvadeChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, CriticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, CriticalHitDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MovementSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, MovementSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, AttackSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CooldownReduction, Category = "Secondary Attributes")
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, CooldownReduction);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PhysicalDamage, Category = "Secondary Attributes")
	FGameplayAttributeData PhysicalDamage;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, PhysicalDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicDamage, Category = "Secondary Attributes")
	FGameplayAttributeData MagicDamage;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, MagicDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FireDamage, Category = "Secondary Attributes")
	FGameplayAttributeData FireDamage;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, FireDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_LightningDamage, Category = "Secondary Attributes")
	FGameplayAttributeData LightningDamage;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, LightningDamage);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ColdDamage, Category = "Secondary Attributes")
	FGameplayAttributeData ColdDamage;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, ColdDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PickupRadius, Category = "Secondary Attributes")
	FGameplayAttributeData PickupRadius;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, PickupRadius);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ExperienceGain, Category = "Secondary Attributes")
	FGameplayAttributeData ExperienceGain;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, ExperienceGain);	

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DashDistance, Category = "Secondary Attributes")
	FGameplayAttributeData DashDistance;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, DashDistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DashCount, Category = "Secondary Attributes")
	FGameplayAttributeData DashCount;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, DashCount);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DashCooldown, Category = "Secondary Attributes")
	FGameplayAttributeData DashCooldown;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, DashCooldown);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AreaOfEffect, Category = "Secondary Attributes")
	FGameplayAttributeData AreaOfEffect;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, AreaOfEffect);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealingEffectiveness, Category = "Secondary Attributes")
	FGameplayAttributeData HealingEffectiveness;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, HealingEffectiveness);
	
	/* Vital Attributes */
	
	// Life and Max Life
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(USR_AttributeSet, Mana);

	/*-------------------------*/
	

	// Primary Attributes
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength)const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity)const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)const;

	UFUNCTION()
	void OnRep_Vitality(const FGameplayAttributeData& OldVitality)const;
	

	// Vital Attributes
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth)const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana)const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)const;	


	// Secondary Attributes
	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen)const;

	UFUNCTION()
	void OnRep_SpecialAbility(const FGameplayAttributeData& OldSpecialAbility)const;

	UFUNCTION()
	void OnRep_SpecialAbilityRegen(const FGameplayAttributeData& OldSpecialAbilityRegen)const;
	
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor)const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)const;

	UFUNCTION()
	void OnRep_MagicArmor(const FGameplayAttributeData& OldMagicArmor)const;
	
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance)const;
	
	UFUNCTION()
	void OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance)const;
	
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance)const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage)const;

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)const;

	UFUNCTION()
	void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)const;
	
	UFUNCTION()
	void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction)const;
	
	UFUNCTION()
	void OnRep_PhysicalDamage(const FGameplayAttributeData& OldPhysicalDamage)const;

	UFUNCTION()
	void OnRep_MagicDamage(const FGameplayAttributeData& OldMagicDamage)const;

	UFUNCTION()
	void OnRep_FireDamage(const FGameplayAttributeData& OldFireDamage)const;

	UFUNCTION()
	void OnRep_LightningDamage(const FGameplayAttributeData& OldLightningDamage)const;

	UFUNCTION()
	void OnRep_ColdDamage(const FGameplayAttributeData& OldColdDamage)const;

	UFUNCTION()
	void OnRep_PickupRadius(const FGameplayAttributeData& OldPickupRadius)const;
	
	UFUNCTION()
	void OnRep_ExperienceGain(const FGameplayAttributeData& OldExperienceGain)const;
	
	UFUNCTION()
	void OnRep_DashDistance(const FGameplayAttributeData& OldDashDistance)const;
	
	UFUNCTION()
	void OnRep_DashCount(const FGameplayAttributeData& OldDashCount)const;
	
	UFUNCTION()
	void OnRep_DashCooldown(const FGameplayAttributeData& OldDashCooldown)const;
	
	UFUNCTION()
	void OnRep_AreaOfEffect(const FGameplayAttributeData& OldAreaOfEffect)const;

	UFUNCTION()
	void OnRep_HealingEffectiveness(const FGameplayAttributeData& OldHealingEffectiveness)const;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};
