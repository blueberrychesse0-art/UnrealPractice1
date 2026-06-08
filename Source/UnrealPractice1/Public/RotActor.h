#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotActor.generated.h"

UCLASS()
class UNREALPRACTICE1_API ARotActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotActor();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;
	float RotationSpeed;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
