//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Base_Weapons.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Sword UMETA(DisplayName = "Sword"),
	Shield UMETA(DisplayName = "Shield"),
	Lance UMETA(DisplayName = "Lance"),
	Gun UMETA(DisplayName = "Gun")
};

USTRUCT(BlueprintType)
struct FWeaponForge : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Armory")
	EWeaponType WeaponType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Armory")
	float Damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Armory")
	float WeaponAttackSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Armory")
	UStaticMesh* WeaponAppearance;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CMCD_GAMEFRAMEWORK_API UBase_Weapons : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBase_Weapons();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
