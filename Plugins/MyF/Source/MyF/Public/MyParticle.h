// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Materials/Material.h"
#include "UObject/Package.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"


#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "MyParticle.generated.h"


UCLASS()
class MYF_API AMyParticle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyParticle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    // Property to hold the static mesh component
    class UStaticMeshComponent* MeshComponent;
    // Function to set the material
    void SetVal(UMaterialInterface* NewMaterial,UStaticMesh* NewMesh,float Speed,float Scale);
	float starttime = 0;
	float livetime = 6.0f;
	bool setval = true;
	float Speed = 500.0f;
	float Scale = 0.1;
};
