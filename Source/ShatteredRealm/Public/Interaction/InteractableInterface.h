// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHATTEREDREALM_API IInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Interact(APawn* InteractingPawn) = 0;
	virtual float GetInteractRadius() = 0;
	virtual bool GetIsInteractable() = 0;
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
