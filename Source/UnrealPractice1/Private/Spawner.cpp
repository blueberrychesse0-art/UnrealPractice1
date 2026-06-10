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

	for(int i = 0; i < 5; ++i)
		SpawnActorRandomly();
	/*GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ASpawner::SpawnActorRandomly,
		5.0f, true);*/
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawner::SpawnActorRandomly()
{
	if (!SpawnClass)
	{
		UE_LOG(LogTemp, Error, TEXT("%s SpawnClass is not exit"), *GetName());
		return;
	}
	FVector WorldLocation = BoxComp->Bounds.Origin;
	FVector WorldExtent = BoxComp->Bounds.BoxExtent;

	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(WorldLocation, WorldExtent);

	GetWorld()->SpawnActor<AActor>(SpawnClass, RandomLocation, GetActorRotation());
}