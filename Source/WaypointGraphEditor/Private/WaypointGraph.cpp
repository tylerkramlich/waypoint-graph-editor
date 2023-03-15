// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointGraph.h"

#include "NavigationSystem.h"
#include "WaypointConnection.h"
#include "Components/LineBatchComponent.h"

AWaypointGraph::AWaypointGraph()
{
    LineBatchComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatchComponent"));
}

void AWaypointGraph::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    DrawConnections();
}

void AWaypointGraph::DrawConnections()
{
    if (!LineBatchComponent)
    {
        return;
    }

    TArray<FBatchedLine> Lines;

    for (AWaypoint* Waypoint : Waypoints)
    {
        if (!Waypoint)
        {
            continue;
        }

        for (AWaypoint* Neighbor : Waypoint->Neighbors)
        {
            if (!Neighbor)
            {
                continue;
            }

            // Create a line between the waypoint and its neighbor
            FVector Start = Waypoint->GetActorLocation();
            FVector End = Neighbor->GetActorLocation();
            FColor LineColor = FColor::Green;
            float Thickness = 1.0f;

            FBatchedLine Line;
            Line.Start = Start;
            Line.End = End;
            Line.Color = LineColor;
            Line.Thickness = Thickness;
            Line.DepthPriority = SDPG_World;

            Lines.Add(Line);
        }
    }

    // Draw all lines with a single draw call
    LineBatchComponent->DrawLines(Lines);
}


