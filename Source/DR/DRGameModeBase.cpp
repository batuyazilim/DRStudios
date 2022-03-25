// Copyright Epic Games, Inc. All Rights Reserved.


#include "DRGameModeBase.h"

#include "HighScoreScreen.h"
#include "MyUserWidget.h"
#include "Blueprint/UserWidget.h"

void ADRGameModeBase::BeginPlay()
{
	
	Super::BeginPlay();
	
	HighScoreWidget = CreateWidget<UHighScoreScreen>(GetWorld(),WidgetClass);
	if(HighScoreWidget != nullptr)
	{
		HighScoreWidget->AddToViewport();
	}
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	//ShowCursor(true);
}
