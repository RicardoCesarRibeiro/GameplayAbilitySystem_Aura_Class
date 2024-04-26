// Copyright Spellbound Studios.


#include "Player/SR_PlayerState.h"

#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "AbilitySystem/SR_AttributeSet.h"
#include "Net/UnrealNetwork.h"

ASr_PlayerState::ASr_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<USR_AttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

void ASr_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASr_PlayerState, Level);
	
}

UAbilitySystemComponent* ASr_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASr_PlayerState::OnRep_Level(int32 OldLevel)
{
	
}
