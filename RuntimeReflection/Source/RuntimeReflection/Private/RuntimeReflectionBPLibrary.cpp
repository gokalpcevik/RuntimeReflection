// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeReflectionBPLibrary.h"
#include "RuntimeReflection.h"

URuntimeReflectionClass* URuntimeReflectionBPLibrary::CreateRuntimeReflectionClassFromObject(UObject* Container, ERuntimeReflectionFieldIterationFlags Flags)
{
	verify(Container != nullptr);

	UClass* Class = Container->GetClass();
	URuntimeReflectionClass* ReflClass = NewObject<URuntimeReflectionClass>();
	ReflClass->Container = Container;

	for (FProperty* pProperty : TFieldRange<FProperty>(Class, static_cast<EFieldIterationFlags>(Flags)))
	{
		FIntProperty* IntProperty = CastField<FIntProperty>(pProperty);
		if (IntProperty)
		{
			URuntimeReflectionIntProperty* pRTIntProperty = NewObject<URuntimeReflectionIntProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTIntProperty, pProperty, Container);
			pRTIntProperty->PropertyType = ERuntimeReflectionPropertyType::Int;
			ReflClass->Properties.Add(pRTIntProperty);
			continue;
		}

		FInt64Property* Int64Property = CastField<FInt64Property>(pProperty);
		if (Int64Property)
		{
			URuntimeReflectionInt64Property* pRTInt64Property = NewObject<URuntimeReflectionInt64Property>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTInt64Property, pProperty, Container);
			pRTInt64Property->PropertyType = ERuntimeReflectionPropertyType::Int64;
			ReflClass->Properties.Add(pRTInt64Property);
			continue;
		}

		FByteProperty* ByteProperty = CastField<FByteProperty>(pProperty);
		if (ByteProperty)
		{
			URuntimeReflectionByteProperty* pRTByteProperty = NewObject<URuntimeReflectionByteProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTByteProperty, pProperty, Container);
			pRTByteProperty->PropertyType = ERuntimeReflectionPropertyType::Byte;
			ReflClass->Properties.Add(pRTByteProperty);
			continue;
		}

		FBoolProperty* BoolProperty = CastField<FBoolProperty>(pProperty);
		if (BoolProperty)
		{
			URuntimeReflectionBoolProperty* pRTBoolProperty = NewObject<URuntimeReflectionBoolProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTBoolProperty, pProperty, Container);
			pRTBoolProperty->PropertyType = ERuntimeReflectionPropertyType::Bool;
			ReflClass->Properties.Add(pRTBoolProperty);
			continue;
		}

		FFloatProperty* FloatProperty = CastField<FFloatProperty>(pProperty);
		if (FloatProperty)
		{
			URuntimeReflectionFloatProperty* pRTFloatProperty = NewObject<URuntimeReflectionFloatProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTFloatProperty, pProperty, Container);
			pRTFloatProperty->PropertyType = ERuntimeReflectionPropertyType::Float;
			ReflClass->Properties.Add(pRTFloatProperty);
			continue;
		}

		FStrProperty* StrProperty = CastField<FStrProperty>(pProperty);
		if (StrProperty)
		{
			URuntimeReflectionStringProperty* pRTStrProperty = NewObject<URuntimeReflectionStringProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTStrProperty, pProperty, Container);
			pRTStrProperty->PropertyType = ERuntimeReflectionPropertyType::String;
			ReflClass->Properties.Add(pRTStrProperty);
			continue;
		}

		FNameProperty* NameProperty = CastField<FNameProperty>(pProperty);
		if (NameProperty)
		{
			URuntimeReflectionNameProperty* pRTNameProperty = NewObject<URuntimeReflectionNameProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTNameProperty, pProperty, Container);
			pRTNameProperty->PropertyType = ERuntimeReflectionPropertyType::Name;
			ReflClass->Properties.Add(pRTNameProperty);
			continue;
		}

		FTextProperty* TextProperty = CastField<FTextProperty>(pProperty);
		if (TextProperty)
		{
			URuntimeReflectionTextProperty* pRTTextProperty = NewObject<URuntimeReflectionTextProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(pRTTextProperty, pProperty, Container);
			pRTTextProperty->PropertyType = ERuntimeReflectionPropertyType::Text;
			ReflClass->Properties.Add(pRTTextProperty);
			continue;
		}

		FObjectProperty* ObjectProperty = CastField<FObjectProperty>(pProperty);
		if (ObjectProperty)
		{
			URuntimeReflectionObjectProperty* PRTObjectProperty = NewObject<URuntimeReflectionObjectProperty>();
			RuntimeReflectionPropertyHelper::InitializeBaseVariablesFromUnrealProperty(PRTObjectProperty, pProperty, Container);
			PRTObjectProperty->PropertyType = ERuntimeReflectionPropertyType::Object;
			ReflClass->Properties.Add(PRTObjectProperty);
			continue;
		}
	}

	return ReflClass;
}
