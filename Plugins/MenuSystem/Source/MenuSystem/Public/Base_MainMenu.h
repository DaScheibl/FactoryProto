#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Base_MainMenu.generated.h"

class UBase_MenuButton; 
class UBase_ConfirmationDialoge;

UCLASS()
class MENUSYSTEM_API UBase_MainMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBase_MenuButton> MB_Quit;

	// Lazy-erzeugte Dialog-Instanz (entspricht der Variable WBP_ConfirmationDialogue)
	UPROPERTY()
	TObjectPtr<UBase_ConfirmationDialoge> ConfirmationDialogue;

	// Klasse, die instanziiert wird — im Editor auf WBP_ConfirmationDialogue setzen
	UPROPERTY(EditDefaultsOnly, Category = "Confirmation Dialogue")
	TSubclassOf<UBase_ConfirmationDialoge> ConfirmationDialogueClass;

	// "Quit Message" — im Editor editierbarer Text
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Confirmation Dialogue")
	FText QuitMessage;

	// Lazy-Getter (entspricht der Funktion GetDialogue)
	UBase_ConfirmationDialoge* GetDialogue();

	UFUNCTION()
	void OnQuitButtonClicked();

	UFUNCTION()
	void OnQuitConfirmation(bool YesNo);
};