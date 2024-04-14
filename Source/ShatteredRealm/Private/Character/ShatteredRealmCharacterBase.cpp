// Copyright Spellbound Studios.


#include "..\..\Public\Character\SRCharacterBase.h"

AShatteredRealmCharacterBase::AShatteredRealmCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AShatteredRealmCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

