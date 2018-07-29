// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "SlidingDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_ESCAPETHEROOM1_API USlidingDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlidingDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenHiddenDoor();
	void CloseHiddenDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	bool bisHidden = false;

	UPROPERTY(EditAnywhere)
	float HiddenDoorDelay = 1.0f;

	float lastHiddenDoorTime;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;	
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate2;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate3;

	//UPROPERTY(EditAnywhere)
	AActor* actorThatOpens;

	AActor* owner;
};