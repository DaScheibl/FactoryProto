#include "MainMenuHUDBase.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

void AMainMenuHUDBase::BeginPlay()
{
	Super::BeginPlay();

	if (!MainMenuClass)
	{
		return;
	}

	APlayerController* PC = GetOwningPlayerController();
	if (!PC)
	{
		return;
	}

	MainMenuWidget = CreateWidget<UUserWidget>(PC, MainMenuClass);
	if (!MainMenuWidget)
	{
		return;
	}

	MainMenuWidget->AddToViewport();

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(MainMenuWidget->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PC->SetInputMode(InputMode);

	PC->bShowMouseCursor = true;
}