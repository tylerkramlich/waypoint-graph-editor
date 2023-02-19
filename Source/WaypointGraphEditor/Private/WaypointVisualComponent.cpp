// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointVisualComponent.h"
#include "WaypointRenderSceneProxy.h"

UWaypointVisualComponent::UWaypointVisualComponent(const FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
	SetCastShadow(false);
#if WITH_EDITORONLY_DATA
	SetIsVisualizationComponent(true);
#endif
	SetHiddenInGame(false);
	bVisibleInReflectionCaptures = false;
	bVisibleInRayTracing = false;
	bVisibleInRealTimeSkyCaptures = false;
	AlwaysLoadOnClient = false;
	bIsEditorOnly = true;
}

FPrimitiveSceneProxy* UWaypointVisualComponent::CreateSceneProxy()
{
	auto Ret = new FWaypointRenderSceneProxy(this);

	const FTransform& XForm = GetComponentTransform();
	FQuat WorldRot = XForm.TransformRotation(WaypointVisualizer.Rotation.Quaternion());
	Ret->Waypoints.Add(FWaypointRenderSceneProxy::FDebugWaypoint(
		XForm.TransformPosition(WaypointVisualizer.Location),
		WorldRot.GetForwardVector(), WorldRot.GetRightVector(),
		XForm.GetMaximumAxisScale() * WaypointVisualizer.Radius,
		WaypointVisualizer.NumSegments, WaypointVisualizer.Color, WaypointVisualizer.Thickness
	));
	
	return Ret;
}

FBoxSphereBounds UWaypointVisualComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	FBoxSphereBounds B = Super::CalcBounds(LocalToWorld);
	B = B + FBoxSphereBounds(WaypointVisualizer.Location, FVector(WaypointVisualizer.Radius), WaypointVisualizer.Radius);
	return B.TransformBy(LocalToWorld);
}

