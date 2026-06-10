#include "RotActor.h"

ARotActor::ARotActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void ARotActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ARotActor::MoveRandom, FMath::FRandRange(1.5f, 4.0f), true, 5.0f);
}

void ARotActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void ARotActor::MoveRandom()
{
	FVector offset{ FMath::FRandRange(-100.0f, 100.0f), 
		FMath::FRandRange(-100.0f, 100.0f), 
		0.0f };

	AddActorWorldOffset(offset);
}

