// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeReflectionBPLibrary.h"
#include "RuntimeReflection.h"

#define INIT_BASE_RT_PROPERTY(RuntimeProperty, UnrealProperty) RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables((RuntimeProperty), (UnrealProperty))

URuntimeReflectionClass* URuntimeReflectionBPLibrary::CreateRuntimeReflectionClassFromObject(UObject* Container, ERuntimeReflectionFieldIterationFlags Flags)
{
	verify(Container != nullptr);

	UClass* Class = Container->GetClass();

	URuntimeReflectionClass* ReflClass = NewObject<URuntimeReflectionClass>();

	// Set the properties from the helper function
	ReflClass->Properties = RuntimeReflectionStructHelper::GetPropertiesFromStruct(Class, (EFieldIterationFlags)Flags);
	// Set the functions from the helper function. This function also sets all function's parameter properties and the return property.
	ReflClass->Functions = RuntimeReflectionStructHelper::GetFunctionsFromClass(Class, (EFieldIterationFlags)Flags);
	return ReflClass;
}

URuntimeReflectionScriptStruct* URuntimeReflectionBPLibrary::CreateRuntimeReflectionScriptStructFromStructProperty(URuntimeReflectionStructProperty* Property, ERuntimeReflectionFieldIterationFlags Flags)
{
	verify(Property != nullptr);
	URuntimeReflectionScriptStruct* pScriptStruct = NewObject<URuntimeReflectionScriptStruct>();
	pScriptStruct->ScriptStruct = Property->ScriptStruct;
	pScriptStruct->CPPName =  Property->ScriptStruct->GetStructCPPName();
	Property->ScriptStruct->GetName(pScriptStruct->ScriptStructName);
	pScriptStruct->Properties = RuntimeReflectionStructHelper::GetPropertiesFromStruct(Property->ScriptStruct, (EFieldIterationFlags)Flags);
	pScriptStruct->ScriptStructType = RuntimeReflectionStructHelper::GetScriptStructType(pScriptStruct->ScriptStruct);
	return pScriptStruct;
}
