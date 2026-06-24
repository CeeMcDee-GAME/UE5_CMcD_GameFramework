//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Pawn.h"
#include "PatrolUnit.generated.h"

class UQuestSubsystem;
class UStaticMeshComponent;

UCLASS()
class CMCD_GAMEFRAMEWORK_API APatrolUnit : public APawn, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	APatrolUnit();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* AppearanceComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	uint8 TeamID;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual FGenericTeamId GetGenericTeamId() const override;
};
