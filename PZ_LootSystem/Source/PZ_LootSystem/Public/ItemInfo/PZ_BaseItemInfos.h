#pragma once

#include "CoreMinimal.h"


//...........................LootSystem\Inventory\Interactive include..............................//


//..................................................................................................//


#include "PZ_BaseItemInfos.generated.h"

class APZ_LootPullContainer;



USTRUCT(BlueprintType)
struct PZ_LOOTSYSTEM_API FItemInfo
{
	GENERATED_USTRUCT_BODY();


	FItemInfo() {};


//public methods
public:

	FORCEINLINE int GetCurrentItemsInSlotNum() const { return CurrentItemsInSlotNum; };
	
	FORCEINLINE void SetCurrentItemsInSlotNum(int NewNum) { CurrentItemsInSlotNum = NewNum; };

//c++ private values
private:

	/*
		Current items num to spawn
	*/
	int CurrentItemsInSlotNum = 0;
	
	
	//.....................................................................................................//


//Blueprint values
public:
	
	/*
		Stack Range. ONLY FOR STACKABLE
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta=(ClampMin = 1, EditCondition = "UseItemToSpawn"))
		FVector2D StackRange = FVector2D(1, 2);
	/*
		Default Items In Slot Num to spawn
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta=(ClampMin = 1, EditCondition = "UseItemToSpawn"))
		int DefaultItemsInSlotNum = 1;
};



	
USTRUCT(BlueprintType)
struct PZ_LOOTSYSTEM_API FItemSpawnInfo
{
	GENERATED_USTRUCT_BODY();


	FItemSpawnInfo(){}
	
	FItemSpawnInfo(APZ_LootPullContainer* InLootPullContainer) : LootPullContainer(InLootPullContainer) {}

	FItemSpawnInfo(TSubclassOf<AActor> InItemToSpawn) : ItemToSpawnClass(InItemToSpawn) {}


//public methods
public:
	
	FORCEINLINE bool IsSpawnInfoValid() const { return IsUseItemForSpawn ? ItemToSpawnClass.Get() != nullptr : LootPullContainer != nullptr; }
	
//.....................................................................................................//


//Blueprint values
public:

	/*
		Flag. Defines spawn mode - from pull container or ItemToSpawn
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		bool IsUseItemForSpawn = true;

	/*
		Reference to loot pull container which contains items to spawn. IF IsUseItemForSpawn == false
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(EditCondition = "!IsUseItemForSpawn"))
		APZ_LootPullContainer* LootPullContainer = nullptr;

	/*
		Weight to spawn in choose lottery
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta=(ClampMin = 0.0f))
		float WeightToSpawn = 0.0f;
	
	/*
		Item class to spawn
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta=(EditCondition = "IsUseItemForSpawn"))
		TSoftClassPtr<AActor> ItemToSpawnClass = nullptr;
	/*
		Item Info. Contains item's num(default and dynamic value) in slot and it's stack
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta=(EditCondition = "IsUseItemForSpawn"))
		FItemInfo ItemInfo;
};
