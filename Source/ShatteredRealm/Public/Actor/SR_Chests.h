// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/InteractableInterface.h"
#include "Interaction/ItemDropperInterface.h"
#include "SR_Chests.generated.h"

class UBoxComponent;
class USR_DropPoolDataAsset;
class ASR_ItemPickUp;
class USkeletalMeshComponent;
class UBoxComponent;
class UInteractableInterface;

UCLASS()
class SHATTEREDREALM_API ASR_Chests : public AActor, public ISR_ItemDropperInterface, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	

	ASR_Chests();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USR_DropPoolDataAsset* DropPoolDataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ASR_ItemPickUp> ItemPickUpClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InteractRadius;
	
	virtual void Interact(APawn* InteractingPawn) override;
	virtual bool GetIsInteractable() override;
	virtual float GetInteractRadius() override;
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	
protected:

	virtual void BeginPlay() override;
	

public:	

	virtual void Tick(float DeltaTime) override;
	
	virtual USR_DropPoolDataAsset* GetDropPoolDataAsset() override;
	virtual TSubclassOf<ASR_ItemPickUp> GetItemPickUpClass() override;

private:

	bool bIsOpened;
	
	
};
