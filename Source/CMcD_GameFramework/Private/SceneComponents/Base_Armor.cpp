//Copyright © 2026 Christiana McDonald. All Rights Reserved.


#include "SceneComponents/Base_Armor.h"

// Sets default values for this component's properties
UBase_Armor::UBase_Armor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBase_Armor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBase_Armor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

