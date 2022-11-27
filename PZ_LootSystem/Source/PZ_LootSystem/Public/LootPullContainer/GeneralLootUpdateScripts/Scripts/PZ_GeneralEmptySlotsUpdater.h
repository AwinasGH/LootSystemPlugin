// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "LootPullContainer/GeneralLootUpdateScripts/PZ_BaseGeneralLootUpdateScript.h"
#include "PZ_GeneralEmptySlotsUpdater.generated.h"

/**
 * 
 */
UCLASS()
class PZ_LOOTSYSTEM_API UPZ_GeneralEmptySlotsUpdater : public UPZ_BaseGeneralLootUpdateScript
{
	GENERATED_BODY()


//constructors
public:

	UPZ_GeneralEmptySlotsUpdater();


//c++ methods
public:

	virtual void Execute_Implementation(APZ_LootPullContainer* LootPullContainer) override;

//.....................................................................................................//
	
};
