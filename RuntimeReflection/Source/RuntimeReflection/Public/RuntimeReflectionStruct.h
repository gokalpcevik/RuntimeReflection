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

	UPROPERTY(BlueprintReadOnly)
	FString CPPName;

	UPROPERTY(BlueprintReadOnly)
	FString ScriptStructName;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsVector() const { return ScriptStructType == ERuntimeReflectionScriptStructType::Vector;  }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsVector2D() const { return ScriptStructType == ERuntimeReflectionScriptStructType::Vector2D; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsRotator() const { return ScriptStructType == ERuntimeReflectionScriptStructType::Rotator; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsTransform() const { return ScriptStructType == ERuntimeReflectionScriptStructType::Transform; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsQuat() const { return ScriptStructType == ERuntimeReflectionScriptStructType::Quaternion; }

	UScriptStruct* ScriptStruct = nullptr;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionFunction : public URuntimeReflectionStruct
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FString FunctionName;

	UPROPERTY(BlueprintReadOnly)
	URuntimeReflectionProperty* ReturnProperty;

	FProperty* ReturnPropertyUE = nullptr;
	UFunction* Function = nullptr;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionClass : public URuntimeReflectionStruct
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<URuntimeReflectionFunction*> Functions;
	
};
