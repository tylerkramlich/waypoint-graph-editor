﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WaypointVisualComponent.h"
#include "GameFramework/Actor.h"
#include "Waypoint.generated.h"

UCLASS()
class WAYPOINTGRAPHEDITOR_API AWaypoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWaypoint();

	FVector GetPosition() const { return Position; }
	void SetPosition(const FVector& NewPosition) { Position = NewPosition; }

	UPROPERTY()
	UWaypointVisualComponent* VisualComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Waypoint")
	FVector Position;
};
