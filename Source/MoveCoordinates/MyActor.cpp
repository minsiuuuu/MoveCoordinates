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

	UE_LOG(LogTemp, Warning, TEXT("Total distance: %f, Total Event Triggered: %d"), totDist, evCnt);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green,
			FString::Printf(TEXT("Total distance: %f, Total Event Triggered: %d"), totDist, evCnt));
	}
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

		float MoveDistance = distance(coordinatesArr[i], coordinatesArr[i + 1]);
		UE_LOG(LogTemp, Error, TEXT("move distance - %f"), MoveDistance);

		totDist += MoveDistance;

		createEvent();


		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow,
				FString::Printf(TEXT("%d, %d move - current coordinates %d, %d"),
					RandomX, RandomY, (int)start.X, (int)start.Y));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White,
				FString::Printf(TEXT("move distance - %f"), MoveDistance));
		}
	}
}

int32 AMyActor::step()
{
	int32 randomNumber = FMath::RandRange(0, 1);
	return randomNumber;
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float distanceX = FMath::Pow(second.X - first.X, 2);
	float distanceY = FMath::Pow(second.Y - first.Y, 2);

	return FMath::Sqrt(distanceX + distanceY);
}

void AMyActor::createEvent()
{
	int32 randomEvent = FMath::RandRange(0, 1);
	if (randomEvent == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		evCnt++;

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue,
				FString::Printf(TEXT("Event Triggered!")));
		}
	}
	else if (randomEvent == 1)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered!"));

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red,
				FString::Printf(TEXT("Event Not Triggered!")));
		}
	}
}