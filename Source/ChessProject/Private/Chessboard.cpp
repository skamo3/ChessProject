// Fill out your copyright notice in the Description page of Project Settings.


#include "Chessboard.h"
#include "ChessTypes.h"

// Sets default values
AChessboard::AChessboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChessboard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChessboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// TODO: return Piece(Rank, File);
ChessPiece* AChessboard::GetPiece(enum class EChessRank Rank, enum class EChessFile File)
{
	return nullptr;
}

bool AChessboard::MovePiece(enum class EChessRank RankDest, enum class EChessFile FileDest,
	enum class EChessRank RankOrigin, enum class EChessFile FileOrigin)
{
	/*
	*	board���� �̵��� ���� ���� ������ ����
	*	�� �̵�
	*	�̵� �� ���� �ڸ��� 0���� �ʱ�ȭ
	*/
	return false;
}

