//Copyright © 2026 Christiana McDonald. All Rights Reserved.


#include "Characters/PlayerCharacter.h"
#include "Miscellaneous/TeamAffiliation.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Hearing.h" 
#include "Perception/AISense_Sight.h"


APlayerCharacter::APlayerCharacter()
	: Attack(CreateDefaultSubobject<UAttack>("Attack Component"))
	, EquipmentComponent(CreateDefaultSubobject<UEquipUnequip_WeaponsArmor>("Equipment"))
	, HeadSlot(CreateDefaultSubobject<USkeletalMeshComponent>("Head Slot"))
	, ChestSlot(CreateDefaultSubobject<USkeletalMeshComponent>("Chest Slot"))
	, MainHandSlot(CreateDefaultSubobject<UStaticMeshComponent>("Hand Slot"))
	, StimuliSourceComponent(CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>("Stimuli Source Component"))
{
	PrimaryActorTick.bCanEverTick = false;
	
	
	MainHandSlot->SetupAttachment(GetMesh(), FName("hand_r")); 
	HeadSlot->SetupAttachment(GetMesh(), FName("head")); 
	ChestSlot->SetupAttachment(GetMesh(), FName("spine_03"));
	
	if (StimuliSourceComponent)
	{
		StimuliSourceComponent->bAutoRegister = true;
		StimuliSourceComponent->RegisterForSense(UAISense_Sight::StaticClass());
	}
	
	TeamID = static_cast<uint8>(ETeamAffiliation::Player);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	ArmorSlot.Add(EArmorType::Helmet, HeadSlot);
	ArmorSlot.Add(EArmorType::ChestPiece, ChestSlot);
	
	if (EquipmentComponent == nullptr) return;
	EquipmentComponent->OnWeaponChanged.AddDynamic(this, &APlayerCharacter::UpdateWeapon);
	EquipmentComponent->OnArmorChanged.AddDynamic(this, &APlayerCharacter::UpdateArmor);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::UpdateWeapon(const FWeaponDelegate& WeaponStats)
{
	MainHandSlot->SetStaticMesh(WeaponStats.Mesh);
	TotalDamage = BaseDamage + WeaponStats.WeaponDamage;
	TotalAttackSpeed = BaseAttackSpeed + WeaponStats.WeaponAttackSpeed;
	
	FString Message = FString::Printf(TEXT("Equipped %s | Total Damage: %f | Total Attack Speed: %f."), *WeaponStats.WeaponName.ToString(), TotalDamage, TotalAttackSpeed);
	OnEquipmentChanged.Broadcast(Message, this);
}

void APlayerCharacter::UpdateArmor(const FArmorDelegate& ArmorStats)
{
	TotalDefense = BaseDefense + ArmorStats.Defense;
	TotalWeight = BaseWeight + ArmorStats.Weight;
	
	switch (ArmorStats.BodyAssignment)
	{
	case EArmorType::ChestPiece:
		ChestSlot->SetSkeletalMesh(ArmorStats.Mesh);
		break;
		
	case EArmorType::Helmet:
		HeadSlot->SetSkeletalMesh(ArmorStats.Mesh);
		break;
		
	default:
		break;
	}
	
	FString Message = FString::Printf(TEXT("Equipped %s | Defense: %f | Weight is now %f."), *ArmorStats.ArmorName.ToString(), TotalDefense, TotalWeight);
	OnEquipmentChanged.Broadcast(Message, this);
}

void APlayerCharacter::PlayerAttacksEnemy()
{
	if (Attack == nullptr) return;
	Attack->AttackEnemy(TotalDamage);
}

void APlayerCharacter::InteractWithTarget_Implementation(AActor* Target)
{
	CurrentAttackTarget = Target;
}

FGenericTeamId APlayerCharacter::GetGenericTeamId() const
{
	return FGenericTeamId(TeamID);
}

