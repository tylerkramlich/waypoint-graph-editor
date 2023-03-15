// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointGraphVisualComponent.h"
#include "WaypointConnection.h"
#include "WaypointGraph.h"
#include "WaypointRenderSceneProxy.h"


// Sets default values for this component's properties
UWaypointGraphVisualComponent::UWaypointGraphVisualComponent(const FObjectInitializer& ObjectInitializer)
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

FPrimitiveSceneProxy* UWaypointGraphVisualComponent::CreateSceneProxy()
{
	auto Ret = new FWaypointRenderSceneProxy(this);

	const FTransform& XForm = GetComponentTransform();

	AWaypointGraph* WaypointGraph = Cast<AWaypointGraph>(GetOwner());

	
	// for (UWaypointConnection* Connection : WaypointGraph->Connections)
	// {
	// 	Ret->Lines.Add(FDebugRenderSceneProxy::FDebugLine(XForm.TransformPosition(Connection->StartWaypoint->GetPosition()), XForm.TransformPosition(Connection->EndWaypoint->GetPosition()), FColor::White, 5.0f));
	// }
	return Ret;
}

FBoxSphereBounds UWaypointGraphVisualComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	FBoxSphereBounds B = Super::CalcBounds(LocalToWorld);

	AWaypointGraph* WaypointGraph = Cast<AWaypointGraph>(GetOwner());

	// for (UWaypointConnection* Connection : WaypointGraph->Connections)
	// {
	// 	FVector Extents = Connection->StartWaypoint->GetPosition().GetAbs().ComponentMax(Connection->EndWaypoint->GetPosition().GetAbs());
	// 	B = B + FBoxSphereBounds(FVector::ZeroVector, Extents, Extents.GetMax());
	// }
	return B.TransformBy(LocalToWorld);
}
