// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class UNREALPRACTICE1_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	FVector StartLocation;
	bool dir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Properties")
	float MaxRange;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
