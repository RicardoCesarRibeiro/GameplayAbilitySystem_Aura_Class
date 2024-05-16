// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SR_GameplayAbility.h"
#include "SR_ProjectileSpell.generated.h"

class ASR_Projectile;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API USR_ProjectileSpell : public USR_GameplayAbility
{
	GENERATED_BODY()

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& ProjectileTargetLocation);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<ASR_Projectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
