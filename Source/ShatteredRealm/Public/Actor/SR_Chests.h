// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/ItemDropperInterface.h"
#include "SR_Chests.generated.h"

class USR_DropPoolDataAsset;

UCLASS()
class SHATTEREDREALM_API ASR_Chests : public AActor, public ISR_ItemDropperInterface
{
	GENERATED_BODY()
	
public:	

	ASR_Chests();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USR_DropPoolDataAsset* DropPoolDataAsset;

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	
	virtual USR_DropPoolDataAsset* GetDropPoolDataAsset() override;
};
