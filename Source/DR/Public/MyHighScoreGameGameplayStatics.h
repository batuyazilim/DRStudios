// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyHighScoreGameGameplayStatics.generated.h"

USTRUCT(BlueprintType)
struct FHighScoreEntry
{
	GENERATED_BODY()
public:
	FString Name;
	int Score;
};
/**
 * 
 */
UCLASS()
class DR_API UMyHighScoreGameGameplayStatics : public UObject
{
	GENERATED_BODY()
	UFUNCTION(BlueprintPure, Category = "Game", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static class UHighScoreGameGameInstance* GetGameInstance(const UObject* WorldContextObject);
public:
	UFUNCTION(BlueprintPure, Category = "Game")
	static TArray<FHighScoreEntry> GetHighScoreTableForSection();
};
