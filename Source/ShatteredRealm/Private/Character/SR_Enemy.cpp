// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_Enemy.h"

#include "..\..\ShatteredRealm\ShatteredRealms.h"

ASR_Enemy::ASR_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
