// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Slate/Public/Widgets/Views/SListView.h"
#include "Widgets/Views/STileView.h"
#include "SScrollBar.h"
#include "Widgets/Views/STableViewBase.h"

template <typename Type>
class ESCAPE_API SCustomListView : public SListView<Type>
{
public:
	void SetScrollbarVisibility(ESlateVisibility InUserVisibility)
	{
		switch (InUserVisibility)
		{
		case ESlateVisibility::Visible:
			STableViewBase::ScrollBar->SetUserVisibility(EVisibility::Visible);
			break;
		case ESlateVisibility::Collapsed:
			STableViewBase::ScrollBar->SetUserVisibility(EVisibility::Collapsed);
			break;
		case ESlateVisibility::Hidden:
			STableViewBase::ScrollBar->SetUserVisibility(EVisibility::Hidden);
			break;
		case ESlateVisibility::HitTestInvisible:
			STableViewBase::ScrollBar->SetUserVisibility(EVisibility::HitTestInvisible);
			break;
		case ESlateVisibility::SelfHitTestInvisible:
			STableViewBase::ScrollBar->SetUserVisibility(EVisibility::SelfHitTestInvisible);
			break;
		default:
			break;
		}
	}
};

template <typename Type>
class ESCAPE_API SCustomTileView : public STileView<Type>
{
public:

	void SetScrollBarVisibility(ESlateVisibility NewVisibility)
	{
		if (this->ScrollBar.IsValid())
		{
			switch (NewVisibility)
			{
			case ESlateVisibility::Visible:
				this->ScrollBar->SetUserVisibility(EVisibility::Visible);
				break;
			case ESlateVisibility::Collapsed:
				this->ScrollBar->SetUserVisibility(EVisibility::Collapsed);
				break;
			case ESlateVisibility::Hidden:
				this->ScrollBar->SetUserVisibility(EVisibility::Hidden);
				break;
			case ESlateVisibility::HitTestInvisible:
				this->ScrollBar->SetUserVisibility(EVisibility::HitTestInvisible);
				break;
			case ESlateVisibility::SelfHitTestInvisible:
				this->ScrollBar->SetUserVisibility(EVisibility::SelfHitTestInvisible);
				break;
			default:
				break;
			}
		}
	}
};

