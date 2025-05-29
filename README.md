## 현재 문제 상황

이 Unreal 프로젝트에는 두 개의 `ACharacter` 클래스가 있습니다.

하나는 `ALabCharacter` 이고, 다른 하나는 `ACharacterBase` 입니다.

두 클래스 모두 `AbilitySystemComponent`과 `AttributeSet`을 가지고 있습니다.


문제는 다음과 같습니다. 

### ACharacterBase

`ACharacterBase`는 생성자에서 `AttributeSet`을 생성합니다. 

그 후, `ACharacterBase::BeginPlay()`안에서, 생성한 `AttributeSet` 인스턴스의 주소를 확인합니다.

이 경우는 문제 없습니다. (인스턴스 주소가 올바름)

코드 위치: `GASPractices\Source\GASPractices\Private\GAS\CharacterBase.cpp`




### ALabCharacter

반면, `ALabCharacter` 에서는 그렇지 않습니다.

마찬가지로 생성자에서 `AttributeSet`을 생성합니다. 

그 후, `ALabCharacter::BeginPlay()`안에서, 생성한 `AttributeSet` 인스턴스의 주소를 확인합니다.

이 경우 문제가 발생합니다. `AttributeSet` 인스턴스의 주소를 가리키던 포인터의 값이 `nullptr(0)`으로 초기화 됩니다.

코드 위치: `GASPractices\Source\GASPractices\Private\First60Min\LabCharacter.cpp`


### 두 코드의 차이점

두 코드가 미묘하게 다른 부분이 있긴 합니다. 

`const T*` 대신 `TObjectPtr<T>`를 사용하거나, `UAbilitySystemComponent`를 사용하는 대신 `UAbilitySystemComponent`를 상속받은 클래스를 사용하거나 합니다.

