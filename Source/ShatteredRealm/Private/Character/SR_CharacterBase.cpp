// Copyright Spellbound Studios.


#include "../../Public/Character/SR_CharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/SR_AbilitySystemComponent.h"

ASr_CharacterBase::ASr_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ASr_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASr_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASr_CharacterBase::InitAbilityActorInfo()
{
	
}

void ASr_CharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	
}

void ASr_CharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void ASr_CharacterBase::AddCharacterAbilities()
{
	USR_AbilitySystemComponent* SrASC = CastChecked<USR_AbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	SrASC->AddCharacterAbilities(StartupAbilities);
	
}

