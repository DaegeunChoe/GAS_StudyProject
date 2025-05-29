// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GA_SomeAbility.h"
#include "GameFramework/Character.h"

void UGA_SomeAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	// nullcheck »ý·«
	TWeakObjectPtr<AActor> OwnerActor = ActorInfo->OwnerActor;
	TWeakObjectPtr<ACharacter> Character = Cast<ACharacter>(OwnerActor);
	Character->Jump();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "ActivateAbility()!!");

	FGameplayEffectSpecHandle EffectSpecHandle = MakeOutgoingGameplayEffectSpec(MyEffect, 1);
	auto a = EffectSpecHandle.Data;
	auto c = a.Get();
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("EffectSpecHandle: %f"), c));
	this->ApplyGameplayEffectSpecToOwner(Handle, ActorInfo, ActivationInfo, EffectSpecHandle);

	// ³¡
	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}