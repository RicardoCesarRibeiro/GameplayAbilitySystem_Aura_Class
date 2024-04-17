// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_CharacterBase.h"

ASR_CharacterBase::ASR_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ASR_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASR_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

