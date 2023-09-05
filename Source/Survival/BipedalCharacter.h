// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Particles/ParticleSystemComponent.h"
#include "BipedalCharacter.generated.h"

UCLASS()
class SURVIVAL_API ABipedalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABipedalCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
    void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	//void LookUp(float AxisValue);
	//void LookRightRate(float AxisValue);

	UPROPERTY(EditAnywhere)
	float RotationRate = 70;

	void Attack()

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent Slash;
};
