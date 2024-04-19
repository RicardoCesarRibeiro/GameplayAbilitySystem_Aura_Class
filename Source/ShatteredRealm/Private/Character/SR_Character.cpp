// Copyright Spellbound Studios.


#include "..\..\Public\Character\SR_Character.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SR_PlayerController.h"
#include "Player/SR_PlayerState.h"
#include "UI/HUD/SR_HUD.h"

ASR_Character::ASR_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f, 0.f );
	GetCharacterMovement()->bConstrainToPlane=true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
}

void ASR_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	// Init ability actor info for the Server
	InitAbilityActorInfo();

}

void ASR_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	// Init ability actor info for the client
	InitAbilityActorInfo();
	
}

void ASR_Character::InitAbilityActorInfo()
{
	ASR_PlayerState* Sr_PlayerState =GetPlayerState<ASR_PlayerState>();
	check(Sr_PlayerState);
	Sr_PlayerState->GetAbilitySystemComponent()-> InitAbilityActorInfo(Sr_PlayerState, this);
	AbilitySystemComponent= Sr_PlayerState->GetAbilitySystemComponent();
	AttributeSet = Sr_PlayerState->GetAttributeSet();

	if (ASR_PlayerController*Sr_PlayerController = Cast<ASR_PlayerController>(GetController()))
	{
		if(ASR_HUD* Sr_HUD = Cast<ASR_HUD>(Sr_PlayerController->GetHUD()))
		{
			Sr_HUD->InitOverlay(Sr_PlayerController, Sr_PlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	
}


