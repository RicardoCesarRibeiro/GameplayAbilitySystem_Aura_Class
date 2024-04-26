// Copyright Spellbound Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widget/SR_UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "SR_HUD.generated.h"

/**
 * 
 */
UCLASS()
class SHATTEREDREALM_API ASr_HUD : public AHUD
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	TObjectPtr<USR_UserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OverlayWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
