// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LabAttributeSet.generated.h"

// struct getter, value getter, value setter, value init
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FAttributeChangedEvent,
	UAttributeSet*, AttributeSet,
	float, OldValue,
	float, NewValue
);

UCLASS()
class GASPRACTICES_API ULabAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:	
	ULabAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue);

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHealthPointChanged;

	ATTRIBUTE_ACCESSORS(ULabAttributeSet, HealthPoint);
	ATTRIBUTE_ACCESSORS(ULabAttributeSet, MaxHealthPoint);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HealthPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHealthPoint;
};
