// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyHighScoreGameGameplayStatics.h"

#include "Engine/GameInstance.h"
#include "HighScoreGameGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class DR_API UHighScoreGameGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	
	UFUNCTION(BlueprintPure, Category = "Game")
	static TArray<FHighScoreEntry> GetHighScoreTableForSection();

	UFUNCTION(BlueprintPure, Category = "Game")
	static bool SetHighScoreTableForSection(FString DataName,int DataScore);
	
};
