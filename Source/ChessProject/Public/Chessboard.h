// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chessboard.generated.h"

UCLASS()
class CHESSPROJECT_API AChessboard : public AActor
{
	GENERATED_BODY()
	
private:

	TArray<class ChessPiece*> Pieces;

public:	
	// Sets default values for this actor's properties
	AChessboard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ChessPiece* GetPiece(enum class EChessRank Rank, enum class EChessFile File);
	bool MovePiece(enum class EChessRank RankDest, enum class EChessFile FileDest, enum class EChessRank RankOrigin, enum class EChessFile FileOrigin);

};
