// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MOVECOORDINATES_API AMyActor : public AActor
{
	GENERATED_BODY()
	
private:
	TArray<FVector2D> coordinatesArr = { FVector2D(0, 0) };
	FVector2D start = FVector2D(0, 0);

	int32 evCnt;
	float totDist;
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void move();
	int32 step();
	float distance(FVector2D first, FVector2D second);
	void createEvent();

};
