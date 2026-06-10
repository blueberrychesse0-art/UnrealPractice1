#include "Spawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ASpawner::SpawnActor,
		0.1f, false);
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawner::SpawnActorRandomly()
{
	if (SpawnClass == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s SpawnClass is not exit"), *GetName());
		return;
	}
	if (SpawnClass->IsChildOf(ASpawner::StaticClass()))
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot spawn SpawnerClass"));
		return;
	}
	if (GetWorld() == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("World is not valid"));
		return;
	}

	FVector WorldLocation = BoxComp->Bounds.Origin;
	FVector WorldExtent = BoxComp->Bounds.BoxExtent;

	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(WorldLocation, WorldExtent);

	GetWorld()->SpawnActor<AActor>(SpawnClass, RandomLocation, GetActorRotation());
}

void ASpawner::SpawnActor()
{
	for (int i = 0; i < 5; ++i)
	{
		SpawnActorRandomly();
	}
}