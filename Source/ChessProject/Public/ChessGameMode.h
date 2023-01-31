// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ChessGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHESSPROJECT_API AChessGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:

protected:
	virtual void BeginPlay() override;

public:

	
};
