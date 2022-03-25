// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyHighScoreGameGameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "HighScoreRowWidget.generated.h"

/**
 * 
 */
UCLASS()
class DR_API UHighScoreRowWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* Name;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* Score;
	
public:
	UFUNCTION(BlueprintCallable)
	void SetRow(FHighScoreEntry RowData);
};
