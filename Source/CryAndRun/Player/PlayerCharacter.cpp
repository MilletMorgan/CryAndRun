// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SprintSpeedMulti = 1.7f;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	 
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// Set up "look" bindings.
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);

	// Set up "jump" bindings.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJumping);

	// Sprint bindings
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::Walk);

}

void APlayerCharacter::MoveForward(float Value)
{

	if ((Controller) && (Value != 0.0f)) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);

	}
}

void APlayerCharacter::MoveRight(float Value)
{

	if ((Controller) && (Value != 0.0f)) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Value);

	}
}

void APlayerCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed *= SprintSpeedMulti;
}

void APlayerCharacter::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed /= SprintSpeedMulti;
}

