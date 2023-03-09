// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreUObject.h"
#include "Waypoint.h"
#include "WaypointConnectionVisualComponent.h"
#include "WaypointConnection.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class WAYPOINTGRAPHEDITOR_API UWaypointConnection : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	UWaypointConnection();

	UFUNCTION(BlueprintCallable)
	void CreateConnection(AWaypoint* StartWaypoint, AWaypoint* EndWaypoint);

	void AddToPath();

	void RemoveFromPath();
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsInPath = false;
	
	UPROPERTY()
	UWaypointConnectionVisualComponent* WaypointConnectionVisualComponent;

	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;
	virtual bool IsTickableWhenPaused() const override;
	virtual ETickableTickType GetTickableTickType() const override;
	virtual bool IsTickableInEditor() const override;
	
private:
	UPROPERTY(EditAnywhere, Category="Connection")
	AWaypoint* StartWaypoint;

	UPROPERTY(EditAnywhere, Category="Connection")
	AWaypoint* EndWaypoint;
	
};
