// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHighScoreGameGameplayStatics.h"

#include "HighScoreGameGameInstance.h"

UHighScoreGameGameInstance* UMyHighScoreGameGameplayStatics::GetGameInstance(const UObject* WorldContextObject)
{
	
	auto gameInstance = WorldContextObject->GetWorld()->GetGameInstance();
	return Cast<UHighScoreGameGameInstance>(gameInstance);
}

TArray<FHighScoreEntry> UMyHighScoreGameGameplayStatics::GetHighScoreTableForSection()
{
	TArray<FHighScoreEntry> Return;
	FHighScoreEntry Entry;
	Entry.Name="Demo";
	Entry.Score=100;
	Return.Add(Entry);
	Entry.Name="Demo2";
	Entry.Score=200;
	Return.Add(Entry);
	
	return Return;
}
