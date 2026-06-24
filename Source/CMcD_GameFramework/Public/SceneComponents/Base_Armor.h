//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Base_Armor.generated.h"

UENUM(BlueprintType)
enum class EArmorType : uint8
{
 	Helmet UMETA(DisplayName = "Helmet"),
	ChestPiece UMETA(DisplayName = "Chest Piece")
};

USTRUCT(BlueprintType)
struct FArmorCloset : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Closet")
	EArmorType BodyPartAssignment;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Closet")
	float DefenseRating;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Closet")
	float Weight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Closet")
	USkeletalMesh* ArmorAppearance;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CMCD_GAMEFRAMEWORK_API UBase_Armor : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBase_Armor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
