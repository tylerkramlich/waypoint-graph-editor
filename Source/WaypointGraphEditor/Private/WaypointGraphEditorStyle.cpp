// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaypointGraphEditorStyle.h"
#include "WaypointGraphEditorModule.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FWaypointGraphEditorStyle::StyleInstance = nullptr;

void FWaypointGraphEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FWaypointGraphEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FWaypointGraphEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("WaypointGraphEditorStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FWaypointGraphEditorStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("WaypointGraphEditorStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("WaypointGraphEditor")->GetBaseDir() / TEXT("Resources"));

	Style->Set("WaypointGraphEditor.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FWaypointGraphEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FWaypointGraphEditorStyle::Get()
{
	return *StyleInstance;
}
