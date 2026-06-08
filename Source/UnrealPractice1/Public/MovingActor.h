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
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
