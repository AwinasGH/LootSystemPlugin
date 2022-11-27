// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.


#include "LootSystemComponent/PZ_LootSystemComponent.h"

#include "LootPullContainer/PZ_LootPullContainer.h"


UPZ_LootSystemComponent::UPZ_LootSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPZ_LootSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	for( FItemSpawnInfo& LItemSpawnInfo : PullToSpawnInfo )
	{
		LItemSpawnInfo.ItemInfo.SetCurrentItemsInSlotNum(LItemSpawnInfo.ItemInfo.DefaultItemsInSlotNum);
	}
}


void UPZ_LootSystemComponent::DropItems()
{
	if( PullToSpawnInfo.Num() == 0 ) return;

	
	float LTotalWeight = 0.f;
	for( const FItemSpawnInfo& LDropSpawnInfo : PullToSpawnInfo )
	{
		LTotalWeight += LDropSpawnInfo.WeightToSpawn;
	}
	LTotalWeight += WeightToSpawnNothing;
	

	TArray<int> WinnersIndexesArray;
	
	for( int i = 0; i < ItemsSpawnNum ; ++i )
	{
		const float LRandNumber = FMath::FRandRange(0, LTotalWeight);

		int32 LTempWeight = 0;
		for( int j = 0; j < PullToSpawnInfo.Num() && PullToSpawnInfo.IsValidIndex(j) ; ++j )
		{
			if( PullToSpawnInfo[j].ItemInfo.GetCurrentItemsInSlotNum() != 0 ) LTempWeight += PullToSpawnInfo[j].WeightToSpawn;
		
			if( LTempWeight > LRandNumber )
			{
				WinnersIndexesArray.Add(j);

				break;
			}
		}
	}

	for( int i = 0; i < ItemsSpawnNum ; ++i )
	{
		for( int j = 0; j < PullToSpawnInfo.Num() && PullToSpawnInfo.IsValidIndex(j); ++j  )
		{
			if ( !WinnersIndexesArray.Contains(j) ) continue;
			WinnersIndexesArray.RemoveSingle(j);
			

			if ( !PullToSpawnInfo[j].IsSpawnInfoValid() ) continue;
			
			
			if ( PullToSpawnInfo[j].IsUseItemForSpawn == false && IsValid(PullToSpawnInfo[j].LootPullContainer) )
			{
				PullToSpawnInfo[j].LootPullContainer->RequestItem(this);
			}
			else 
			{
				SpawnItem(PullToSpawnInfo[j]);
			}

			break;
		}
	}
}

bool UPZ_LootSystemComponent::ItemSpawnLogic_Implementation(const FItemSpawnInfo& ItemSpawnInfo)
{
	return false;//TODO on child
}

bool UPZ_LootSystemComponent::SpawnItem(FItemSpawnInfo& ItemSpawnInfo)
{
	if( ItemSpawnLogic(ItemSpawnInfo) )
	{
		if ( ItemSpawnInfo.ItemInfo.GetCurrentItemsInSlotNum() != 0 )
		{
			ItemSpawnInfo.ItemInfo.SetCurrentItemsInSlotNum(ItemSpawnInfo.ItemInfo.GetCurrentItemsInSlotNum() - 1);
		}
		
		OnItemSpawned(ItemSpawnInfo);
		OnItemSpawnedBind.Broadcast(ItemSpawnInfo.ItemInfo);

		return true;
	}

	return false;
}



