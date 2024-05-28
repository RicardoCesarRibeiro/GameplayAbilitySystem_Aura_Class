// Copyright Spellbound Studios.

#include "Actor/SR_Chests.h"
#include "ShatteredRealm/ShatteredRealms.h"
#include "Components/BoxComponent.h"


// Sets default values
ASR_Chests::ASR_Chests()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	if (BoxComponent)
	{
		RootComponent = BoxComponent;
		BoxComponent->SetCollisionProfileName(TEXT("BlockAll"));
		SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
		if (SkeletalMeshComponent)
		{
			SkeletalMeshComponent->SetupAttachment(BoxComponent);
			SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
	InteractRadius = 200.f;
	bIsOpened = false;
}

// Called when the game starts or when spawned
void ASR_Chests::BeginPlay()
{
	Super::BeginPlay();
	
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

TSubclassOf<ASR_ItemPickUp> ASR_Chests::GetItemPickUpClass()
{
	return ItemPickUpClass;
}

void ASR_Chests::Interact(APawn* InteractingPawn)
{
	DropItems(this);
	bIsOpened = true;
}

bool ASR_Chests::GetIsInteractable()
{
	return !bIsOpened;
}

float ASR_Chests::GetInteractRadius()
{
	return InteractRadius;
}

void ASR_Chests::HighlightActor()
{
	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->SetRenderCustomDepth(true);
		SkeletalMeshComponent->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void ASR_Chests::UnHighlightActor()
{
	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->SetRenderCustomDepth(false);
	}
}



