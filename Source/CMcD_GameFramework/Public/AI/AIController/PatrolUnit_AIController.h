//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "PatrolUnit_AIController.generated.h"

class UBehaviorTree;

class UAISenseConfig_Sight;

namespace BBKeys
{
	const FName SightKey = TEXT("SightKey");
	const FName InvestigatingKey = TEXT("bIsInvestigating");
}
UCLASS()
class CMCD_GAMEFRAMEWORK_API APatrolUnit_AIController : public AAIController
{
	GENERATED_BODY()

public:
	APatrolUnit_AIController();
	
	virtual void BeginPlay() override;
protected:
	virtual void OnPossess(APawn* InPawn) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Senses")
	UAISenseConfig_Sight* SightConfig;
	
	UFUNCTION()
	void SensedSomething(AActor* SensedActor, FAIStimulus Stimulus);
	
private:
	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;
};
