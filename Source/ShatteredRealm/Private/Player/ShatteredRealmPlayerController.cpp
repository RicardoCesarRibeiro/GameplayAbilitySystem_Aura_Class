// Copyright Spellbound Studios.


#include "..\..\Public\Player\ShatteredRealmPlayerController.h"

#include "EnhancedInputSubsystems.h"

AShatteredRealmPlayerController::AShatteredRealmPlayerController()
{
	bReplicates = true;
}

void AShatteredRealmPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(ShatteredRealmContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(ShatteredRealmContext,0);
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
}