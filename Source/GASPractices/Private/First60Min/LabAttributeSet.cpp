// Fill out your copyright notice in the Description page of Project Settings.


#include "First60Min/LabAttributeSet.h"

ULabAttributeSet::ULabAttributeSet()
{
	InitHealthPoint(100.0f);
	InitMaxHealthPoint(100.0f);
}

void ULabAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthPointAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealthPoint());
	}
	Super::PreAttributeChange(Attribute, NewValue);
}

void ULabAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	if (Attribute == GetMaxHealthPointAttribute())
	{
		OnHealthPointChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetMaxHealthPointAttribute())
	{
		const float CurrentHealth = GetHealthPoint();
		OnHealthPointChanged.Broadcast(this, CurrentHealth, CurrentHealth);
	}
}
