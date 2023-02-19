// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "WaypointGraphEditorStyle.h"

class FWaypointGraphEditorCommands : public TCommands<FWaypointGraphEditorCommands>
{
public:

	FWaypointGraphEditorCommands()
		: TCommands<FWaypointGraphEditorCommands>(TEXT("WaypointGraphEditor"), NSLOCTEXT("Contexts", "WaypointGraphEditor", "WaypointGraphEditor Plugin"), NAME_None, FWaypointGraphEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
