// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"

// Sets default values
AZombie::AZombie()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	USkeletalMeshComponent* zombie = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ZombieSt"));
	zombie->SetupAttachment(RootComponent);
	// remplire le chemin de la texture dans les ""
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> zombieAsset(TEXT("/Game/Zombie/ZombieMesh/Zombie_Tpose.Zombie_Tpose"));

	if (zombieAsset.Succeeded()) {
		zombie->SetSkeletalMesh(zombieAsset.Object);
		zombie->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		zombie->SetWorldScale3D(FVector(1.f));
	}
	
}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

