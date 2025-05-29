// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CharacterBase.h"
#include "AbilitySystemComponent.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Abilities/GameplayAbility.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	SomeAttributeSet = CreateDefaultSubobject<UGS_SomeAttributeSet>(TEXT("SomeAttributeSet"));
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	FGameplayAbilitySpec AbilitySpec(JumpAbility);
	AbilitySystemComponent->GiveAbility(AbilitySpec);

	if (IsValid(SomeAttributeSet))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "SomeAttributeSet is Valid");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "SomeAttributeSet is NOT Valid");
	}

	const UGS_SomeAttributeSet* Foo = AbilitySystemComponent->GetSet<UGS_SomeAttributeSet>();
	if (IsValid(Foo))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "GetSet UGS_SomeAttributeSet is Valid");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "GetSet UGS_SomeAttributeSet is NOT Valid");
	}
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//const UGS_SomeAttributeSet* Foo = AbilitySystemComponent->GetSet<UGS_SomeAttributeSet>();
	//if (IsValid(Foo))
	//{
	//	if (IsValid(Foo->GetOwningActor()))
	//	{
	//		float HP = SomeAttributeSet->GetHealhPoint();
	//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, FString::Printf(TEXT("HP : %e"), HP));
	//	}
	//}
	//else
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "Foo is NOT Valid");
	//}
}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//입력 이벤트를 Bind 해주는 부분
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacterBase::OnJumpInput);
	}
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::OnJumpInput(const FInputActionValue& Value)
{
	FGameplayAbilitySpec* Spec = AbilitySystemComponent->FindAbilitySpecFromClass(JumpAbility);
	AbilitySystemComponent->TryActivateAbility(Spec->Handle);
}
