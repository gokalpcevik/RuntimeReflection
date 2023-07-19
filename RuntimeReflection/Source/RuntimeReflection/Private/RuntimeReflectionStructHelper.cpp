// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeReflectionStructHelper.h"

RuntimeReflectionStructHelper::RuntimeReflectionStructHelper()
{
}

RuntimeReflectionStructHelper::~RuntimeReflectionStructHelper()
{
}

TArray<URuntimeReflectionProperty*> RuntimeReflectionStructHelper::GetPropertiesFromStruct(UStruct* pStruct, EFieldIterationFlags Flags)
{
	verify(pStruct != nullptr);

	TArray<URuntimeReflectionProperty*> Properties;

	for (FProperty* pProperty : TFieldRange<FProperty>(pStruct, Flags))
	{
		Properties.Add(ConstructRuntimePropertyFromProperty(pProperty));
	}

	return Properties;
}

URuntimeReflectionProperty* RuntimeReflectionStructHelper::ConstructRuntimePropertyFromProperty(FProperty* pProperty)
{
	// Function's return properties can be null, so if this function is called to construct a return property, just return null.
	if(pProperty == nullptr)
		return nullptr;

	FIntProperty* IntProperty = CastField<FIntProperty>(pProperty);
	if (IntProperty)
	{
		URuntimeReflectionIntProperty* pRTIntProperty = NewObject<URuntimeReflectionIntProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTIntProperty, pProperty);
		pRTIntProperty->PropertyType = ERuntimeReflectionPropertyType::Int;
		return pRTIntProperty;
	}

	FInt64Property* Int64Property = CastField<FInt64Property>(pProperty);
	if (Int64Property)
	{
		URuntimeReflectionInt64Property* pRTInt64Property = NewObject<URuntimeReflectionInt64Property>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTInt64Property, pProperty);
		pRTInt64Property->PropertyType = ERuntimeReflectionPropertyType::Int64;
		return pRTInt64Property;
	}

	FByteProperty* ByteProperty = CastField<FByteProperty>(pProperty);
	if (ByteProperty)
	{
		URuntimeReflectionByteProperty* pRTByteProperty = NewObject<URuntimeReflectionByteProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTByteProperty, pProperty);
		pRTByteProperty->PropertyType = ERuntimeReflectionPropertyType::Byte;
		return pRTByteProperty;
	}

	FBoolProperty* BoolProperty = CastField<FBoolProperty>(pProperty);
	if (BoolProperty)
	{
		URuntimeReflectionBoolProperty* pRTBoolProperty = NewObject<URuntimeReflectionBoolProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTBoolProperty, pProperty);
		pRTBoolProperty->PropertyType = ERuntimeReflectionPropertyType::Bool;
		return pRTBoolProperty;
	}

	FFloatProperty* FloatProperty = CastField<FFloatProperty>(pProperty);
	if (FloatProperty)
	{
		URuntimeReflectionFloatProperty* pRTFloatProperty = NewObject<URuntimeReflectionFloatProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTFloatProperty, pProperty);
		pRTFloatProperty->PropertyType = ERuntimeReflectionPropertyType::Float;
		return pRTFloatProperty;
	}

	FStrProperty* StrProperty = CastField<FStrProperty>(pProperty);
	if (StrProperty)
	{
		URuntimeReflectionStringProperty* pRTStrProperty = NewObject<URuntimeReflectionStringProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTStrProperty, pProperty);
		pRTStrProperty->PropertyType = ERuntimeReflectionPropertyType::String;
		return pRTStrProperty;
	}

	FNameProperty* NameProperty = CastField<FNameProperty>(pProperty);
	if (NameProperty)
	{
		URuntimeReflectionNameProperty* pRTNameProperty = NewObject<URuntimeReflectionNameProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTNameProperty, pProperty);
		pRTNameProperty->PropertyType = ERuntimeReflectionPropertyType::Name;
		return pRTNameProperty;
	}

	FTextProperty* TextProperty = CastField<FTextProperty>(pProperty);
	if (TextProperty)
	{
		URuntimeReflectionTextProperty* pRTTextProperty = NewObject<URuntimeReflectionTextProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTTextProperty, pProperty);
		pRTTextProperty->PropertyType = ERuntimeReflectionPropertyType::Text;
		return pRTTextProperty;
	}

	FObjectProperty* ObjectProperty = CastField<FObjectProperty>(pProperty);
	if (ObjectProperty)
	{
		URuntimeReflectionObjectProperty* pRTObjectProperty = NewObject<URuntimeReflectionObjectProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTObjectProperty, pProperty);
		pRTObjectProperty->PropertyType = ERuntimeReflectionPropertyType::Object;
		return pRTObjectProperty;
	}

	FStructProperty* StructProperty = CastField<FStructProperty>(pProperty);

	if (StructProperty)
	{
		URuntimeReflectionStructProperty* pRTStructProperty = NewObject<URuntimeReflectionStructProperty>();
		RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTStructProperty, pProperty);
		pRTStructProperty->StructProperty = StructProperty;
		pRTStructProperty->ScriptStruct = StructProperty->Struct;
		pRTStructProperty->PropertyType = ERuntimeReflectionPropertyType::ScriptStruct;
		return pRTStructProperty;
	}

	URuntimeReflectionProperty* pRTBaseProperty = NewObject<URuntimeReflectionProperty>();
	RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(pRTBaseProperty, pProperty);
	pRTBaseProperty->PropertyType = ERuntimeReflectionPropertyType::Other;

	return pRTBaseProperty;
}

TArray<URuntimeReflectionFunction*> RuntimeReflectionStructHelper::GetFunctionsFromClass(UClass* pClass,
                                                                                         EFieldIterationFlags Flags)
{
	TArray<URuntimeReflectionFunction*> Functions;

	for (UFunction* pFunc : TFieldRange<UFunction>(pClass, Flags))
	{
		URuntimeReflectionFunction* pReflFunc = NewObject<URuntimeReflectionFunction>();
		// Parameters
		pReflFunc->Properties = GetPropertiesFromStruct(pFunc, Flags);
		// UFunction*
		pReflFunc->Function = pFunc;
		// Function Name
		pFunc->GetName(pReflFunc->FunctionName);
		// Return property; FProperty*
		pReflFunc->ReturnPropertyUE = pFunc->GetReturnProperty();
		// Return property for exposing to BPs; URuntimeReflectionProperty*
		pReflFunc->ReturnProperty = ConstructRuntimePropertyFromProperty(pReflFunc->ReturnPropertyUE);
		Functions.Add(pReflFunc);
	}

	return Functions;
}


ERuntimeReflectionScriptStructType RuntimeReflectionStructHelper::GetScriptStructType(UScriptStruct* pScriptStruct)
{
	verify(pScriptStruct != nullptr);
	ERuntimeReflectionScriptStructType Type = ERuntimeReflectionScriptStructType::Other;

	if (pScriptStruct == TBaseStructure<FVector>::Get())
	{
		Type = ERuntimeReflectionScriptStructType::Vector;
	}
	else if (pScriptStruct == TBaseStructure<FVector2D>::Get())
	{
		Type = ERuntimeReflectionScriptStructType::Vector2D;
	}
	else if (pScriptStruct == TBaseStructure<FRotator>::Get())
	{
		Type = ERuntimeReflectionScriptStructType::Rotator;
	}
	else if (pScriptStruct == TBaseStructure<FQuat>::Get())
	{
		Type = ERuntimeReflectionScriptStructType::Quaternion;
	}
	else if (pScriptStruct == TBaseStructure<FTransform>::Get())
	{
		Type = ERuntimeReflectionScriptStructType::Transform;
	}
	return(Type);
}
