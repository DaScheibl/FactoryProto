// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_MenuButton.h"
#include "CommonTextBlock.h"

void UBase_MenuButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	UpdateButtonText();
}

void UBase_MenuButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	UpdateButtonText();
}

void UBase_MenuButton::UpdateButtonText()
{
	if (CT_ButtonText)
	{
		CT_ButtonText->SetText(ButtonText);
	}
}
