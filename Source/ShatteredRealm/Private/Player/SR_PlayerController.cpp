// Copyright Spellbound Studios.


#include "..\..\Public\Player\SR_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Input/SR_InputComponent.h"
#include "Interaction/EnemyInterface.h"

ASr_PlayerController::ASr_PlayerController()
{
	bReplicates = true;
}

void ASr_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
	
}

void ASr_PlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
	
	if(LastActor == nullptr)
	{
		if (ThisActor!= nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			// Case A - Both are null, do nothing
		}
	}	
	else //LastActor is valid
	{
		if (ThisActor ==nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}	
		else // Both Actors are valid
		{
			if (LastActor!= ThisActor)
			{
				// Case D

				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}	
	}
}

void ASr_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	
}

void ASr_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	
}

void ASr_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	
}


void ASr_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(SRContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(SRContext,0);
	}
	
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
}

void ASr_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	USR_InputComponent* SrInputComponent = CastChecked<USR_InputComponent>(InputComponent);
	SrInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASr_PlayerController::Move);
	SrInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ASr_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

