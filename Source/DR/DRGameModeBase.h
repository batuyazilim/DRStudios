// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HighScoreScreen.h"
#include "GameFramework/GameModeBase.h"
#include "DRGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DR_API ADRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category="Class Types")
	TSubclassOf<class UHighScoreScreen> WidgetClass;
	
	UPROPERTY(VisibleAnywhere, Category="Score")
	class UHighScoreScreen* HighScoreWidget;
	
	virtual void BeginPlay() override;
};
