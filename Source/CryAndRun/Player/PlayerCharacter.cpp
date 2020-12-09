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

	check(GEngine != nullptr);

	// Display a debug message for three seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Using PlayerCharacter."));
	 
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

	// Sprint bindings
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &APlayerCharacter::StopCrouch);

}

// avant arriere
void APlayerCharacter::MoveForward(float Value)
{

	if ((Controller) && (Value != 0.0f)) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);

	}
}
// droite gauche
void APlayerCharacter::MoveRight(float Value)
{

	if ((Controller) && (Value != 0.0f)) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Value);

	}
}

// Fonction qui permet le sprint
void APlayerCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed *= SprintSpeedMulti;
}

// Fonction qui permet la marche 
void APlayerCharacter::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed /= SprintSpeedMulti;
}

// Fonction pour s'accroupir
void APlayerCharacter::StartCrouch()
{
	if (!GetCharacterMovement()->IsCrouching())
	{
		GetCharacterMovement()->bWantsToCrouch = true;
		GetCharacterMovement()->Crouch();
	}
}

//Fonction pour stoper accroupi
void APlayerCharacter::StopCrouch()
{
	if (GetCharacterMovement()->IsCrouching())
	{
		GetCharacterMovement()->bWantsToCrouch = false;
		GetCharacterMovement()->UnCrouch();
	}
}

