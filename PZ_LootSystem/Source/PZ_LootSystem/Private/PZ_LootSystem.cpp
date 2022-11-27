// Copyright Epic Games, Inc. All Rights Reserved.

#include "PZ_LootSystem.h"

#define LOCTEXT_NAMESPACE "FPZ_LootSystemModule"

void FPZ_LootSystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FPZ_LootSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPZ_LootSystemModule, PZ_LootSystem)