// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "ItemInfo/PZ_BaseItemInfos.h"

#include "UObject/NoExportTypes.h"

#include "PZ_BaseItemUpdateScript.generated.h"


/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class PZ_LOOTSYSTEM_API UPZ_BaseItemUpdateScript : public UObject
{
	GENERATED_BODY()
	
//constructors
public:
	

	UPZ_BaseItemUpdateScript();
	


//.....................................................................................................//

	
//Blueprint methods
public:

	/*
		Execute script
	*/
	virtual void Execute(FItemSpawnInfo& ItemSpawnInfo) {};
};
