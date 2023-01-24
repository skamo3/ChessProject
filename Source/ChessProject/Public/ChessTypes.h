#pragma once

#include "CoreMinimal.h"
#include "ChessTypes.generated.h"

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

UENUM()
enum class EChessTeam
{
	Black,
	White,
};