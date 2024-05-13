// Copyright Spellbound Studios.


#include "AbilitySystem/Abilities/SR_ProjectileSpell.h"

#include "Actor/SR_Projectile.h"
#include "Interaction/CombatInterface.h"


void USR_ProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                          const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void USR_ProjectileSpell::SpawnProjectile()
{
	
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;


	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		//TODO: Set the projectile Rotation
		
		ASR_Projectile* Projectile = GetWorld()->SpawnActorDeferred<ASR_Projectile>(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		//TODO: Give the Projectile a GP Effect Spec for causing Damage.
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}
