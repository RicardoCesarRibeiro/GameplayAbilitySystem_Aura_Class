// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_Enemy.h"

#include "..\..\ShatteredRealm\ShatteredRealms.h"
#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "AbilitySystem/SR_AttributeSet.h"

ASr_Enemy::ASr_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<USR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<USR_AttributeSet>("AttributeSet");
}

void ASr_Enemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue((CUSTOM_DEPTH_RED));
}

void ASr_Enemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 ASr_Enemy::GetPlayerLevel()
{
	return Level;
}

void ASr_Enemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();

}

void ASr_Enemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<USR_AbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();


	
}
