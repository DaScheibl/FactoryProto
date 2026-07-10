// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Base_ConfirmationDialoge.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;
class UWidgetAnimation;

// Event Dispatcher: entspricht "InputDispatch" mit dem bool-Param "Yes/No"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputDispatchSignature, bool, YesNo);

UCLASS()
class MENUSYSTEM_API UBase_ConfirmationDialoge : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Entspricht dem Event Dispatcher "InputDispatch" im Blueprint
	UPROPERTY(BlueprintAssignable, Category = "Confirmation Dialogue")
	FInputDispatchSignature InputDispatch;

	// Ändert nur den angezeigten Text und fügt das Widget dem Viewport hinzu
	UFUNCTION(BlueprintCallable, Category = "Confirmation Dialogue")
	void ShowDialogue(FText Message);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Yes;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_No;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CT_Message;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> FadeIn;

	UFUNCTION()
	void OnButtonYesClicked();

	UFUNCTION()
	void OnButtonNoClicked();

private:
	// Gemeinsame Fade-Reverse-Kette für beide Buttons
	void CloseDialogue();

	UFUNCTION()
	void RemoveDialogue();
};