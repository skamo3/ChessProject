// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPiece.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AChessPiece::AChessPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	check(Scene);
	RootComponent = Scene;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChessBody"));
	check(Mesh);
	Mesh->SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void AChessPiece::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnClicked.AddDynamic(this, &AChessPiece::OnClickMesh);
	Mesh->OnBeginCursorOver.AddDynamic(this, &AChessPiece::OnMouseOverMesh);
	Mesh->OnEndCursorOver.AddDynamic(this, &AChessPiece::OnMouseEndMesh);
	
}

// Called every frame
void AChessPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


bool AChessPiece::Move(EChessRank RankDest, EChessFile FileDest, EChessRank RankOrigin, EChessFile FileOrigin) const
{
	return false;
}

bool AChessPiece::Attack(EChessRank RankDest, EChessFile FileDest, EChessRank RankOrigin, EChessFile FileOrigin) const
{
	return false;
}

void AChessPiece::OnClickMesh(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	UE_LOG(LogTemp, Warning, TEXT("Test click on pieces"));
	FVector otherColor = FVector(0.3, 0.2, 0);
	Mesh->SetVectorParameterValueOnMaterials(TEXT("Color"), otherColor);
}

void AChessPiece::OnMouseOverMesh(UPrimitiveComponent* ClickedComp)
{
	UE_LOG(LogTemp, Warning, TEXT("Test Over on pieces"));

}

void AChessPiece::OnMouseEndMesh(UPrimitiveComponent* Component)
{
	UE_LOG(LogTemp, Warning, TEXT("Test End on pieces"));
}

EChessTeam AChessPiece::GetTeam()
{
	return Team;
}

EChessType AChessPiece::GetType()
{
	return Type;
}

void AChessPiece::SetTeam(EChessTeam newTeam)
{
	Team = newTeam;
}

void AChessPiece::SetType(EChessType newType)
{
	Type = newType;
}
