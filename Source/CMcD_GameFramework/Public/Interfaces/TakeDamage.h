//Copyright © 2026 Christiana McDonald. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TakeDamage.generated.h"

UINTERFACE(MinimalAPI)
class UTakeDamage : public UInterface
{
	GENERATED_BODY()
};

class CMCD_GAMEFRAMEWORK_API ITakeDamage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void DamageEnemy(float DamageAmount);
	//float GetCurrentHealth(); //A getter function for later use. It isn't/hasn't been implemented in this code as of right now as it isn't needed.
};
