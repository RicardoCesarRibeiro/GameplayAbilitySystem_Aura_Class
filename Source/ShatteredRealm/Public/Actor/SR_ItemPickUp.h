// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/SR_ItemDataAsset.h"
#include "SR_ItemPickUp.generated.h"


UCLASS()
class SHATTEREDREALM_API ASR_ItemPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASR_ItemPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadOnly)
	FResultItemData ItemData;

	void Init(FResultItemData ResultItemData);
	UFUNCTION(BlueprintImplementableEvent)
	void Test();
	
};
