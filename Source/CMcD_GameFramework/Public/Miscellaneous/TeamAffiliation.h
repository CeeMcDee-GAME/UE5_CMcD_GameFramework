//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ETeamAffiliation : uint8
{
	Player = 0,
	Enemies = 1,
	Neutrals = 255
};