// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "WaypointConnectionVisualComponent.generated.h"


USTRUCT(BlueprintType)
struct FWaypointConnectionVisualizer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector End;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Thickness;
	
	FWaypointConnectionVisualizer(const FVector& InStart, const FVector& InEnd, const FColor& InColor, const float& InThickness) : Start(InStart), End(InEnd), Color(InColor), Thickness(InThickness)
	{
		
	}

	FWaypointConnectionVisualizer():Start(FVector::ZeroVector),End(FVector(100, 0, 0)),Color(FColor::White),Thickness(5.0f)
	{
		
	}
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WAYPOINTGRAPHEDITOR_API UWaypointConnectionVisualComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWaypointConnectionVisualComponent(const FObjectInitializer& ObjectInitializer);

	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
	virtual bool ShouldRecreateProxyOnUpdateTransform() const override { return true; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWaypointConnectionVisualizer WaypointConnectionVisualizer;
};
