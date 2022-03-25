// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreGameGameInstance.h"
TArray<FHighScoreEntry> Return;
FHighScoreEntry Entry;
TArray<FHighScoreEntry> UHighScoreGameGameInstance::GetHighScoreTableForSection()
{
	return  Return;
}

bool UHighScoreGameGameInstance::SetHighScoreTableForSection(FString DataName, int DataScore)
{
	
	auto highScoreTable = GetHighScoreTableForSection();
	int val = highScoreTable.Num();
	if (DataName == "")
	{
		return false;
	}
	bool temp = true;
	for (int i = 0; i< highScoreTable.Num(); i++)
	{
		if(highScoreTable[i].Name == DataName)
		{
			temp = false;
			if(DataScore > highScoreTable[i].Score)
			{
				Entry.Name=DataName;
				Entry.Score=DataScore;
				Return.Add(Entry);
				Return.RemoveAt(i);
				
			}
			return true;
		}
	}
	
	if(temp)
	{
		Entry.Name=DataName;
		Entry.Score=DataScore;
		Return.Add(Entry);
	}
	return true;
}
