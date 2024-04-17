// Copyright Spellbound Studios.


#include "Player/SR_PlayerState.h"

#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "AbilitySystem/SR_AttributeSet.h"

ASR_PlayerState::ASR_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<USR_AttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ASR_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
