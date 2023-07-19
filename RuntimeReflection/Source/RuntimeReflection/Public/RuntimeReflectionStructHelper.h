// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeReflectionStruct.h"

/**
 * 
 */
class RUNTIMEREFLECTION_API RuntimeReflectionStructHelper
{
public:
	RuntimeReflectionStructHelper();
	~RuntimeReflectionStructHelper();

	static ERuntimeReflectionScriptStructType GetScriptStructType(UScriptStruct* pScriptStruct);
};
