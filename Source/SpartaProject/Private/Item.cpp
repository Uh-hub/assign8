#include "Item.h"

//DEFINE_LOG_CATEGORY(LogSparta); 

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
			    //컴포넌트를 생성해주는 함수<타입>(TEXT(해당 컴포넌트 이름)); :템플릿 형태
	SetRootComponent(SceneRoot); // SceneRoot를 루트 컴포넌트로 하겠다

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	//StaticMeshComp를 SceneRoot에 연결하겠다는 뜻

	//"/Game/Resources/Props/SM_Star_C.SM_Star_C"
	//'/Game/Resources/Props/Materials/M_Statue.M_Statue'
	//'/Game/Resources/Props/Materials/M_Lamp.M_Lamp'

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	////MeshAsset은 경로에 맞는 mesh를 찾는 helper
	////만약 해당 Mesh를 찾는데 성공했다면 MeshAsset의 object를 Mesh로 set
	//if (MeshAsset.Succeeded())
	//{
	//	StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	//}

	//static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Props/Materials/M_Statue.M_Statue"));
	//if (MaterialAsset.Succeeded()) 
	//{
	//	StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	//	//하나의 메쉬에 여러가지 material을 부분별로 부착 가능함 여기서는 우선 첫번째꺼에 넣기 위해 0 작성
	//	//UE_LOG(LogSparta, Warning, TEXT("%s Constructor"), *GetName()); //GetName이 Actor Item 클래스의 현재 인스턴스의 이름을 가져옴
	//}

	PrimaryActorTick.bCanEverTick = true; //tick 특별히 사용하지 않는 경우에는 false로 꺼놓는 게 나음
	
	
	RotationSpeed = 90.0f;
	
}

//void AItem::PostInitializeComponents()
//{
//	Super::PostInitializeComponents(); //여기 왜 Super?? 부모 호출해주는 거임 꼭 해주기
//	//UE_LOG(LogSparta, Warning, TEXT("%s PostInitializeComponents"), *GetName());
//}

void AItem::BeginPlay()
{
	Super::BeginPlay(); // 부모 호출이래 

	OnItemPickedUP();
	//SetActorLocation(FVector(300.0f, 200.0f, 100.0f)); //FVector가 location 값
	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); //pitch(y축), yaw(z축), roll(x축)
	//SetActorScale3D(FVector(2.0f, 1.0f, 1.0f)); //FVector(2.0f) 라고 하면 FVector(2.0f, 2.0f, 2.0f)와 같은 말임
	
	
	/*3가지를 한 번에 관리 가능*/
	//FVector NewLocation(300.0f, 200.0f, 100.0f);
	//FRotator NewRotation(0.0f, 90.0f, 0.0f);
	//FVector NewScale(2.0f, 1.0f, 1.0f);

	//FTransform NewTransform(NewRotation, NewLocation, NewScale);
	//SetActorTransform(NewTransform);

	//UE_LOG(LogTemp, Warning, TEXT("My Log!"));//Log Temp : 언리얼엔진에서 미리 만들어놓은 임시 카테고리
	////warning: 주의 표시로 노란색으로 뜸 // Display : 실행흐름 출력 같이 평험한 상황(흰색) //Error : 당장 수정해야 하는 것(빨간색)
	//UE_LOG(LogSparta, Error, TEXT("My Sparta!"));//Waring 보다 높은 Error이기 때문에 출력될 것임
	////현재 로그는 BeginPlay가 실행되어야 출력됩니다. 즉, 물체가 화면에 떠야 출력됨
	//UE_LOG(LogSparta, Warning, TEXT("%s BeginPlay"), *GetName());
}

void AItem::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	
	if (!FMath::IsNearlyZero(RotationSpeed)) 
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f)); //스스로 자전하는 거니까 local로
	}
	

	
}

//void AItem::Destroyed()
//{
//	UE_LOG(LogSparta, Warning, TEXT("%s Destroyed"), *GetName());
//	Super::Destroyed();
//}
//
//void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
//{
//	UE_LOG(LogSparta, Warning, TEXT("%s EndPlay"), *GetName());
//	Super::EndPlay(EndPlayReason);
//	
//}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}