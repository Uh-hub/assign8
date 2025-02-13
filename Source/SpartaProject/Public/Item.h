#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"
//Reflection �ý����� �����ϴ� ������Ϸ� �� include���� include�� �߿� ���� �Ʒ��� �־�߸� ���忡�� �ȶ�


//DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All); // Warning �̻��� �͸� ����ϰڴٴ� ���̰� ���� ������� �� ���Ѵٸ� �� ����� �� �ְ� All��

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
	UStaticMeshComponent* StaticMeshComp; //Mesh�� Static component��

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Properties")
	float RotationSpeed;

	//virtual void PostInitializeComponents() override; //������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ� �ޱ�. ��ȣ�ۿ�
	virtual void BeginPlay() override;//���α׷��� ����� ������ �Ҹ��� �Լ�
	virtual void Tick(float DeltaTime) override;
	//virtual void Destroyed() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;//EndPlayReason : Enum Ÿ�� ������ � ��Ȳ�� ������ EndPlay�� ����Ǿ����� �˷���

	//
	UFUNCTION(BlueprintCallable, Category="Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category="Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category ="Item|Event")
	void OnItemPickedUP();
};
