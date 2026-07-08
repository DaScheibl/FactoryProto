// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUDBase.generated.h"

class UUserWidget;

UCLASS()
class MENUSYSTEM_API AMainMenuHUDBase : public AHUD
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