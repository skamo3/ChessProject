// Fill out your copyright notice in the Description page of Project Settings.

#include "Chessboard.h"
#include "Engine/StaticMesh.h"
#include "Engine/TargetPoint.h"
#include "Logging/LogMacros.h"
#include "Engine/StaticMeshSocket.h"
#include "ChessPawn.h"
#include "ChessRook.h"
#include "ChessBishop.h"
#include "ChessKnight.h"
#include "ChessQueen.h"
#include "ChessKing.h"

// Sets default values
AChessboard::AChessboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChessBoard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChessBoard"));
	check(ChessBoard);
	ChessBoard->SetupAttachment(RootComponent);

	Pieces.Init(nullptr, static_cast<int32>(EChessFile::MaxNum) *
		static_cast<int32>(EChessRank::MaxNum));

}

// Called when the game starts or when spawned
void AChessboard::BeginPlay()
{
	Super::BeginPlay();

	if (ChessPieceData != nullptr)
	{
		// ChessPieceData->

		FString ContextString;
		TArray<FChessDataRow*> Rows;
		ChessPieceData->GetAllRows<FChessDataRow>(ContextString, Rows);
		for (FChessDataRow* Row : Rows)
		{
			switch (Row->Type)
			{
			case EChessType::Pawn:
				SpawnPiece(ChessPawn, *Row);
				break;
			case EChessType::Rook:
				SpawnPiece(ChessRook, *Row);
				break;
			case EChessType::Knight:
				SpawnPiece(ChessKnight, *Row);
				break;
			case EChessType::Bishop:
				SpawnPiece(ChessBishop, *Row);
				break;
			case EChessType::Queen:
				SpawnPiece(ChessQueen, *Row);
				break;
			case EChessType::King:
				SpawnPiece(ChessKing, *Row);
				break;
			default:
				break;
			}
		}
		
		printBoard();
	}
	
}

// Called every frame
void AChessboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// TODO: return Piece(Rank, File);
ChessPiece* AChessboard::GetPiece(EChessFile File, EChessRank Rank)
{
	return nullptr;
}

bool AChessboard::MovePiece(EChessFile FileDest, EChessRank RankDest,
	EChessFile FileOrigin, EChessRank RankOrigin)
{
	/*
	*	board에서 이동할 곳에 말이 있으면 제거
	*	말 이동
	*	이동 후 원래 자리는 0으로 초기화
	*/
	return false;
}

void AChessboard::SpawnPiece(const TSubclassOf<class AChessPiece> piece, const FChessDataRow& Row)
{
	check(piece);

	AChessPiece* newPiece;

	newPiece = GetWorld()->SpawnActor<AChessPiece>(piece, GetActorLocation() + Row.Location,
		FRotator::ZeroRotator);
	newPiece->SetOwner(this);
	newPiece->SetTeam(Row.Team);
	newPiece->SetType(Row.Type);

	LocatingPiece(newPiece, Row.File, Row.Rank);
}

void AChessboard::printBoard()
{

	FString boardtext("Board:\n\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Pieces[i * 8 + j] == nullptr)
				boardtext += "=";
			else
				boardtext += "0";
		}
		boardtext += "\n";
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *boardtext);
}

void AChessboard::LocatingPiece(AChessPiece* TargetPiece, EChessFile FileDest, EChessRank RankDest)
{

	int targetLocation = static_cast<int>(FileDest)+ (static_cast<int>(RankDest) * 8);
	if (Pieces[targetLocation] != nullptr)
		Pieces[targetLocation]->Destroy();
	Pieces[targetLocation] = TargetPiece;
}

