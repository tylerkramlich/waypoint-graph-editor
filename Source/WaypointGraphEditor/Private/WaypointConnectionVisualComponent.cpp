// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointConnectionVisualComponent.h"

#include "WaypointRenderSceneProxy.h"

UWaypointConnectionVisualComponent::UWaypointConnectionVisualComponent(const FObjectInitializer& ObjectInitializer)
{
	// set up some constants
	PrimaryComponentTick.bCanEverTick = false;
	SetCastShadow(false);
#if WITH_EDITORONLY_DATA
	// Note: this makes this component invisible on level instances, not sure why
	SetIsVisualizationComponent(true);
#endif
	SetHiddenInGame(false);
	bVisibleInReflectionCaptures = false;
	bVisibleInRayTracing = false;
	bVisibleInRealTimeSkyCaptures = false;
	AlwaysLoadOnClient = false;
	bIsEditorOnly = true;
}

FPrimitiveSceneProxy* UWaypointConnectionVisualComponent::CreateSceneProxy()
{
	auto Ret = new FWaypointRenderSceneProxy(this);

	const FTransform& XForm = GetComponentTransform();
	Ret->Lines.Add(FDebugRenderSceneProxy::FDebugLine(XForm.TransformPosition(WaypointConnectionVisualizer.Start), XForm.TransformPosition(WaypointConnectionVisualizer.End), WaypointConnectionVisualizer.Color, WaypointConnectionVisualizer.Thickness));

	return Ret;
}

FBoxSphereBounds UWaypointConnectionVisualComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	FBoxSphereBounds B = Super::CalcBounds(LocalToWorld);
	FVector Extents = WaypointConnectionVisualizer.Start.GetAbs().ComponentMax(WaypointConnectionVisualizer.End.GetAbs());
	B = B + FBoxSphereBounds(FVector::ZeroVector, Extents, Extents.GetMax());
	return B.TransformBy(LocalToWorld);
}
