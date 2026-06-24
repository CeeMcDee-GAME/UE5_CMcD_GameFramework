//Copyright © 2026 Christiana McDonald. All Rights Reserved.


#include "AI/AIController/PatrolUnit_AIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h" 

void APatrolUnit_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (BehaviorTreeAsset == nullptr) return;
	RunBehaviorTree(BehaviorTreeAsset);
}

APatrolUnit_AIController::APatrolUnit_AIController()
	: SightConfig(CreateDefaultSubobject<UAISenseConfig_Sight>("Sight"))
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("Perception Component");
	
	if (SightConfig)
	{
		SightConfig->SightRadius = 700.0f;
		SightConfig->LoseSightRadius = 900.0f;
		SightConfig->PeripheralVisionAngleDegrees = 180.0f;
		SightConfig->SetMaxAge(5.0f);
		
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	}
	if (PerceptionComponent == nullptr) return;
	
	PerceptionComponent->ConfigureSense(*SightConfig);
}

void APatrolUnit_AIController::BeginPlay()
{
	Super::BeginPlay();
	
	if (PerceptionComponent)
	{
		PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &APatrolUnit_AIController::SensedSomething);
	}
}

void APatrolUnit_AIController::SensedSomething(AActor* SensedActor, FAIStimulus Stimulus)
{
	UBlackboardComponent* BlackboardComponent = GetBlackboardComponent();
	if (BlackboardComponent == nullptr) return;
	
	FAISenseID Sight = UAISense::GetSenseID<UAISense_Sight>();
	
	if (Stimulus.Type == Sight)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			BlackboardComponent->SetValueAsObject(BBKeys::SightKey, SensedActor);
			BlackboardComponent->SetValueAsBool(BBKeys::InvestigatingKey, true);
			
			if (GEngine)
			{
				FString SystemMessage = FString::Printf(TEXT("Hello! I see you! I can't walk, but I see you!"));
				GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Orange, SystemMessage);
			}
		}
		else
		{
			FString SystemMessage = FString::Printf(TEXT("Goodbye for now!"));
			GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Orange, SystemMessage);
			
			BlackboardComponent->ClearValue(BBKeys::SightKey);
			BlackboardComponent->SetValueAsBool(BBKeys::InvestigatingKey, false);
		}
	}
}

