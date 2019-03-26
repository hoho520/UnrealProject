// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TileView.h"
#include "UI/CustomWidget/SCustomListView.h"
#include "EscapeTileView.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API UEscapeTileView : public UTileView
{
	GENERATED_BODY()

public:
	virtual void ReleaseSlateResources(bool bReleaseChildren) override
	{
		UTileView::ReleaseSlateResources(bReleaseChildren);

		MyTileView.Reset();
	}

protected:
	virtual TSharedRef<STableViewBase> RebuildListWidget() override
	{
		return ConstructTileView<SCustomTileView>();
	}

	/** STileView construction helper - useful if using a custom STileView subclass */
	template <template<typename> class TileViewT = SCustomTileView>
	TSharedRef<TileViewT<UObject*>> ConstructTileView()
	{
		MyTileView = ITypedUMGListView<UObject*>::ConstructTileView<TileViewT>(this, ListItems, TileAlignment, EntryHeight, EntryWidth, SelectionMode, bClearSelectionOnClick, bWrapHorizontalNavigation, ConsumeMouseWheel);
		MyTileView->SetScrollBarVisibility(ScrollBarVisibility);
		return StaticCastSharedRef<TileViewT<UObject*>>(MyTileView.ToSharedRef());
	}

public:
	// 스크롤바 표시 유무
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScrollBar")
	ESlateVisibility ScrollBarVisibility;

protected:
	TSharedPtr<SCustomTileView<UObject*>> MyTileView;

};
