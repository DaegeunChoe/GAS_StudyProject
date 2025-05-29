// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GS_SomeAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GASPRACTICES_API UGS_SomeAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UGS_SomeAttributeSet();

	//~ ¾îÆ®¸®ºäÆ® 'Health'ÀÇ ÇïÆÛ ÇÔ¼ö
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UGS_SomeAttributeSet, HealhPoint);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(HealhPoint);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(HealhPoint);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(HealhPoint);

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HealhPoint; // HP
};
