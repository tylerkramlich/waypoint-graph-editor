﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Waypoint.h"

#include "WaypointConnection.h"
#include "WaypointVisualComponent.h"


// Sets default values
AWaypoint::AWaypoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

#if WITH_EDITOR
	VisualComponent = CreateDefaultSubobject<UWaypointVisualComponent>("WaypointVisual");
	VisualComponent->SetupAttachment(GetRootComponent());
#endif
	
}

// Called when the game starts or when spawned
void AWaypoint::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

