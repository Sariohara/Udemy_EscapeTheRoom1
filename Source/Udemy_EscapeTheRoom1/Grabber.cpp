// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT playerViewPointLocation,
		OUT playerViewPointRotation
	);

	UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"),
		*playerViewPointLocation.ToString(),
		*playerViewPointRotation.ToString()
	)

	FVector LineTraceEnd = playerViewPointLocation + playerViewPointRotation.Vector() * Reach;
	DrawDebugLine(
		GetWorld(),						//get world
		playerViewPointLocation,		//get player location
		LineTraceEnd,					//draw the end line trace
		FColor(255, 0, 0),				//get the color of the line
		false,							//false
		0.0f,							//0.0f
		0.0f,							//0.0f
		10.0f							//thickness
	);

}

