// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RuntimeReflectionProperty.h"
#include "RuntimeReflectionStruct.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionStruct : public UObject
{
public:
	GENERATED_BODY()

	// Properties are common for all UStructs; i.e. UClass, UScriptStruct, UFunction
	UPROPERTY(BlueprintReadOnly)
	TArray<URuntimeReflectionProperty*> Properties;

	UObject* Container = nullptr;
};

UENUM(Blueprintable)
enum class ERuntimeReflectionScriptStructType : uint8
{
	None = 0,
	Vector,
	Vector2D,
	IntVector,
	Rotator,
	Quaternion,
	Transform,
	Other = 255
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionScriptStruct : public URuntimeReflectionStruct
{
public:
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	ERuntimeReflectionScriptStructType ScriptStructType = ERuntimeReflectionScriptStructType::None;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionFunction : public URuntimeReflectionStruct
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 ParameterCount;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionClass : public URuntimeReflectionStruct
{
public:
	GENERATED_BODY()

};
