// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HW08_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();
	
	// UMG 위젯 클래스를 에디터에서 할당받을 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> HUDWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD")
	UUserWidget* HUDWidgetInstance;

	// 메뉴 UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Menu")
	UUserWidget* MainMenuWidgetInstance;
		
	UFUNCTION(BlueprintPure, Category = "HUD")
	UUserWidget* GetHUDWidget() const;

	// HUD 표시
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void ShowGameHUD();
	// 메인 메뉴 표시
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowMainMenu(bool bIsRestart);
	// 게임 시작
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void StartGame();

protected:
	virtual void BeginPlay() override;
};
