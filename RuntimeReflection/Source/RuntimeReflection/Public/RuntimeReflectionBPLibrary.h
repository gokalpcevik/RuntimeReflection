// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RuntimeReflectionHelperMacros.h"
#include "RuntimeReflectionProperty.h"
#include "RuntimeReflectionStruct.h"
#include "RuntimeReflectionStructHelper.h"
#include "RuntimeReflectionPropertyHelper.h"
#include "RuntimeReflectionBPLibrary.generated.h"

UENUM(Blueprintable)
enum class ERuntimeReflectionFieldIterationFlags : uint8
{
	None = 0,
	IncludeSuper = 1 << 0,		// Include super class
	IncludeDeprecated = 1 << 1,	// Include deprecated properties
	IncludeInterfaces = 1 << 2,	// Include interfaces
	IncludeAll = IncludeSuper | IncludeDeprecated | IncludeInterfaces,
	Default = IncludeSuper | IncludeDeprecated,
};

UCLASS()
class URuntimeReflectionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static URuntimeReflectionClass* CreateRuntimeReflectionClassFromObject(UObject* Container,ERuntimeReflectionFieldIterationFlags Flags);

	UFUNCTION(BlueprintCallable)
	static URuntimeReflectionScriptStruct* CreateRuntimeReflectionScriptStructFromStructProperty(URuntimeReflectionStructProperty* Property, ERuntimeReflectionFieldIterationFlags Flags);

};
