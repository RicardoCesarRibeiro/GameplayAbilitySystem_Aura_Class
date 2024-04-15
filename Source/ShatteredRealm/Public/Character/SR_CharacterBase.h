// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SR_CharacterBase.generated.h"

UCLASS(Abstract)
class SHATTEREDREALM_API ASR_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASR_CharacterBase();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
	
};
