// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_Character.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SR_PlayerController.h"
#include "Player/SR_PlayerState.h"
#include "UI/HUD/SR_HUD.h"
#include "UI/Inventory/InventoryComponent.h"

ASr_Character::ASr_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f, 0.f );
	GetCharacterMovement()->bConstrainToPlane=true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory Component"));

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
}

void ASr_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	// Init ability actor info for the Server
	InitAbilityActorInfo();
	AddCharacterAbilities();

}

void ASr_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	// Init ability actor info for the client
	InitAbilityActorInfo();
	
}

int32 ASr_Character::GetPlayerLevel()
{
	const ASr_PlayerState* Sr_PlayerState =GetPlayerState<ASr_PlayerState>();
	check(Sr_PlayerState);
	return Sr_PlayerState->GetPlayerLevel();
}

void ASr_Character::InitAbilityActorInfo()
{
	ASr_PlayerState* Sr_PlayerState =GetPlayerState<ASr_PlayerState>();
	check(Sr_PlayerState);
	Sr_PlayerState->GetAbilitySystemComponent()-> InitAbilityActorInfo(Sr_PlayerState, this);
	Cast<USR_AbilitySystemComponent>(Sr_PlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent= Sr_PlayerState->GetAbilitySystemComponent();
	AttributeSet = Sr_PlayerState->GetAttributeSet();

	if (ASr_PlayerController*Sr_PlayerController = Cast<ASr_PlayerController>(GetController()))
	{
		if(ASr_HUD* Sr_HUD = Cast<ASr_HUD>(Sr_PlayerController->GetHUD()))
		{
			Sr_HUD->InitOverlay(Sr_PlayerController, Sr_PlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	InitializeDefaultAttributes();
	
}


