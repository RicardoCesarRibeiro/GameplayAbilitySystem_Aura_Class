// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SRPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class ShatteredRealm_API AShatteredRealmPlayerController : public APlayerController
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