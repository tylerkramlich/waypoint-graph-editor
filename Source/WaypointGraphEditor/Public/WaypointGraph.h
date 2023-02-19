// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Waypoint.h"
#include "GameFramework/Actor.h"
#include "WaypointGraph.generated.h"

/**
 * 
 */
UCLASS()
class WAYPOINTGRAPHEDITOR_API AWaypointGraph : public AActor
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void SpawnWaypoints();

	UFUNCTION(BlueprintCallable)
	void TestMethod();

	UFUNCTION(BlueprintCallable)
	void OtherTestMethod();
	
	UPROPERTY()
	UWaypointConnection* CreatedConnection;
};
