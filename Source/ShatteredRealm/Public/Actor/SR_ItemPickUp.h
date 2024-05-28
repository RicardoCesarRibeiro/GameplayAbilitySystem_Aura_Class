// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/InteractableInterface.h"
#include "Items/SR_ItemDataAsset.h"
#include "SR_ItemPickUp.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class SHATTEREDREALM_API ASR_ItemPickUp : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:
	
	ASR_ItemPickUp();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComponent;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadOnly)
	FResultItemData ItemData;

	UPROPERTY(BlueprintReadOnly)
	AActor* ItemSpawner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsInteractable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InteractRadius;
	
	void Init(FResultItemData ResultItemData, AActor* NewItemSpawner);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayDropAnimation();

	virtual void Interact(APawn* InteractingPawn) override;
	virtual bool GetIsInteractable() override;
	virtual float GetInteractRadius() override;
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
};
