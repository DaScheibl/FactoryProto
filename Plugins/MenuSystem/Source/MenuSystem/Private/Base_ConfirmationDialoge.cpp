#include "Base_ConfirmationDialoge.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Animation/WidgetAnimation.h"
#include "TimerManager.h"
#include "Base_MenuButton.h"
#include "CommonTextBlock.h"

void UBase_ConfirmationDialoge::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (FadeIn)
	{
		PlayAnimation(FadeIn, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f);
	}
}

void UBase_ConfirmationDialoge::NativeConstruct()
{
	Super::NativeConstruct();
	
	Button_Yes->OnClicked().AddUObject(this, &UBase_ConfirmationDialoge::OnButtonYesClicked);
	Button_No->OnClicked().AddUObject(this, &UBase_ConfirmationDialoge::OnButtonNoClicked);
}

void UBase_ConfirmationDialoge::ShowDialogue(FText Message)
{
	if (CT_Message)
	{
		CT_Message->SetText(Message);
	}

	AddToViewport();
}

void UBase_ConfirmationDialoge::OnButtonYesClicked()
{
	InputDispatch.Broadcast(true);
	CloseDialogue();
}

void UBase_ConfirmationDialoge::OnButtonNoClicked()
{
	InputDispatch.Broadcast(false);
	CloseDialogue();
}

void UBase_ConfirmationDialoge::CloseDialogue()
{
	if (!FadeIn)
	{
		RemoveFromParent();
		return;
	}

	// FadeIn rückwärts abspielen
	PlayAnimation(FadeIn, 0.0f, 1, EUMGSequencePlayMode::Reverse, 1.0f);

	// Delay = Länge der Animation (entspricht GetEndTime im Blueprint), dann entfernen
	const float Duration = FadeIn->GetEndTime();

	FTimerHandle RemoveTimer;
	GetWorld()->GetTimerManager().SetTimer(
		RemoveTimer,
		this,
		&UBase_ConfirmationDialoge::RemoveDialogue,
		Duration,
		false);
}

void UBase_ConfirmationDialoge::RemoveDialogue()
{
	RemoveFromParent();
}