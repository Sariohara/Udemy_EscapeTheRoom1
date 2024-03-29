// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOPenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_ESCAPETHEROOM1_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

	float GetTotalMassofPlayerOnPlate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UPROPERTY(BlueprintAssignable)
	FOnOPenRequest OnOpenRequest;

private:

	UPROPERTY(EditAnywhere)
	float openAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	float doorCloseDelay = 1.0f;

	float lastDoorOpenTime;

	float TotalMass = 0.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate = nullptr;

	AActor* Owner = nullptr;

		
	
};
