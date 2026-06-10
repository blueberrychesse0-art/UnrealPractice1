#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class UBoxComponent;

UCLASS()
class UNREALPRACTICE1_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:
	ASpawner();

protected:
	virtual void BeginPlay() override;
	FTimerHandle MemberTimerHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> SpawnClass;
public:
	virtual void Tick(float DeltaTime) override;

	void SpawnActorRandomly();

	UFUNCTION(BlueprintCallable)
	void SpawnActor();
};
