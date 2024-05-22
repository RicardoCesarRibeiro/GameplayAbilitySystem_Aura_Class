// Copyright Spellbound Studios.


#include "Actor/SR_ItemPickUp.h"

// Sets default values
ASR_ItemPickUp::ASR_ItemPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASR_ItemPickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASR_ItemPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASR_ItemPickUp::Init(FResultItemData ResultItemData)
{
	ItemData = ResultItemData;
	Test();
}

