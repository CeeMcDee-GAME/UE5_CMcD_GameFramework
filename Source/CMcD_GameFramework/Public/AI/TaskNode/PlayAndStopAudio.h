//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PlayAndStopAudio.generated.h"

class UAudioComponent;
class USoundBase;

UCLASS()
class CMCD_GAMEFRAMEWORK_API UPlayAndStopAudio : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UPlayAndStopAudio();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* SoundToPlay;
	
private:
	UPROPERTY()
	UAudioComponent* AudioComponent;
};
