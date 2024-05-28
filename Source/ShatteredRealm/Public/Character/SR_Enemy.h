// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "SR_CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "Interaction/InteractableInterface.h"
#include "SR_Enemy.generated.h"


class UWidgetComponent;
/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API ASr_Enemy : public ASr_CharacterBase, public IEnemyInterface, public IInteractableInterface
{
	GENERATED_BODY()

public:
	ASr_Enemy();


	/** Interactable Interface */
	virtual void Interact(APawn* InteractingPawn) override;
	virtual bool GetIsInteractable() override;
	virtual float GetInteractRadius() override;
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** End Interactable Interface */

	/**Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/**End Combat Interface */

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	float BaseWalkSpeed = 350.f;

	

	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

	void HitReactTagChanged();

};
