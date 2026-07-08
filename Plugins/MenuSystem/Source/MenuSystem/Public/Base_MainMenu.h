#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BaseMainMenu.generated.h"

UCLASS()
class MENUSYSTEM_API UBaseMainMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
};