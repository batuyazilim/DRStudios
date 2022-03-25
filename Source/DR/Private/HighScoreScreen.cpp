// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreScreen.h"

#include "HighScoreGameGameInstance.h"
#include "HighScoreRowWidget.h"
#include "MyHighScoreGameGameplayStatics.h"
#include "MyUserWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"


void UHighScoreScreen::SetValues()
{
	RowContainer->ClearChildren();
	auto gameInstance = Cast<UHighScoreGameGameInstance>(GetWorld()->GetGameInstance());
	auto highScoreTable = gameInstance->GetHighScoreTableForSection();
	//auto highScoreTable = UMyHighScoreGameGameplayStatics::GetHighScoreTableForSection();
	for (int i = 0; i< highScoreTable.Num(); i++)
	{
		for (int j = i+1; j < highScoreTable.Num(); j++)
		{
			if(highScoreTable[j].Score > highScoreTable[i].Score)
			{
				highScoreTable.Swap(i,j);
			}
		}
	}
	for (auto i : highScoreTable)
	{
		auto *RowWidget = CreateWidget<UHighScoreRowWidget>(GetWorld(),HighScoreWidgetClass);
		if(RowWidget != nullptr)
		{
			RowContainer->AddChild(RowWidget);
			RowWidget->SetRow(i);
		}
	}
}

void UHighScoreScreen::IncreaseValue()
{
	ScoreCount += 10;
	Score->SetText(FText::AsNumber(ScoreCount));
}

void UHighScoreScreen::DecreaseValue()
{
	ScoreCount -= 10;
	Score->SetText(FText::AsNumber(ScoreCount));
}

void UHighScoreScreen::Finisgame()
{
	//UHighScoreGameGameInstance* GameInstanceRef = Cast<UHighScoreGameGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	auto gameInstance = Cast<UHighScoreGameGameInstance>(GetWorld()->GetGameInstance());
	gameInstance->SetHighScoreTableForSection(GetText->GetText().ToString(),FCString::Atof(*Score->GetText().ToString()));
	SetValues();
	ScoreCount = 0;
	Score->SetText(FText::AsNumber(0));
}
