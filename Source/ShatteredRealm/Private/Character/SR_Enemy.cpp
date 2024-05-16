// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_Enemy.h"

#include "..\..\ShatteredRealm\ShatteredRealms.h"
#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "AbilitySystem/SR_AbilitySystemLibrary.h"
#include "AbilitySystem/SR_AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "UI/Widget/SR_UserWidget.h"

ASr_Enemy::ASr_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<USR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<USR_AttributeSet>("AttributeSet");

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

void ASr_Enemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue((CUSTOM_DEPTH_RED));
}

void ASr_Enemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 ASr_Enemy::GetPlayerLevel()
{
	return Level;
}

void ASr_Enemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();

	//Set WidgetController
	if (USR_UserWidget* SrUserWidget = Cast<USR_UserWidget>(HealthBar->GetUserWidgetObject()))
	{
		SrUserWidget->SetWidgetController(this);
	}
	// Bind Health change Delegates
	if(const USR_AttributeSet* Sr_AS = Cast<USR_AttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Sr_AS->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Sr_AS->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);
		
		OnHealthChanged.Broadcast(Sr_AS->GetHealth());
		OnMaxHealthChanged.Broadcast(Sr_AS->GetMaxHealth());
	}
	
}

void ASr_Enemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<USR_AbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	
	InitializeDefaultAttributes();
}

void ASr_Enemy::InitializeDefaultAttributes() const
{
	USR_AbilitySystemLibrary::InitializeDefaultAttributes(this, CharacterClass, Level, AbilitySystemComponent);
}
