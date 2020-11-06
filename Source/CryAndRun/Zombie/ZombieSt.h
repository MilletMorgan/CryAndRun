// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ZombieSt.generated.h"



UCLASS()
class CRYANDRUN_API AZombieSt : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AZombieSt();
private:
	int MaxWalkSpeed = 800;
	//UPROPERTY(EditAnywere)
	//primary state value
	float lifePoint = 100.0;
	float damage = 25.0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
