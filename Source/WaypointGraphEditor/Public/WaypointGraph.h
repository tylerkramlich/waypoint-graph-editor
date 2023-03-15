// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Waypoint.h"
#include "WaypointGraphVisualComponent.h"
#include "GameFramework/Actor.h"
#include "WaypointGraph.generated.h"

class UWaypointConnection;
/**
 * 
 */
UCLASS(BlueprintType)
class WAYPOINTGRAPHEDITOR_API AWaypointGraph : public AActor
{
	GENERATED_BODY()

public:
	AWaypointGraph();

	UPROPERTY()
	ULineBatchComponent* LineBatchComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AWaypoint*> Waypoints;

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UFUNCTION(BlueprintCallable)
	void DrawConnections();
};
