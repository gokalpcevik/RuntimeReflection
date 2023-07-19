// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeReflectionProperty.h"

/**
 * 
 */
class RUNTIMEREFLECTION_API RuntimeReflectionPropertyHelper
{
public:
	RuntimeReflectionPropertyHelper();
	~RuntimeReflectionPropertyHelper();

	static void InitializeBaseVariablesFromUnrealProperty(URuntimeReflectionProperty* pRuntimeProperty, FProperty* pUnrealProperty, UObject* pOwner);
};
