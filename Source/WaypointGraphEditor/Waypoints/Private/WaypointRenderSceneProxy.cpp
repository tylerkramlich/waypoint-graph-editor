// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointRenderSceneProxy.h"

void FWaypointRenderSceneProxy::GetDynamicMeshElements(const TArray<const FSceneView*>& Views,
	const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const
{
	FDebugRenderSceneProxy::GetDynamicMeshElements(Views, ViewFamily, VisibilityMap, Collector);

	for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
	{
		if (VisibilityMap & 1 << ViewIndex)
		{
			FPrimitiveDrawInterface* PDI = Collector.GetPDI(ViewIndex);

			// Draw Waypoint
			for (const auto& W : Waypoints)
			{
				DrawCircle(PDI, W.Centre, W.X, W.Y, W.Color, W.Radius, W.NumSegments, SDPG_World, W.Thickness, 0, W.Thickness > 0);
			}
		}
	}
}

FPrimitiveViewRelevance FWaypointRenderSceneProxy::GetViewRelevance(const FSceneView* View) const
{
	FPrimitiveViewRelevance Result;
	Result.bDrawRelevance = IsShown(View);
	Result.bDynamicRelevance = true;
	Result.bShadowRelevance = false;
	Result.bEditorPrimitiveRelevance = UseEditorCompositing(View);
	return Result;
}