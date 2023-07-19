// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeReflectionStructHelper.h"

RuntimeReflectionStructHelper::RuntimeReflectionStructHelper()
{
}

RuntimeReflectionStructHelper::~RuntimeReflectionStructHelper()
{
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