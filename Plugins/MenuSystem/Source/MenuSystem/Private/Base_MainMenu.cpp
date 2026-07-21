#include "Base_MainMenu.h"
#include "Base_ConfirmationDialoge.h"
#include "Base_MenuButton.h"    
#include "Kismet/KismetSystemLibrary.h"

void UBase_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (MB_Quit)
	{
		MB_Quit->OnClicked().AddUObject(this, &UBase_MainMenu::OnQuitButtonClicked);
	}
}

UBase_ConfirmationDialoge* UBase_MainMenu::GetDialogue()
{
	// Entspricht dem IsValid-Branch: nur erzeugen, wenn noch nicht vorhanden
	if (!IsValid(ConfirmationDialogue))
	{
		if (ConfirmationDialogueClass)
		{
			ConfirmationDialogue = CreateWidget<UBase_ConfirmationDialoge>(
				GetOwningPlayer(), ConfirmationDialogueClass);
		}
	}

	return ConfirmationDialogue;
}

void UBase_MainMenu::OnQuitButtonClicked()
{
	UBase_ConfirmationDialoge* Dialogue = GetDialogue();
	if (!Dialogue)
	{
		return;
	}

	Dialogue->ShowDialogue(QuitMessage);

	// Main-Menu während des Dialogs nicht anklickbar (Not Hit-Testable, Self & All Children)
	SetVisibility(ESlateVisibility::HitTestInvisible);

	// Erst alle alten Bindungen lösen, dann neu binden (wie im Blueprint)
	Dialogue->InputDispatch.Clear();
	Dialogue->InputDispatch.AddDynamic(this, &UBase_MainMenu::OnQuitConfirmation);
}

void UBase_MainMenu::OnQuitConfirmation(bool YesNo)
{
	// Main-Menu wieder sichtbar/anklickbar
	SetVisibility(ESlateVisibility::Visible);

	if (YesNo)
	{
		UKismetSystemLibrary::QuitGame(
			this, GetOwningPlayer(), EQuitPreference::Quit, false);
	}
}