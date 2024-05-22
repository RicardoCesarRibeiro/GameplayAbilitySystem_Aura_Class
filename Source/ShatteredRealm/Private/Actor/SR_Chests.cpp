// Copyright Spellbound Studios.

#include "Actor/SR_Chests.h"



// Sets default values
ASR_Chests::ASR_Chests()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASR_Chests::BeginPlay()
{
	Super::BeginPlay();
	DropItems(GetActorLocation(), this);
	
}

// Called every frame
void ASR_Chests::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

USR_DropPoolDataAsset* ASR_Chests::GetDropPoolDataAsset()
{
	return DropPoolDataAsset;
}



