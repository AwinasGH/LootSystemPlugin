// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.


#include "LootPullContainer/GeneralLootUpdateScripts/Scripts/PZ_GeneralEmptySlotsUpdater.h"

#include "LootPullContainer/PZ_LootPullContainer.h"

UPZ_GeneralEmptySlotsUpdater::UPZ_GeneralEmptySlotsUpdater()
{
	
}

void UPZ_GeneralEmptySlotsUpdater::Execute_Implementation(APZ_LootPullContainer* LootPullContainer)
{
	if( !IsValid(LootPullContainer) || LootPullContainer->ItemsInfo.Num() == 0 ) return;
	
	for( int i = 0; i < LootPullContainer->ItemsInfo.Num() && LootPullContainer->ItemsInfo.IsValidIndex(i) ; ++i )
	{
		if( LootPullContainer->ItemsInfo[i].ItemUpdateScript == nullptr )
		{
			if( LootPullContainer->ItemsInfo[i].ItemInfo.GetCurrentItemsInSlotNum() != 0 ) return;
		}
	}

	for( int i = 0; i < LootPullContainer->ItemsInfo.Num() && LootPullContainer->ItemsInfo.IsValidIndex(i) ; ++i )
	{
		if( LootPullContainer->ItemsInfo[i].ItemUpdateScript == nullptr )
		{
			LootPullContainer->ItemsInfo[i].ItemInfo.SetCurrentItemsInSlotNum(LootPullContainer->ItemsInfo[i].ItemInfo.DefaultItemsInSlotNum);
		}
	}
}
