// Copyright Spellbound Studios.


#include "UI/Widget/SR_UserWidget.h"

void USR_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
