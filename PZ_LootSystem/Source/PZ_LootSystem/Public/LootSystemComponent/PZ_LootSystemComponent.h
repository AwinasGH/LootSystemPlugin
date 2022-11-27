// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "PZ_PullSpawnInfo.h"

#include "Components/ActorComponent.h"

#include "ItemInfo/PZ_BaseItemInfos.h"

#include "PZ_LootSystemComponent.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemSpawned, const FItemInfo&, ItemInfo);



/*
 *	Component which contains spawn info(references to LootContainers, direct ItemInfo, ...) and execute spawn. 
*/
UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PZ_LOOTSYSTEM_API UPZ_LootSystemComponent : public UActorComponent
{
	GENERATED_BODY()
	

//constructor
public:

	UPZ_LootSystemComponent();

//constructor
public:

	virtual void BeginPlay() override;
	

//>>....................................................................................................................................................................<<//


//Blueprint public methods
public:

	/*
		Runs through the pool and request(for spawn) or spawn(directly) items.
	*/
	UFUNCTION(BlueprintCallable, Category = "LootSystemComponent|Spawn")
		virtual void DropItems();
	/*
		Spawn item directly
	*/
	UFUNCTION(BlueprintCallable, Category = "LootSystemComponent|Spawn")
		virtual bool SpawnItem(UPARAM(ref)FItemSpawnInfo& ItemSpawnInfo);
	

//Blueprint protected methods
protected:
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected), BlueprintNativeEvent, Category = "LootSystemComponent|Spawn")
		bool CanSpawnItem(const FItemSpawnInfo& ItemSpawnInfo);
		virtual bool CanSpawnItem_Implementation(const FItemSpawnInfo& ItemSpawnInfo) { return false; };
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected), BlueprintNativeEvent, Category = "LootSystemComponent|Spawn")
		bool ItemSpawnLogic(const FItemSpawnInfo& ItemSpawnInfo);
		virtual bool ItemSpawnLogic_Implementation(const FItemSpawnInfo& ItemSpawnInfo);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected), BlueprintNativeEvent, Category = "LootSystemComponent|Spawn")
		void OnItemSpawned(const FItemSpawnInfo& ItemSpawnInfo);
		virtual void OnItemSpawned_Implementation(const FItemSpawnInfo& ItemSpawnInfo){};
	

//Blueprint values
protected:
	
	/*
		On item spawn delegate
	*/
	UPROPERTY(BlueprintAssignable, Category = "LootSystemComponent|EventsForBind")
		FOnItemSpawned OnItemSpawnedBind;
	
	/*
		Pull of containers with drop info to spawn
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootSystemComponent|Default")
		TArray<FItemSpawnInfo> PullToSpawnInfo;
	/*
		Items num to spawn
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin = 1))
		int ItemsSpawnNum = 1;
	/*
		Weight to spawn nothing
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin = 0.0f))
		float WeightToSpawnNothing = 0.0f;
};
