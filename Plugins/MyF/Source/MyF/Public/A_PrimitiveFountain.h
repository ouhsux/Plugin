// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "ActorFactoryEmptyActor.generated.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Runtime\Engine\Public\EngineGlobals.h"
#include "Math/UnrealMathUtility.h" // 包含 FMath 头文件
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime\Engine\Classes\Components\StaticMeshComponent.h"
#include "A_PrimitiveFountain.generated.h"

UCLASS()
class MYF_API AA_PrimitiveFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_PrimitiveFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	float TimerCountdown = 0.0f;
	void gen_particle();
	void SetMM();

	UPROPERTY(EditAnywhere, Category = "Behavior")
	class UMaterialInterface* Material;

	// Property to hold the mesh
	UPROPERTY(EditAnywhere, Category = "Behavior")
	class UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	float Speed =500;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	float Scale = 0.02;
};
