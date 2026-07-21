// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Base_MenuButton.generated.h"

class UCommonTextBlock;
/**
 * 
 */
UCLASS()
class MENUSYSTEM_API UBase_MenuButton : public UCommonButtonBase
{
	GENERATED_BODY()
	
	protected:
	virtual void NativePreConstruct() override;
	virtual void SynchronizeProperties() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> CT_ButtonText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MenuButton")
	FText ButtonText;
	
private:
	void UpdateButtonText();
};
