// Fill out your copyright notice in the Description page of Project Settings.


#include "BipedalCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABipedalCharacter::ABipedalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABipedalCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABipedalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABipedalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABipedalCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABipedalCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &ABipedalCharacter::Attack);
}

void ABipedalCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ABipedalCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void Attack() 
{
	UGameplayStatics::SpawnEmitterAttached(Slash, this, TEXT(FX_Trail_L_02));
}

//void ABipedalCharacter::LookUp(float AxisValue)
//{
//	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
//}

//void ABipedalCharacter::LookRightRate(float AxisValue)
//{
	
//}


