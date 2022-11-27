// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.


#include "LootPullContainer/PZ_LootPullContainer.h"

#include "ItemInfo/PZ_BaseItemInfos.h"
#include "LootSystemComponent/PZ_LootSystemComponent.h"


APZ_LootPullContainer::APZ_LootPullContainer()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APZ_LootPullContainer::BeginPlay()
{
	Super::BeginPlay();

	for( FItemSpawnInfo& LItemSpawnInfo : ItemsInfo )
	{
		LItemSpawnInfo.ItemInfo.SetCurrentItemsInSlotNum(LItemSpawnInfo.ItemInfo.DefaultItemsInSlotNum);

		if( LItemSpawnInfo.LootPullContainer == this )
		{
			LItemSpawnInfo.LootPullContainer = nullptr;
			
			continue;
		}

		if( LItemSpawnInfo.LootPullContainer == nullptr ) continue;

		for( FItemSpawnInfo& LInsidePullItemSpawnInfo : LItemSpawnInfo.LootPullContainer->ItemsInfo )
		{
			if( LInsidePullItemSpawnInfo.LootPullContainer == this ) LInsidePullItemSpawnInfo.LootPullContainer = nullptr;
		}
	}
}


void APZ_LootPullContainer::RequestItem_Implementation(UPZ_LootSystemComponent* RequesterLootComponent)
{
	if( ItemsInfo.Num() < 1 || !IsValid(RequesterLootComponent) ) return;

	if( IsValid(GeneralLootUpdateScript) ) GeneralLootUpdateScript->Execute(this);

	for( FContainerSpawnInfo& LItemSpawnInfo : ItemsInfo )
	{
		if( IsValid(LItemSpawnInfo.ItemUpdateScript) ) LItemSpawnInfo.ItemUpdateScript->Execute(LItemSpawnInfo);
	}
	
	const int WinnerSpawnIndex = ChooseItem();
	
	if( ItemsInfo.IsValidIndex(WinnerSpawnIndex) && ItemsInfo[WinnerSpawnIndex].IsSpawnInfoValid() )
	{
		if( ItemsInfo[WinnerSpawnIndex].IsUseItemForSpawn == false && IsValid(ItemsInfo[WinnerSpawnIndex].LootPullContainer) )
		{
			ItemsInfo[WinnerSpawnIndex].LootPullContainer->RequestItem(RequesterLootComponent);
		}
		else
		{
			RequesterLootComponent->SpawnItem(ItemsInfo[WinnerSpawnIndex]);
		}
	}
}


int APZ_LootPullContainer::ChooseItem_Implementation()
{
	float LTotalWeight = 0.f;
	for( FContainerSpawnInfo& LItemSpawnInfo : ItemsInfo )
	{
		if( IsValid(LItemSpawnInfo.ItemUpdateScript) ) LItemSpawnInfo.ItemUpdateScript->Execute(LItemSpawnInfo);
		
		if( LItemSpawnInfo.ItemInfo.GetCurrentItemsInSlotNum() != 0 ) LTotalWeight += LItemSpawnInfo.WeightToSpawn;
	}
	
	const float LRandNumber = FMath::FRandRange(0, LTotalWeight);
	
	int32 LTempWeight = 0;
	
	for( int i = 0; i < ItemsInfo.Num() && ItemsInfo.IsValidIndex(i); ++i )
	{
		if( ItemsInfo[i].ItemInfo.GetCurrentItemsInSlotNum() != 0 ) LTempWeight += ItemsInfo[i].WeightToSpawn;
		
		if( LTempWeight > LRandNumber ) return i;
	}

	return -1;
}


