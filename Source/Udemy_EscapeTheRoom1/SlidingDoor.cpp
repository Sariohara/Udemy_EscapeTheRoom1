// Fill out your copyright notice in the Description page of Project Settings.

#include "SlidingDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
USlidingDoor::USlidingDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USlidingDoor::BeginPlay()
{
	Super::BeginPlay();

	actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void USlidingDoor::OpenHiddenDoor()
{
	//Find the owner
	owner = GetOwner();


	if (owner && bisHidden == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("object is hidden: %b"), bisHidden)
		//bisHidden = true;
		owner->SetActorHiddenInGame(true);
		owner->SetActorEnableCollision(false);
		owner->SetActorTickEnabled(false);
		bisHidden = true;
		
	}
	
	
}

void USlidingDoor::CloseHiddenDoor()
{
	//Find the owner
	owner = GetOwner();

	if (owner && bisHidden == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("object is not hidden: %b"), bisHidden)
		owner->SetActorHiddenInGame(false);
		owner->SetActorEnableCollision(true);
		owner->SetActorTickEnabled(true);
		bisHidden = false;
	}
	
	
}


// Called every frame
void USlidingDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurePlate && pressurePlate->IsOverlappingActor(actorThatOpens))
	{
		OpenHiddenDoor();
		lastHiddenDoorTime = GetWorld()->GetTimeSeconds();
	}
	
	if (pressurePlate2 && pressurePlate2->IsOverlappingActor(actorThatOpens))
	{
		OpenHiddenDoor();
		lastHiddenDoorTime = GetWorld()->GetTimeSeconds();
	}
	
	if (pressurePlate3 && pressurePlate3->IsOverlappingActor(actorThatOpens))
	{
		OpenHiddenDoor();
		lastHiddenDoorTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - lastHiddenDoorTime > HiddenDoorDelay)
	{
		CloseHiddenDoor();
	}

	
}

