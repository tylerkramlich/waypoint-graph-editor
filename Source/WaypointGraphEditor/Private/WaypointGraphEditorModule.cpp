// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaypointGraphEditorModule.h"

#include "ToolMenus.h"
#include "WaypointGraphEditorCommands.h"
#include "WaypointGraphEditorStyle.h"
#include "Blutility/Classes/EditorUtilityWidgetBlueprint.h"
#include "Blutility/Public/EditorUtilitySubsystem.h"
#include "EditorAssetLibrary.h"

static const FName WaypointGraphTabName("WaypointGraphEditor");

#define LOCTEXT_NAMESPACE "FWaypointGraphEditorModule"

void FWaypointGraphEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FWaypointGraphEditorStyle::Initialize();
	FWaypointGraphEditorStyle::ReloadTextures();

	FWaypointGraphEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FWaypointGraphEditorCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FWaypointGraphEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FWaypointGraphEditorModule::RegisterMenus));
}

void FWaypointGraphEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FWaypointGraphEditorStyle::Shutdown();

	FWaypointGraphEditorCommands::Unregister();
}

void FWaypointGraphEditorModule::PluginButtonClicked()
{
	UObject* Blueprint = UEditorAssetLibrary::LoadAsset(FString(TEXT("/Script/Blutility.EditorUtilityWidgetBlueprint'/WaypointGraph/WaypointGraphWidget.WaypointGraphWidget'")));
	if (IsValid(Blueprint))
	{
		UEditorUtilityWidgetBlueprint* EditorWidget = Cast<UEditorUtilityWidgetBlueprint>(Blueprint);
		if (IsValid(EditorWidget))
		{
			UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
			EditorUtilitySubsystem->SpawnAndRegisterTab(EditorWidget);
		}
	}
}

void FWaypointGraphEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FWaypointGraphEditorCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FWaypointGraphEditorCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWaypointGraphEditorModule, WaypointGraphEditor)