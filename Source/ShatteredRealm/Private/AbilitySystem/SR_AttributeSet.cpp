// Copyright Spellbound Studios.


#include "AbilitySystem/SR_AttributeSet.h"
#include "Net/UnrealNetwork.h"

USR_AttributeSet::USR_AttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
	
}

void USR_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USR_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}
// Health
void USR_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)const

{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, Health, OldHealth);
}

void USR_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const

{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USR_AttributeSet, MaxHealth, OldMaxHealth);
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