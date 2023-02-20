// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPlayerCharacter.h"

// Sets default values
AChessPlayerCharacter::AChessPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bSimGravityDisabled = false;

}

// Called when the game starts or when spawned
void AChessPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChessPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChessPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

