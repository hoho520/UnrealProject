// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
DECLARE_DELEGATE(FAction);
DECLARE_DELEGATE_OneParam(FAction_bool, bool);
DECLARE_DELEGATE_OneParam(FAction_int32, int32)
DECLARE_DELEGATE_OneParam(FAction_float , float)
DECLARE_DELEGATE_OneParam(FAction_FString, FString);

class ESCAPE_API UIDeclareDelegates
{
public:
	
};
