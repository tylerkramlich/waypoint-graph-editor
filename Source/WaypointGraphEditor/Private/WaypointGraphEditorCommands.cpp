// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaypointGraphEditorCommands.h"

#define LOCTEXT_NAMESPACE "FWaypointGraphModule"

void FWaypointGraphEditorCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "WaypointGraphEditor", "Execute WaypointGraph action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
