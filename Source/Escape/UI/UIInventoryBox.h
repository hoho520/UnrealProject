// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIDeclareDelegates.h"
#include "Blueprint/UserWidget.h"
#include "UIInventoryBox.generated.h"

/**
 인벤토리 박스 클래스
 */
class UTileView;
class UButton;
UCLASS()
class ESCAPE_API UUIInventoryBox : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	// 닫기 버튼 이벤크 델리게이트 정의
	void SetCloseEventDelegate(FAction NewDelegate) { CloseEventDelegate = NewDelegate; }
	// 인벤토리 슬롯 위젯 추가
	void AddInventorySlot();
	// 인벤토리 리프레시
	void RefreshTileView();
	// 닫기 이벤트
	UFUNCTION()
	void Close();

protected:
	UPROPERTY(EditInstanceOnly)
	TSubclassOf<UUserWidget> InvenSlotClass;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTileView* InvenTileView;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* CloseBtn;

private:
	FAction CloseEventDelegate;
};
