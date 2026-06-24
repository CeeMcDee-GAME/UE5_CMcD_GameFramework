//Copyright © 2026 Christiana McDonald. All Rights Reserved.


#include "SceneComponents/Base_Weapons.h"

// Sets default values for this component's properties
UBase_Weapons::UBase_Weapons()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBase_Weapons::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBase_Weapons::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

