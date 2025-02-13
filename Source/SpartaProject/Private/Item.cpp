#include "Item.h"

//DEFINE_LOG_CATEGORY(LogSparta); 

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
			    //������Ʈ�� �������ִ� �Լ�<Ÿ��>(TEXT(�ش� ������Ʈ �̸�)); :���ø� ����
	SetRootComponent(SceneRoot); // SceneRoot�� ��Ʈ ������Ʈ�� �ϰڴ�

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	//StaticMeshComp�� SceneRoot�� �����ϰڴٴ� ��

	//"/Game/Resources/Props/SM_Star_C.SM_Star_C"
	//'/Game/Resources/Props/Materials/M_Statue.M_Statue'
	//'/Game/Resources/Props/Materials/M_Lamp.M_Lamp'

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	////MeshAsset�� ��ο� �´� mesh�� ã�� helper
	////���� �ش� Mesh�� ã�µ� �����ߴٸ� MeshAsset�� object�� Mesh�� set
	//if (MeshAsset.Succeeded())
	//{
	//	StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	//}

	//static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Props/Materials/M_Statue.M_Statue"));
	//if (MaterialAsset.Succeeded()) 
	//{
	//	StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	//	//�ϳ��� �޽��� �������� material�� �κк��� ���� ������ ���⼭�� �켱 ù��°���� �ֱ� ���� 0 �ۼ�
	//	//UE_LOG(LogSparta, Warning, TEXT("%s Constructor"), *GetName()); //GetName�� Actor Item Ŭ������ ���� �ν��Ͻ��� �̸��� ������
	//}

	PrimaryActorTick.bCanEverTick = true; //tick Ư���� ������� �ʴ� ��쿡�� false�� ������ �� ����
	
	
	RotationSpeed = 90.0f;
	
}

//void AItem::PostInitializeComponents()
//{
//	Super::PostInitializeComponents(); //���� �� Super?? �θ� ȣ�����ִ� ���� �� ���ֱ�
//	//UE_LOG(LogSparta, Warning, TEXT("%s PostInitializeComponents"), *GetName());
//}

void AItem::BeginPlay()
{
	Super::BeginPlay(); // �θ� ȣ���̷� 

	OnItemPickedUP();
	//SetActorLocation(FVector(300.0f, 200.0f, 100.0f)); //FVector�� location ��
	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); //pitch(y��), yaw(z��), roll(x��)
	//SetActorScale3D(FVector(2.0f, 1.0f, 1.0f)); //FVector(2.0f) ��� �ϸ� FVector(2.0f, 2.0f, 2.0f)�� ���� ����
	
	
	/*3������ �� ���� ���� ����*/
	//FVector NewLocation(300.0f, 200.0f, 100.0f);
	//FRotator NewRotation(0.0f, 90.0f, 0.0f);
	//FVector NewScale(2.0f, 1.0f, 1.0f);

	//FTransform NewTransform(NewRotation, NewLocation, NewScale);
	//SetActorTransform(NewTransform);

	//UE_LOG(LogTemp, Warning, TEXT("My Log!"));//Log Temp : �𸮾������� �̸� �������� �ӽ� ī�װ�
	////warning: ���� ǥ�÷� ��������� �� // Display : �����帧 ��� ���� ������ ��Ȳ(���) //Error : ���� �����ؾ� �ϴ� ��(������)
	//UE_LOG(LogSparta, Error, TEXT("My Sparta!"));//Waring ���� ���� Error�̱� ������ ��µ� ����
	////���� �α״� BeginPlay�� ����Ǿ�� ��µ˴ϴ�. ��, ��ü�� ȭ�鿡 ���� ��µ�
	//UE_LOG(LogSparta, Warning, TEXT("%s BeginPlay"), *GetName());
}

void AItem::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	
	if (!FMath::IsNearlyZero(RotationSpeed)) 
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f)); //������ �����ϴ� �Ŵϱ� local��
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