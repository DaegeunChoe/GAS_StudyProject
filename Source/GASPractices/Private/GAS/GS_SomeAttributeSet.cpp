// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GS_SomeAttributeSet.h"

UGS_SomeAttributeSet::UGS_SomeAttributeSet()
{
}

void UGS_SomeAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, "AAAA");
}
