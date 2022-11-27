// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.


#include "LootPullContainer/LootItemUpdateScript/Scripts/PZ_ItemEmptySlotUpdateScript.h"



UPZ_ItemEmptySlotUpdateScript::UPZ_ItemEmptySlotUpdateScript()
{
	
}

void UPZ_ItemEmptySlotUpdateScript::Execute(FItemSpawnInfo& ItemSpawnInfo)
{
	if( ItemSpawnInfo.ItemInfo.GetCurrentItemsInSlotNum() == 0 )
	{
		ItemSpawnInfo.ItemInfo.SetCurrentItemsInSlotNum(ItemSpawnInfo.ItemInfo.DefaultItemsInSlotNum);
	}
}

