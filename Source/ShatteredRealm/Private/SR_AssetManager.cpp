// Copyright Spellbound Studios.


#include "SR_AssetManager.h"
#include "SR_GameplayTags.h"

USR_AssetManager& USR_AssetManager::Get()
{
	check(GEngine);
	
	USR_AssetManager* SrAssetManager = Cast<USR_AssetManager>(GEngine->AssetManager);
	return *SrAssetManager;
}

void USR_AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FSr_GameplayTags::InitializeNativeGameplayTags();	
}
