//Copyright © 2026 Christiana McDonald. All Rights Reserved.


#include "Pawns/PatrolUnit.h"
#include "Miscellaneous/TeamAffiliation.h"

APatrolUnit::APatrolUnit()
	: AppearanceComponent(CreateDefaultSubobject<UStaticMeshComponent>("Appearance"))
{
	PrimaryActorTick.bCanEverTick = false;
	
	AppearanceComponent->SetupAttachment(RootComponent);
	
	TeamID = static_cast<uint8>(ETeamAffiliation::Enemies);
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void APatrolUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

void APatrolUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APatrolUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FGenericTeamId APatrolUnit::GetGenericTeamId() const
{
	return FGenericTeamId(TeamID);
}
