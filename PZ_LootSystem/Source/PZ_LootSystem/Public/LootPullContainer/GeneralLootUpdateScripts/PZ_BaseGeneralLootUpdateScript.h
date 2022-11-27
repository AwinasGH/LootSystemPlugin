// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PZ_BaseGeneralLootUpdateScript.generated.h"

class APZ_LootPullContainer;

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class PZ_LOOTSYSTEM_API UPZ_BaseGeneralLootUpdateScript : public UObject
{
	GENERATED_BODY()


//constructors
public:

	UPZ_BaseGeneralLootUpdateScript();
	


//.....................................................................................................//

	
//Blueprint methods
public:

	/*
		Execute script
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BaseGeneralLootUpdateScript")
		void Execute(APZ_LootPullContainer* LootPullContainer);
		virtual void Execute_Implementation(APZ_LootPullContainer* LootPullContainer) {};
};
