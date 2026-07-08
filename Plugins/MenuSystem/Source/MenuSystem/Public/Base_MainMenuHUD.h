// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Base_MainMenuHUD.generated.h"

class UUserWidget;

UCLASS()
class MENUSYSTEM_API ABase_MainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MenuSystem")
	TSubclassOf<UUserWidget> MainMenuClass;

private:
	UPROPERTY()
	TObjectPtr<UUserWidget> MainMenuWidget;
};