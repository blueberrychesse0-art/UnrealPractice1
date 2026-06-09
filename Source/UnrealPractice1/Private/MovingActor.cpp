#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	StartLocation = GetActorLocation();
	MoveSpeed = 500.0f;
	MaxRange = 2000.0f;
	dir = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMovingActor::ChangeActive, 
		FMath::FRandRange(2.0f, 5.0f), true, FMath::FRandRange(0.0f, 10.0f));
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		float Distance = FVector::Dist(GetActorLocation(), StartLocation);
		AddActorWorldOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));
		if (Distance > MaxRange && dir == true)
		{
			MoveSpeed *= -1.0f;
			dir = false;
		}
		if (Distance <= MaxRange)
		{
			dir = true;
		}
	}
}

void AMovingActor::ChangeActive()
{
	if (IsHidden())
	{
		SetActorHiddenInGame(false);
		SetActorEnableCollision(true);
	}
	else
	{
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
	
}

