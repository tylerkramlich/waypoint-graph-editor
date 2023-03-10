// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "WaypointVisualComponent.generated.h"


USTRUCT(BlueprintType)
struct WAYPOINTGRAPHEDITOR_API FWaypointVisualizer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumSegments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Thickness;
	
	FWaypointVisualizer(const FVector& InLocation, const FRotator& InRotation, float InRadius, int InNumSegments, const FColor& InColor, float InThickness) :
	Location(InLocation), Rotation(InRotation), Radius(InRadius), NumSegments(InNumSegments), Color(InColor), Thickness(InThickness)
	{
		
	}

	FWaypointVisualizer():
		Location(FVector::ZeroVector),
		Rotation(FRotator::ZeroRotator),
		Radius(50), NumSegments(12), Color(FColor::White), Thickness(5.0f)
	{
		
	}
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WAYPOINTGRAPHEDITOR_API UWaypointVisualComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWaypointVisualComponent(const FObjectInitializer& ObjectInitializer);

	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
	virtual bool ShouldRecreateProxyOnUpdateTransform() const override { return true; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWaypointVisualizer WaypointVisualizer;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite);
	// TArray<FWaypointConnectionVisualizer> WaypointConnectionsVisualizers;
};
