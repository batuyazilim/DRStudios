// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreRowWidget.h"

#include "Components/TextBlock.h"

void UHighScoreRowWidget::SetRow(FHighScoreEntry RowData)
{
	Name->SetText(FText::FromString(RowData.Name));
	Score->SetText(FText::AsNumber(RowData.Score));
	
}
