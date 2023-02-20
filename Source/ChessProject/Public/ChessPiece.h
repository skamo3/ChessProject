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

	UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetTeam, BlueprintSetter = SetTeam, Category = State)
	EChessTeam Team;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetType, BlueprintSetter = SetType, Category = State)
	EChessType Type;
	
public:	
	// Sets default values for this actor's properties
	AChessPiece();

protected:

	UPROPERTY(VisibleAnywhere, Category = Scene)
		class USceneComponent* Scene;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;

	//UPROPERTY(EditAnywhere, Category = "Materials")
	//	UMaterialInterface* NormalMat;

	//UPROPERTY(EditAnywhere, Category = "Materials")
	//	UMaterialInterface* HighlightMat;



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 위치로 이동 가능한 지 검사
	virtual bool Move(EChessRank RankDest,
		EChessFile FileDest, EChessRank RankOrigin,
		EChessFile FileOrigin) const;

	// 위치로 공격 가능한 지 검사
	virtual bool Attack(EChessRank RankDest,
		EChessFile FileDest, EChessRank RankOrigin,
		EChessFile FileOrigin) const;

	UFUNCTION()
	void OnClickMesh(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	UFUNCTION()
		void OnMouseOverMesh(UPrimitiveComponent* Component);

	UFUNCTION()
		void OnMouseEndMesh(UPrimitiveComponent* Component);


	UFUNCTION(BlueprintGetter, Category = getter)
		EChessTeam GetTeam();

	UFUNCTION(BlueprintGetter, Category = getter)
		EChessType GetType();

	UFUNCTION(BlueprintSetter, Category = setter)
		void SetTeam(EChessTeam newTeam);

	UFUNCTION(BlueprintSetter, Category = setter)
		void SetType(EChessType newType);
};
