#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	StartLocation = GetActorLocation();
	MoveSpeed = 100.0f;
	MaxRange = 1000.0f;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		float Distance = FVector::Dist(GetActorLocation(), StartLocation);
		AddActorWorldOffset(FVector(Distance, 0.0f, 0.0f));
		if (Distance > MaxRange)
		{
			MoveSpeed *= -1.0f;
		}
	}
}

