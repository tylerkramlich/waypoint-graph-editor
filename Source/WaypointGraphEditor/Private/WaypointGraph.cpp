// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointGraph.h"

#include "NavigationSystem.h"
#include "WaypointConnection.h"

void AWaypointGraph::SpawnWaypoints()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;

	AWaypoint* FirstWaypoint = GetWorld()->SpawnActor<AWaypoint>(AWaypoint::StaticClass(), FVector(100, 0,0), FRotator(0, 0, 0), SpawnParameters);
	AWaypoint* SecondWaypoint = GetWorld()->SpawnActor<AWaypoint>(AWaypoint::StaticClass(), FVector(0, 0,0), FRotator(0, 0, 0), SpawnParameters);
	
	UWaypointConnection* WaypointConnection = NewObject<UWaypointConnection>(this);
	Connections.Add(WaypointConnection);
	WaypointConnection->CreateConnection(FirstWaypoint, SecondWaypoint);

	AWaypoint* ThirdWaypoint = GetWorld()->SpawnActor<AWaypoint>(AWaypoint::StaticClass(), FVector(100, 0,0), FRotator(0, 0, 0), SpawnParameters);
	AWaypoint* FourthWaypoint = GetWorld()->SpawnActor<AWaypoint>(AWaypoint::StaticClass(), FVector(0, 0,0), FRotator(0, 0, 0), SpawnParameters);

	UWaypointConnection* WaypointConnectionTwo = NewObject<UWaypointConnection>(this);
	WaypointConnectionTwo->CreateConnection(ThirdWaypoint, FourthWaypoint);
	Connections.Add(WaypointConnectionTwo);

	UWaypointConnection* WaypointConnectionThree = NewObject<UWaypointConnection>(this);
	WaypointConnectionThree->CreateConnection(FirstWaypoint, FourthWaypoint);
	Connections.Add(WaypointConnectionThree);
}

void AWaypointGraph::TestMethod()
{
	
}

void AWaypointGraph::OtherTestMethod()
{
	for (auto Connection : Connections)
	{
		Connection->AddToPath();
	}
}
