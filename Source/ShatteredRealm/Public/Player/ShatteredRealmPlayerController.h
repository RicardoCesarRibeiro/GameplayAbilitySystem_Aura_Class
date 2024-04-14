// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShatteredRealmPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API AShatteredRealmPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AShatteredRealmPlayerController();
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> ShatteredRealmContext;

};