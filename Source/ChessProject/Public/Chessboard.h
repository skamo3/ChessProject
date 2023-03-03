// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessTypes.h"
#include "Chessboard.generated.h"


enum class EChessFile : uint8;
enum class EChessRank : uint8;

UCLASS()
class CHESSPROJECT_API AChessboard : public AActor
{
	GENERATED_BODY()
	
private:
	
public:	
	// Sets default values for this actor's properties
	AChessboard();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Board")
		TArray<class AChessPiece*> Pieces;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf<class AChessPawn> ChessPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf<class AChessRook> ChessRook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf<class AChessKnight> ChessKnight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf<class AChessBishop> ChessBishop;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf<class AChessQueen> ChessQueen;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf<class AChessKing> ChessKing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Location")
		class UDataTable* ChessPieceData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* ChessBoard;

	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<class UUserWidget> PathFinderWidgetClass;

	UPROPERTY()
		class UWidgetComponent* PathFinderWidgetComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void SpawnPiece(const TSubclassOf<class AChessPiece> piece, const FChessDataRow& Row);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ChessPiece* GetPiece(EChessFile File, EChessRank Rank);
	bool MovePiece(EChessFile FileDest, EChessRank RankDest, EChessFile FileOrigin, EChessRank RankOrigin);

	void printBoard();

	void LocatingPiece(AChessPiece* TargetPiece, EChessFile FileDest, EChessRank RankDest);
};
