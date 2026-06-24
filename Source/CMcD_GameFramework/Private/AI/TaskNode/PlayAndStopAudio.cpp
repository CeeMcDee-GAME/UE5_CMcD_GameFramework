//Copyright © 2026 Christiana McDonald. All Rights Reserved.


#include "AI/TaskNode/PlayAndStopAudio.h"

#include "AIController.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

UPlayAndStopAudio::UPlayAndStopAudio()
{
	NodeName = TEXT("PlayAndStopAudio");
	
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UPlayAndStopAudio::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (SoundToPlay == nullptr) return EBTNodeResult::Failed;
	
	AAIController* FoundAI = OwnerComp.GetAIOwner();
	if (FoundAI == nullptr) return EBTNodeResult::Failed;
	
	APawn* FoundPawn = FoundAI->GetPawn();
	if (FoundPawn == nullptr) return EBTNodeResult::Failed;
	
	USceneComponent* PRootComponent = FoundPawn->GetRootComponent();
	if (PRootComponent == nullptr) return EBTNodeResult::Failed;
	
	AudioComponent = UGameplayStatics::SpawnSoundAttached(SoundToPlay, PRootComponent, FName("None"), FVector::ZeroVector, EAttachLocation::KeepRelativeOffset, false, 1.0f, 1.0f, 0.0f, nullptr, nullptr, true);
	
	if (AudioComponent == nullptr) return EBTNodeResult::Failed;
	
	return EBTNodeResult::InProgress;
}

EBTNodeResult::Type UPlayAndStopAudio::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AudioComponent == nullptr) return EBTNodeResult::Failed;
	if (!AudioComponent->IsPlaying()) return EBTNodeResult::Failed;
	
	AudioComponent->Stop();
	AudioComponent->DestroyComponent();
	
	AudioComponent = nullptr;
	
	return EBTNodeResult::Aborted;
}
