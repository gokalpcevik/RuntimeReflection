// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeReflectionStruct.h"
#include "RuntimeReflectionPropertyHelper.h"

/**
 * 
 */
class RUNTIMEREFLECTION_API RuntimeReflectionStructHelper
{
public:
	RuntimeReflectionStructHelper();
	~RuntimeReflectionStructHelper();

	static TArray<URuntimeReflectionProperty*> GetPropertiesFromStruct(UStruct* pStruct, EFieldIterationFlags Flags);
	static URuntimeReflectionProperty* ConstructRuntimePropertyFromProperty(FProperty* pProperty);
	static TArray<URuntimeReflectionFunction*> GetFunctionsFromClass(UClass* pClass, EFieldIterationFlags Flags);
	static ERuntimeReflectionScriptStructType GetScriptStructType(UScriptStruct* pScriptStruct);
};
