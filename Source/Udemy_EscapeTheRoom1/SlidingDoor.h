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

	void OpenSlidingDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
	float openAngle = 90.0f;

	bool bisHidden = false;

	FTimerHandle* hideDoorTimer;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;

	//UPROPERTY(EditAnywhere)
	AActor* actorThatOpens;
};