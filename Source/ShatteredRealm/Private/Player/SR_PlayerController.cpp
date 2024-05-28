// Copyright Spellbound Studios.


#include "..\..\Public\Player\SR_PlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "SR_GameplayTags.h"
#include "AbilitySystem/SR_AbilitySystemComponent.h"
#include "Components/SplineComponent.h"
#include "Input/SR_InputComponent.h"
#include "Interaction/EnemyInterface.h"
#include "Interaction/InteractableInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

ASr_PlayerController::ASr_PlayerController()
{
	bReplicates = true;
	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

void ASr_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	AutoRun();
}

void ASr_PlayerController::AutoRun()
{
	if (!bAutoRunning) return;
	if (APawn* ControlledPawn = GetPawn())
	{
		const FVector LocationOnSpline = Spline->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
		const FVector Direction = Spline->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World );
		ControlledPawn->AddMovementInput(Direction);

		const float DistanceToDestination = (LocationOnSpline - CacheDestination).Length();
		if (DistanceToDestination <= AutoRunningAcceptanceRadius)
		{
			bAutoRunning = false;
			if (TargetInteractable)
			{
				TargetInteractable->Interact(ControlledPawn);
				TargetInteractable = nullptr;
			}
		}
	}
}

void ASr_PlayerController::CursorTrace()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastHoverInteractable = CurrentHoverInteractable;
    IInteractableInterface* Interactable = Cast<IInteractableInterface>(CursorHit.GetActor());
    if (Interactable && Interactable->GetIsInteractable())
    {
        CurrentHoverInteractable = Interactable;
    }
    else
    {
        CurrentHoverInteractable = nullptr;
    }
	
	if(LastHoverInteractable != CurrentHoverInteractable)
	{
		if (LastHoverInteractable)
		{
			LastHoverInteractable->UnHighlightActor();
		}
		if (CurrentHoverInteractable)
		{
			CurrentHoverInteractable->HighlightActor();
		}
	}
}

void ASr_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.MatchesTagExact(FSr_GameplayTags::Get().InputTag_LMB))
	{
		TargetInteractable = false;
		
		if (CurrentHoverInteractable && CurrentHoverInteractable->GetIsInteractable())
		{
			// Clicking on a Non Enemy
			if (!UKismetSystemLibrary::DoesImplementInterface(CurrentHoverInteractable->_getUObject(), UEnemyInterface::StaticClass()))
			{
				TargetInteractable = CurrentHoverInteractable;
			}
		}
	}
}

void ASr_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FSr_GameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
		return;
	}

	if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
	
	if (!bTargeting && !bShiftKeyDown)
	{
		const APawn* ControlledPawn = GetPawn();
		if (FollowTime <= ShortPressThreshold && ControlledPawn)
		{

			// Interactable Pathing
			if (AActor* TargetActor = Cast<AActor>(TargetInteractable))
			{
				FVector TargetDirection = (GetPawn()->GetActorLocation() - TargetActor->GetActorLocation()).GetSafeNormal(0.0f); 
				CacheDestination = TargetActor->GetActorLocation() + (TargetDirection * TargetInteractable->GetInteractRadius());
//				Debug Sphere
//				UKismetSystemLibrary::DrawDebugSphere(this, CacheDestination, 50.f,12.f, FLinearColor::Red, 5.f, 2.f);
			}
	
			
			if (UNavigationPath * NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CacheDestination ))
			{
				Spline->ClearSplinePoints();
				for (const FVector& PointLoc : NavPath->PathPoints)
				{
					Spline->AddSplinePoint(PointLoc, ESplineCoordinateSpace::World);
				}
				CacheDestination = NavPath->PathPoints[NavPath->PathPoints.Num() -1];
				bAutoRunning = true;
			}	
		}
		FollowTime = 0.f;
		bTargeting = false;
	}
}

void ASr_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FSr_GameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
		return;
	}

	if (bTargeting || bShiftKeyDown)
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
	}
	else
	{
		FollowTime += GetWorld()->GetDeltaSeconds();
		if (CursorHit.bBlockingHit) CacheDestination = CursorHit.ImpactPoint;

		if (APawn* ControlledPawn = GetPawn())
		{
			const FVector WorldDirection = (CacheDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection);
		}
	}
}

USR_AbilitySystemComponent* ASr_PlayerController::GetASC()
{
	if (Sr_AbilitySystemComponent == nullptr)
	{
		Sr_AbilitySystemComponent = Cast<USR_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return Sr_AbilitySystemComponent;
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
	SrInputComponent->BindAction(ShiftAction, ETriggerEvent::Started, this, &ASr_PlayerController::ShiftPressed);
	SrInputComponent->BindAction(ShiftAction, ETriggerEvent::Completed, this, &ASr_PlayerController::ShiftReleased);
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
		if (bAutoRunning) bAutoRunning = false;
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

