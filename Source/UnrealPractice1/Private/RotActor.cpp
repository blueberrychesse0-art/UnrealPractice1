#include "RotActor.h"

ARotActor::ARotActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void ARotActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARotActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

