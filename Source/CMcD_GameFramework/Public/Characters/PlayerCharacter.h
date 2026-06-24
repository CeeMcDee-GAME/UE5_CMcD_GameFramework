//Copyright © 2026 Christiana McDonald. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "ActorComponents/Attack.h"
#include "GameFramework/Character.h"
#include "Interfaces/Interact.h"
#include "SceneComponents/EquipUnequip_WeaponsArmor.h"
#include "PlayerCharacter.generated.h"

class UUserWidget;
class UEquipUnequip_WeaponsArmor;
class UAIPerceptionStimuliSourceComponent;
class USkeletalMeshComponent;
class UAttack;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEquipmentChangedSignature, const FString&, Message, AActor*, Speaker);
UCLASS()
class CMCD_GAMEFRAMEWORK_API APlayerCharacter : public ACharacter, public IGenericTeamAgentInterface, public IInteract
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
	FOnEquipmentChangedSignature OnEquipmentChanged;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAttack* Attack;
	
	UPROPERTY(BlueprintReadOnly, Category = "Equipment")
	TMap<EArmorType, USkeletalMeshComponent*> ArmorSlot;
	
	UPROPERTY()
	float BaseDefense = 10.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float TotalDefense = 0.0f;
	
	UPROPERTY()
	float BaseWeight = 50.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float TotalWeight = 0.0f;
	
	UPROPERTY()
	float BaseDamage = 10.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float TotalDamage = 0.0f;
	
	UPROPERTY()
	float BaseAttackSpeed = 20.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float TotalAttackSpeed = 0.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* HeadSlot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* ChestSlot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MainHandSlot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEquipUnequip_WeaponsArmor* EquipmentComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionStimuliSourceComponent* StimuliSourceComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	uint8 TeamID;
	
private:
	UPROPERTY()
	AActor* CurrentAttackTarget = nullptr;
	
public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void PlayerAttacksEnemy();
	
	virtual void InteractWithTarget_Implementation(AActor* Target) override;
	
	virtual FGenericTeamId GetGenericTeamId() const override;
	
	UFUNCTION()
	void UpdateWeapon(const FWeaponDelegate& WeaponStats);
	
	UFUNCTION()
	void UpdateArmor(const FArmorDelegate& ArmorStats);
};
