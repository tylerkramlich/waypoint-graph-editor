// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointConnection.h"

#include "AI/NavigationSystemBase.h"

UWaypointConnection::UWaypointConnection()
{
#if WITH_EDITOR
	WaypointConnectionVisualComponent = CreateDefaultSubobject<UWaypointConnectionVisualComponent>("WaypointConnectionVisual");
	WaypointConnectionVisualComponent->RegisterComponent();
#endif
}

void UWaypointConnection::CreateConnection(AWaypoint* FirstWaypoint, AWaypoint* SecondWaypoint)
{
	StartWaypoint = FirstWaypoint;
	EndWaypoint = SecondWaypoint;
	
	WaypointConnectionVisualComponent->WaypointConnectionVisualizer.Start = StartWaypoint->GetTransform().GetLocation();
	WaypointConnectionVisualComponent->WaypointConnectionVisualizer.End = EndWaypoint->GetTransform().GetLocation();
}

void UWaypointConnection::AddToPath()
{
	bIsInPath = true;
}

void UWaypointConnection::RemoveFromPath()
{
	bIsInPath = false;
}

void UWaypointConnection::Tick(float DeltaTime)
{
	if (StartWaypoint && EndWaypoint)
	{
		if (bIsInPath)
		{
			WaypointConnectionVisualComponent->WaypointConnectionVisualizer.Color = FColor::Green;
		} else
		{
			WaypointConnectionVisualComponent->WaypointConnectionVisualizer.Color = FColor::White;
		}
		
		WaypointConnectionVisualComponent->WaypointConnectionVisualizer.Start = StartWaypoint->GetTransform().GetLocation();
		WaypointConnectionVisualComponent->WaypointConnectionVisualizer.End = EndWaypoint->GetTransform().GetLocation();
		WaypointConnectionVisualComponent->MarkRenderStateDirty();
	}
}

bool UWaypointConnection::IsTickable() const
{
	return FTickableGameObject::IsTickable();
}

TStatId UWaypointConnection::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UWaypointConnection, STATGROUP_Tickables);
}

bool UWaypointConnection::IsTickableWhenPaused() const
{
	return FTickableGameObject::IsTickableWhenPaused();
}

ETickableTickType UWaypointConnection::GetTickableTickType() const
{
	return FTickableGameObject::GetTickableTickType();
}