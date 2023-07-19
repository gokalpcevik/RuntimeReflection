// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RuntimeReflectionProperty.generated.h"

UENUM(Blueprintable)
enum class ERuntimeReflectionPropertyType : uint8
{
	None = 0,
	Int = 1,
	Int64,
	Byte,
	Bool,
	Float,
	String,
	Text,
	Name,
	Object,
	ScriptStruct
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionProperty : public UObject
{
public:
	GENERATED_BODY()

	URuntimeReflectionProperty(FObjectInitializer const& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	bool HasMetadata(FName const& Key);

	UPROPERTY(BlueprintReadOnly)
	UObject* Container;
	// Property Name
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	UPROPERTY(BlueprintReadOnly)
	int32 ArrayDim;
	UPROPERTY(BlueprintReadOnly)
	int32 ElementSize;

	// Due to the limitations of blueprints, we have to do it like this. Bit fields won't work and if we made them work with 8-bit unsigned
	// values, it would be the same as below. 
	// PropertyFlags[63:56]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte7;
	// PropertyFlags[55:48]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte6;
	// PropertyFlags[47:40]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte5;
	// PropertyFlags[39:32]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte4;
	// PropertyFlags[31:24]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte3;
	// PropertyFlags[23:16]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte2;
	// PropertyFlags[15:8]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte1;
	// PropertyFlags[7:0]
	UPROPERTY(BlueprintReadOnly)
	uint8 PropertyFlagsByte0;
	UPROPERTY(BlueprintReadOnly)
	ERuntimeReflectionPropertyType PropertyType;

	// For CPP only
	FProperty* Property;
	uint64 PropertyFlags;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionBoolProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	bool GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	bool GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(bool Value);

	FBoolProperty* BoolProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionByteProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	uint8 GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	uint8 GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(uint8 Value);

	FByteProperty* ByteProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionIntProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	int32 GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	int32 GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(int32 Value);

	UFUNCTION(BlueprintCallable)
	int32 GetIntMetaData(FName const& Key);

	FIntProperty* IntProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionInt64Property : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	int64 GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	int64 GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(int64 Value);

	UFUNCTION(BlueprintCallable)
	int64 GetIntMetaData(FName const& Key);

	FInt64Property* IntProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionFloatProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	float GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	float GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(float Value);

	UFUNCTION(BlueprintCallable)
	float GetFloatMetadata(FName const& Key);

	FFloatProperty* FloatProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionStringProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FString GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	FString GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(FString const& Value);

	FStrProperty* StringProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionTextProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FText GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	FText GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(FText const& Value);

	FTextProperty* TextProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionNameProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FName GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	FName GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(FName Value);

	FNameProperty* NameProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionObjectProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	UObject* GetDefaultValue();

	UFUNCTION(BlueprintCallable)
	UObject* GetValue();

	UFUNCTION(BlueprintCallable)
	void SetValue(UObject* Value);

	FObjectProperty* ObjectProperty;
};

UCLASS(BlueprintType)
class RUNTIMEREFLECTION_API URuntimeReflectionStructProperty : public URuntimeReflectionProperty
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<URuntimeReflectionProperty*> Properties;

	UScriptStruct* ScriptStruct;
	FStructProperty* StructProperty;
};