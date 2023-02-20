// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHESSPROJECT_API AChessGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

protected:
	virtual void BeginPlay() override;

public:
	AChessGamePlayerController();

};
