#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ChessTypes.generated.h"

UENUM(BlueprintType)
enum class EChessRank : uint8
{
	Rank1	UMETA(DisplayName = "Rank1"),
	Rank2	UMETA(DisplayName = "Rank2"),
	Rank3	UMETA(DisplayName = "Rank3"),
	Rank4	UMETA(DisplayName = "Rank4"),
	Rank5	UMETA(DisplayName = "Rank5"),
	Rank6	UMETA(DisplayName = "Rank6"),
	Rank7	UMETA(DisplayName = "Rank7"),
	Rank8	UMETA(DisplayName = "Rank8"),
	MaxNum	UMETA(DisplayName = "MaxRank"),
};

UENUM(BlueprintType)
enum class EChessFile : uint8
{
	FileA	UMETA(DisplayName = "FileA"),
	FileB	UMETA(DisplayName = "FileB"),
	FileC	UMETA(DisplayName = "FileC"),
	FileD	UMETA(DisplayName = "FileD"),
	FileE	UMETA(DisplayName = "FileE"),
	FileF	UMETA(DisplayName = "FileF"),
	FileG	UMETA(DisplayName = "FileG"),
	FileH	UMETA(DisplayName = "FileH"),
	MaxNum	UMETA(DisplayName = "MaxFile"),
};

UENUM(BlueprintType)
enum class EChessTeam : uint8
{
	Black	UMETA(DisplayName = "Black"),
	White	UMETA(DisplayName = "White"),
	MaxNum	UMETA(DisplayName = "MaxNum"),
};

UENUM(BlueprintType)
enum class EChessType : uint8
{
	Pawn	UMETA(DisplayName = "Pawn"),
	Rook	UMETA(DisplayName = "Rook"),
	Knight	UMETA(DisplayName = "Knight"),
	Bishop	UMETA(DisplayName = "Bishop"),
	Queen	UMETA(DisplayName = "Queen"),
	King	UMETA(DisplayName = "King"),
	MaxNum	UMETA(DisplayName = "MaxNum"),
};

USTRUCT(Atomic, BlueprintType)
struct FChessDataRow : public FTableRowBase
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
		FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
		EChessType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
		EChessTeam Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
		EChessRank Rank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
		EChessFile File;


};