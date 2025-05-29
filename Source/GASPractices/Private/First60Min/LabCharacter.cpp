// Fill out your copyright notice in the Description page of Project Settings.


#include "First60Min/LabCharacter.h"
#include "First60Min/LabAttributeSet.h"
#include "First60Min/LabAbilitySystemComponent.h"

ALabCharacter::ALabCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	LabAbilitySystemComponent = CreateDefaultSubobject<ULabAbilitySystemComponent>(TEXT("ASC"));
	LabAttributeSet = CreateDefaultSubobject<ULabAttributeSet>(TEXT("LabAttributeSet"));
}

void ALabCharacter::BeginPlay()
{
	Super::BeginPlay();

	//LabAbilitySystemComponent->InitAbilityActorInfo(this, this);

	if (IsValid(LabAttributeSet))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "BeginPlay(): LabAttributeSet is Valid");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "BeginPlay(): LabAttributeSet is NOT Valid");
	}

	//const ULabAttributeSet* Foo = LabAbilitySystemComponent->GetSet<ULabAttributeSet>();
	//if (IsValid(Foo))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "GetSet ULabAttributeSet is Valid");
	//}
	//else
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "GetSet ULabAttributeSet is NOT Valid");
	//}
}

void ALabCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALabCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ALabCharacter::GetAbilitySystemComponent() const
{
	return LabAbilitySystemComponent;
}
