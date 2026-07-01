// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FactoryGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FACTORY_API AFactoryGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void StartPlay() override;
	
};
