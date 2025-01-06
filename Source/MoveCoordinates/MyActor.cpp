// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FMath::SRandInit(FPlatformTime::Cycles());
	move();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move()
{
	for (int32 i = 0; i < 10; i++)
	{
		int32 RandomX = step();
		int32 RandomY = step();
		start.X += RandomX;
		start.Y += RandomY;
		coordinatesArr.Add(FVector2D(start.X, start.Y));
		UE_LOG(LogTemp, Warning, TEXT("%d, %d move - current coordinates %d, %d"),
			RandomX, RandomY, (int)start.X, (int)start.Y);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
				FString::Printf(TEXT("%d, %d move - current coordinates %d, %d"),
					RandomX, RandomY, (int)start.X, (int)start.Y));
		}
	}
}

int32 AMyActor::step()
{
	int32 randomNumber = FMath::RandRange(0, 1);
	return randomNumber;
}