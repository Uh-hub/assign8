#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"
//Reflection 시스템을 지원하는 헤더파일로 이 include문이 include문 중에 가장 아래에 있어야만 빌드에러 안뜸


//DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All); // Warning 이상의 것만 출력하겠다는 뜻이고 만약 디버깅할 때 원한다면 다 출력할 수 있게 All로

UCLASS()
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item|Components")
	USceneComponent* SceneRoot; //Root Component - Scene component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item|Components")
	UStaticMeshComponent* StaticMeshComp; //Mesh는 Static component로

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Properties")
	float RotationSpeed;

	//virtual void PostInitializeComponents() override; //컴포넌트가 완성된 직후 호출. 컴포넌트끼리 데이터 주고 받기. 상호작용
	virtual void BeginPlay() override;//프로그램이 실행된 시점에 불리는 함수
	virtual void Tick(float DeltaTime) override;
	//virtual void Destroyed() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;//EndPlayReason : Enum 타입 변수로 어떤 상황과 이유로 EndPlay가 실행되었는지 알려줌

	//
	UFUNCTION(BlueprintCallable, Category="Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category="Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category ="Item|Event")
	void OnItemPickedUP();
};
