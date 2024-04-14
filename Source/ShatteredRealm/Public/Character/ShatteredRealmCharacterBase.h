// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShatteredRealmCharacterBase.generated.h"

UCLASS(Abstract)
class ShatteredRealm_API AShatteredRealmCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AShatteredRealmCharacterBase();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
