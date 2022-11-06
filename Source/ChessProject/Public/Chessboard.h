// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chessboard.generated.h"

UENUM()
enum class EChessRank
{
	Rank1,
	Rank2,
	Rank3,
	Rank4,
	Rank5,
	Rank6,
	Rank7,
	Rank8,
};

UENUM()
enum class EChessFile
{
	FileA,
	FileB,
	FileC,
	FileD,
	FileE,
	FileF,
	FileG,
	FileH,
};

UCLASS()
class CHESSPROJECT_API AChessboard : public AActor
{
	GENERATED_BODY()
	
private:

	TArray<class ChessPiece> Pieces;

public:	
	// Sets default values for this actor's properties
	AChessboard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ChessPiece* GetPiece(EChessRank Rank, EChessFile File);
	bool MovePiece(EChessRank RankDest, EChessFile FileDest, EChessRank RankOrigin, EChessFile FileOrigin);

};
