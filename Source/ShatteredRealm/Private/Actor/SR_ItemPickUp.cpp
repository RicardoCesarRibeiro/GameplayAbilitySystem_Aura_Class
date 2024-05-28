// Copyright Spellbound Studios.


#include "Actor/SR_ItemPickUp.h"
#include "ShatteredRealm/ShatteredRealms.h"
#include "Character/SR_Character.h"
#include "UI/Inventory/InventoryComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ASR_ItemPickUp::ASR_ItemPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	if (BoxComponent)
	{
		RootComponent = BoxComponent;
		BoxComponent->SetCollisionProfileName(TEXT("IgnoreOnlyPawn"));
		StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
		if (StaticMeshComponent)
		{
			StaticMeshComponent->SetupAttachment(RootComponent);
			StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
	bIsInteractable = true;
	InteractRadius = 50;
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

void ASR_ItemPickUp::Init(FResultItemData ResultItemData, AActor* NewItemSpawner)
{
	ItemData = ResultItemData;
	ItemSpawner = NewItemSpawner;
	
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetStaticMesh(ItemData.ItemMesh);
	}
	PlayDropAnimation();
}

void ASR_ItemPickUp::Interact(APawn* InteractingPawn)
{
	if (ASr_Character* Character = Cast<ASr_Character>(InteractingPawn))
	{
		if (Character->InventoryComponent->AddItem(ItemData))
		{
			Destroy();
			bIsInteractable = false;
		}
		
	}
}

bool ASR_ItemPickUp::GetIsInteractable()
{
	return bIsInteractable;
}

float ASR_ItemPickUp::GetInteractRadius()
{
	return InteractRadius;
}

void ASR_ItemPickUp::HighlightActor()
{
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderCustomDepth(true);
		StaticMeshComponent->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void ASR_ItemPickUp::UnHighlightActor()
{
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderCustomDepth(false);
	}
}

