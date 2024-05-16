// Copyright Spellbound Studios.


#include "AbilitySystem/SR_AttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
#include "SR_GameplayTags.h"

USR_AttributeSet::USR_AttributeSet()
{
	const FSr_GameplayTags& GameplayTags = FSr_GameplayTags::Get();
	

	/* Primary Attributes */
	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Strength, GetStrengthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Intelligence, GetIntelligenceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Dexterity, GetDexterityAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Vitality, GetVitalityAttribute);

	/* Secondary Attributes */

	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Armor, GetArmorAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_ArmorPenetration, GetArmorPenetrationAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_AttackSpeed, GetAttackSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_BlockChance, GetBlockChanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_ColdDamage, GetColdDamageAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_CooldownReduction, GetCooldownReductionAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_DashCooldown, GetDashCooldownAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_DashCount, GetDashCountAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_DashDistance, GetDashDistanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_EvadeChance, GetEvadeChanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_ExperienceGain, GetExperienceGainAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_FireDamage, GetFireDamageAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_HealingEffectiveness, GetHealingEffectivenessAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_HealthRegen, GetHealthRegenAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_LightningDamage, GetLightningDamageAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_MagicArmor, GetMagicArmorAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_MagicDamage, GetMagicDamageAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_MaxHealth, GetMaxHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_MaxMana, GetMaxManaAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_MovementSpeed, GetMovementSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_PhysicalDamage, GetPhysicalDamageAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_PickupRadius, GetPickupRadiusAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_AreaOfEffect, GetAreaOfEffectAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_CriticalHitChance, GetCriticalHitChanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_CriticalHitDamage, GetCriticalHitDamageAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Secondary_SpecialAbilityRegen, GetSpecialAbilityAttribute);
	
}

void USR_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Primary Attributes
	
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Vitality, COND_None, REPNOTIFY_Always);

	
	// Secondary Attributes

	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, HealthRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, SpecialAbilityRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MagicArmor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, EvadeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, CooldownReduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, PhysicalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MagicDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, FireDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, LightningDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, ColdDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, PickupRadius, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, ExperienceGain, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, DashDistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, DashCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, DashCooldown, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, AreaOfEffect, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, HealingEffectiveness, COND_None, REPNOTIFY_Always);
	

	// Vital Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, SpecialAbility, COND_None, REPNOTIFY_Always);
	
}
// Clamp on PreAttributeChange

void USR_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if(Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}


void USR_AttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = Causer of the Effect
	// Target = Target of the Effect (Owner of this AttributeSet)
	
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void USR_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
		UE_LOG(LogTemp, Warning, TEXT("Changed Health on %s, Health: %f"), *Props.TargetAvatarActor->GetName(),GetHealth());
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}


// Primary Attributes

void USR_AttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Strength, OldStrength);
}
void USR_AttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Dexterity, OldDexterity);
}
void USR_AttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Intelligence, OldIntelligence);
}
void USR_AttributeSet::OnRep_Vitality(const FGameplayAttributeData& OldVitality) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Vitality, OldVitality);
}


// Secondary Attributes

void USR_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, MaxHealth, OldMaxHealth);
}
void USR_AttributeSet::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, HealthRegen, OldHealthRegen);
}
void USR_AttributeSet::OnRep_SpecialAbility(const FGameplayAttributeData& OldSpecialAbility) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, SpecialAbility, OldSpecialAbility);
}	
void USR_AttributeSet::OnRep_SpecialAbilityRegen(const FGameplayAttributeData& OldSpecialAbilityRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, SpecialAbilityRegen, OldSpecialAbilityRegen);
}
void USR_AttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Armor, OldArmor);
}
void USR_AttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, ArmorPenetration, OldArmorPenetration);
}
void USR_AttributeSet::OnRep_MagicArmor(const FGameplayAttributeData& OldMagicArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, MagicArmor, OldMagicArmor);
}
void USR_AttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, BlockChance, OldBlockChance);
}
void USR_AttributeSet::OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, EvadeChance, OldEvadeChance);
}
void USR_AttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, CriticalHitChance, OldCriticalHitChance);
}
void USR_AttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, CriticalHitDamage, OldCriticalHitDamage);
}
void USR_AttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, MovementSpeed, OldMovementSpeed);
}
void USR_AttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, AttackSpeed, OldAttackSpeed);
}
void USR_AttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, CooldownReduction, OldCooldownReduction);
}
void USR_AttributeSet::OnRep_PhysicalDamage(const FGameplayAttributeData& OldPhysicalDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, PhysicalDamage, OldPhysicalDamage);
}
void USR_AttributeSet::OnRep_MagicDamage(const FGameplayAttributeData& OldMagicDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, MagicDamage, OldMagicDamage);
}
void USR_AttributeSet::OnRep_FireDamage(const FGameplayAttributeData& OldFireDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, FireDamage, OldFireDamage);
}
void USR_AttributeSet::OnRep_LightningDamage(const FGameplayAttributeData& OldLightningDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, LightningDamage, OldLightningDamage);
}
void USR_AttributeSet::OnRep_ColdDamage(const FGameplayAttributeData& OldColdDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, ColdDamage, OldColdDamage);
}
void USR_AttributeSet::OnRep_PickupRadius(const FGameplayAttributeData& OldPickupRadius) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, PickupRadius, OldPickupRadius);
}
void USR_AttributeSet::OnRep_ExperienceGain(const FGameplayAttributeData& OldExperienceGain) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, ExperienceGain, OldExperienceGain);
}
void USR_AttributeSet::OnRep_DashDistance(const FGameplayAttributeData& OldDashDistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, DashDistance, OldDashDistance);
}
void USR_AttributeSet::OnRep_DashCount(const FGameplayAttributeData& OldDashCount) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, DashCount, OldDashCount);
}
void USR_AttributeSet::OnRep_DashCooldown(const FGameplayAttributeData& OldDashCooldown) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, DashCooldown, OldDashCooldown);
}
void USR_AttributeSet::OnRep_AreaOfEffect(const FGameplayAttributeData& OldAreaOfEffect) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, AreaOfEffect, OldAreaOfEffect);
}
void USR_AttributeSet::OnRep_HealingEffectiveness(const FGameplayAttributeData& OldHealingEffectiveness) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, HealingEffectiveness, OldHealingEffectiveness);
}
// Health
void USR_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)const

{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Health, OldHealth);
}

// Mana
void USR_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)const

{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Mana, OldMana);
}

void USR_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const

{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, MaxMana, OldMaxMana);
}


