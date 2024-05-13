// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SR_Projectile.generated.h"
class USphereComponent;
class UProjectileMovementComponent;


UCLASS()
class SHATTEREDREALM_API ASR_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASR_Projectile();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent>  ProjectileMovement;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor*OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
