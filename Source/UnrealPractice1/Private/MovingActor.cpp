#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

