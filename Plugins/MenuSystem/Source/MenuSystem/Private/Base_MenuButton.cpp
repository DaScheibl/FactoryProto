// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_MenuButton.h"
#include "CommonTextBlock.h"

void UBase_MenuButton::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (CT_ButtonText)
	{
		CT_ButtonText->SetText(ButtonText);
	}
}
