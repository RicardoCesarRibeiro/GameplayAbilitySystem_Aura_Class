// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_Enemy.h"

#include "..\..\ShatteredRealm\ShatteredRealms.h"
#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "AbilitySystem/SR_AttributeSet.h"

ASR_Enemy::ASR_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<USR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<USR_AttributeSet>("AttributeSet");
}

void ASR_Enemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue((CUSTOM_DEPTH_RED));
}

void ASR_Enemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void ASR_Enemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

}
