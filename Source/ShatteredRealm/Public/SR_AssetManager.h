// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SR_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API USR_AssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	
	static USR_AssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
