// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeReflectionProperty.h"

#define VERIFY_PROPERTY() verify(Property != nullptr)
#define VERIFY_PROPERTY_AND_CONTAINER() verify(Property != nullptr && Container != nullptr)

URuntimeReflectionProperty::URuntimeReflectionProperty(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

bool URuntimeReflectionProperty::HasMetadata(FName const& Key)
{
	VERIFY_PROPERTY();
	return Property->HasMetaData(Key);
}

bool URuntimeReflectionBoolProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return BoolProperty->GetDefaultPropertyValue();
}

bool URuntimeReflectionBoolProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return BoolProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionBoolProperty::SetValue(bool Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	BoolProperty->SetPropertyValue_InContainer(Container, Value);
}

uint8 URuntimeReflectionByteProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return ByteProperty->GetDefaultPropertyValue();
}

uint8 URuntimeReflectionByteProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return ByteProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionByteProperty::SetValue(uint8 Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	ByteProperty->SetPropertyValue_InContainer(Container, Value);
}

int32 URuntimeReflectionIntProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return IntProperty->GetDefaultPropertyValue();
}

int32 URuntimeReflectionIntProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return IntProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionIntProperty::SetValue(int32 Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	IntProperty->SetPropertyValue_InContainer(Container, Value);
}

int32 URuntimeReflectionIntProperty::GetIntMetaData(FName const& Key)
{
	VERIFY_PROPERTY();
	return IntProperty->GetIntMetaData(Key);
}

int64 URuntimeReflectionInt64Property::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return IntProperty->GetDefaultPropertyValue();
}

int64 URuntimeReflectionInt64Property::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return IntProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionInt64Property::SetValue(int64 Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	IntProperty->SetPropertyValue_InContainer(Container, Value);
}

int64 URuntimeReflectionInt64Property::GetIntMetaData(FName const& Key)
{
	VERIFY_PROPERTY();
	return IntProperty->GetIntMetaData(Key);
}

float URuntimeReflectionFloatProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return FloatProperty->GetDefaultPropertyValue();
}

float URuntimeReflectionFloatProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return FloatProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionFloatProperty::SetValue(float Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	FloatProperty->SetPropertyValue_InContainer(Container, Value);
}

float URuntimeReflectionFloatProperty::GetFloatMetadata(FName const& Key)
{
	VERIFY_PROPERTY();
	return FloatProperty->GetFloatMetaData(Key);
}

FString URuntimeReflectionStringProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return StringProperty->GetDefaultPropertyValue();
}

FString URuntimeReflectionStringProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return StringProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionStringProperty::SetValue(FString const& Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	StringProperty->SetPropertyValue_InContainer(Container, Value);
}

FText URuntimeReflectionTextProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return TextProperty->GetDefaultPropertyValue();
}

FText URuntimeReflectionTextProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return TextProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionTextProperty::SetValue(FText const& Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	TextProperty->SetPropertyValue_InContainer(Container, Value);
}

FName URuntimeReflectionNameProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return NameProperty->GetDefaultPropertyValue();
}

FName URuntimeReflectionNameProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return NameProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionNameProperty::SetValue(FName Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	NameProperty->SetPropertyValue_InContainer(Container, Value);
}

UObject* URuntimeReflectionObjectProperty::GetDefaultValue()
{
	VERIFY_PROPERTY();
	return ObjectProperty->GetDefaultPropertyValue();
}

UObject* URuntimeReflectionObjectProperty::GetValue()
{
	VERIFY_PROPERTY_AND_CONTAINER();
	return ObjectProperty->GetPropertyValue_InContainer(Container);
}

void URuntimeReflectionObjectProperty::SetValue(UObject* Value)
{
	VERIFY_PROPERTY_AND_CONTAINER();
	ObjectProperty->SetPropertyValue_InContainer(Container, Value);
}


