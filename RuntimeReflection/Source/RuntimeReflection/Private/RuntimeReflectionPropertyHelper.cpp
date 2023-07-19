// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeReflectionPropertyHelper.h"

RuntimeReflectionPropertyHelper::RuntimeReflectionPropertyHelper()
{
}

RuntimeReflectionPropertyHelper::~RuntimeReflectionPropertyHelper()
{
}

void RuntimeReflectionPropertyHelper::InitializeBasePropertyVariables(URuntimeReflectionProperty* pRuntimeProperty, FProperty* pUnrealProperty)
{
	pRuntimeProperty->Property = pUnrealProperty;
	pRuntimeProperty->PropertyFlags = pUnrealProperty->GetPropertyFlags();
	pRuntimeProperty->Name = pUnrealProperty->GetName();
	pRuntimeProperty->ElementSize = pUnrealProperty->ElementSize;
	pRuntimeProperty->ArrayDim = pUnrealProperty->ArrayDim;

	uint64 flags = pRuntimeProperty->PropertyFlags;
	pRuntimeProperty->PropertyFlagsByte0 = (uint8)(flags >> 0  & 0xFF);
	pRuntimeProperty->PropertyFlagsByte1 = (uint8)(flags >> 8  & 0xFF);
	pRuntimeProperty->PropertyFlagsByte2 = (uint8)(flags >> 16 & 0xFF);
	pRuntimeProperty->PropertyFlagsByte3 = (uint8)(flags >> 24 & 0xFF);
	pRuntimeProperty->PropertyFlagsByte4 = (uint8)(flags >> 32 & 0xFF);
	pRuntimeProperty->PropertyFlagsByte5 = (uint8)(flags >> 40 & 0xFF);
	pRuntimeProperty->PropertyFlagsByte6 = (uint8)(flags >> 48 & 0xFF);
	pRuntimeProperty->PropertyFlagsByte7 = (uint8)(flags >> 56 & 0xFF);
}