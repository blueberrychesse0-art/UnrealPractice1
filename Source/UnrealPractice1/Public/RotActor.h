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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
