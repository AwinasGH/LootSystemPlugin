// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "LootPullContainer/LootItemUpdateScript/PZ_BaseItemUpdateScript.h"

#include "PZ_ItemEmptySlotUpdateScript.generated.h"

/**
 * 
 */
UCLASS()
class PZ_LOOTSYSTEM_API UPZ_ItemEmptySlotUpdateScript : public UPZ_BaseItemUpdateScript
{
	GENERATED_BODY()

	
//constructors
public:

	UPZ_ItemEmptySlotUpdateScript();


//c++ methods
public:

	virtual void Execute(FItemSpawnInfo& ItemSpawnInfo) override;

//.....................................................................................................//
};
