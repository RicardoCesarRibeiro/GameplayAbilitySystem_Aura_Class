// Copyright Spellbound Studios.


#include "Actor/SR_EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/SR_AttributeSet.h"
#include "Components/SphereComponent.h"


ASR_EffectActor::ASR_EffectActor()
{
	
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	
}

void ASR_EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: CHANGE THIS TO APPLY A GAMEPLAY EFFECT. For now, using const_cast as a HACK!
	if (IAbilitySystemInterface* ASR_Interface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const USR_AttributeSet* Usr_AttributeSet = Cast<USR_AttributeSet>(ASR_Interface->GetAbilitySystemComponent()->GetAttributeSet(USR_AttributeSet::StaticClass()));
		
		USR_AttributeSet* MutableSrAttributeSet = const_cast<USR_AttributeSet*>(Usr_AttributeSet);
		MutableSrAttributeSet->SetHealth(Usr_AttributeSet->GetHealth() +25.f);
		Destroy();
		
	}

}

void ASR_EffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


void ASR_EffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASR_EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ASR_EffectActor::EndOverlap);
}

