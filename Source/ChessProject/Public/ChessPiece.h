// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessTypes.h"
#include "ChessPiece.generated.h"

UCLASS()
class CHESSPROJECT_API AChessPiece : public AActor
{
	GENERATED_BODY()

private:
	EChessTeam Team;
	
public:	
	// Sets default values for this actor's properties
	AChessPiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ��ġ�� �̵� ������ �� �˻�
	virtual bool Move(enum class EChessRank RankDest,
		enum class EChessFile FileDest, enum class EChessRank RankOrigin,
		enum class EChessFile FileOrigin) const;

	// ��ġ�� ���� ������ �� �˻�
	virtual bool Attack(enum class EChessRank RankDest,
		enum class EChessFile FileDest, enum class EChessRank RankOrigin,
		enum class EChessFile FileOrigin) const;

};
