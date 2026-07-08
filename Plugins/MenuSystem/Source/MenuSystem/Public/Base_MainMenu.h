#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Base_MainMenu.generated.h"

UCLASS()
class MENUSYSTEM_API UBase_MainMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
};