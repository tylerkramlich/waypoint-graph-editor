// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointGraph.h"

#include "WaypointConnection.h"

void AWaypointGraph::SpawnWaypoints()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;

	AWaypoint* FirstWaypoint = GetWorld()->SpawnActor<AWaypoint>(AWaypoint::StaticClass(), FVector(100, 0,0), FRotator(0, 0, 0), SpawnParameters);
	AWaypoint* SecondWaypoint = GetWorld()->SpawnActor<AWaypoint>(AWaypoint::StaticClass(), FVector(0, 0,0), FRotator(0, 0, 0), SpawnParameters);
	
	UWaypointConnection* WaypointConnection = NewObject<UWaypointConnection>(this);
	CreatedConnection = WaypointConnection;
	WaypointConnection->CreateConnection(FirstWaypoint, SecondWaypoint);

	WaypointConnection->AddToPath();
}

void AWaypointGraph::TestMethod()
{
	CreatedConnection->RemoveFromPath();
}

void AWaypointGraph::OtherTestMethod()
{
	CreatedConnection->AddToPath();
}
