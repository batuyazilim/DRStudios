// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HighScoreScreen.generated.h"

/**
 * 
 */
UCLASS()
class DR_API UHighScoreScreen : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	int ScoreCount;
public:
	
	UFUNCTION(BlueprintCallable)
	void SetValues();
	UFUNCTION(BlueprintCallable)
	void IncreaseValue();
	UFUNCTION(BlueprintCallable)
	void DecreaseValue();
	UFUNCTION(BlueprintCallable)
	void Finisgame();
	

	/*UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* TopName;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* TopScore;
	*/
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UEditableTextBox* GetText;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* Score;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UVerticalBox* RowContainer;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "High Score")
	TSubclassOf<class UHighScoreRowWidget> HighScoreWidgetClass;

};
