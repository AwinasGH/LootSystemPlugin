// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PZ_ContainerSpawnInfo.h"

#include "GameFramework/Actor.h"

#include "GeneralLootUpdateScripts/PZ_BaseGeneralLootUpdateScript.h"


#include "PZ_LootPullContainer.generated.h"


class UPZ_LootSystemComponent;


UCLASS()
class PZ_LOOTSYSTEM_API APZ_LootPullContainer : public AActor
{
	GENERATED_BODY()
	

//constructor
public:

	APZ_LootPullContainer();

	friend UPZ_BaseGeneralLootUpdateScript;


//c++ public methods
public:

	virtual void BeginPlay() override;
	

//>>....................................................................................................................................................................<<//

//Blueprint public methods
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "LootPullContainer|Algorithm")
		void RequestItem(UPZ_LootSystemComponent* RequesterLootComponent);
		virtual void RequestItem_Implementation(UPZ_LootSystemComponent* RequesterLootComponent);

	
//Blueprint protected methods
protected:
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected), BlueprintNativeEvent, Category = "LootPullContainer|Algorithm")
		int ChooseItem();
		virtual int ChooseItem_Implementation();

//Blueprint values
public:

	/*
		General Loot update script
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category = "Default")
		UPZ_BaseGeneralLootUpdateScript* GeneralLootUpdateScript = nullptr;
	/*
		Array of Items info
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		TArray<FContainerSpawnInfo> ItemsInfo;
};
