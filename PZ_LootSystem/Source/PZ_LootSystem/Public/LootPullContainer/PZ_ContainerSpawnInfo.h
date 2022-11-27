#pragma once

#include "CoreMinimal.h"


//...........................LootSystem\Inventory\Interactive include..............................//

#include "ItemInfo/PZ_BaseItemInfos.h"
#include "LootItemUpdateScript/PZ_BaseItemUpdateScript.h"

//..................................................................................................//


#include "PZ_ContainerSpawnInfo.generated.h"




class APZ_LootPullContainer;






USTRUCT(BlueprintType)
struct FContainerSpawnInfo : public FItemSpawnInfo
{
	GENERATED_USTRUCT_BODY();


	FContainerSpawnInfo(){};
	
	
//.....................................................................................................//


//Blueprint values
public:
	

	/*
		This item update script. Doesn't depend on the general
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category = "Default", meta=(EditCondition = "UseItemToSpawn"))
		UPZ_BaseItemUpdateScript* ItemUpdateScript = nullptr;
};

	
