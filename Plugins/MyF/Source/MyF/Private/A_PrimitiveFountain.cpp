// Fill out your copyright notice in the Description page of Project Settings.


#include "A_PrimitiveFountain.h"
#include "MyParticle.h"

// Sets default values
AA_PrimitiveFountain::AA_PrimitiveFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SetMM();  
}

// Called when the game starts or when spawned
void AA_PrimitiveFountain::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AA_PrimitiveFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    TimerCountdown -= DeltaTime;
    if (TimerCountdown <= 0.0f )
    {
       
          gen_particle();  
          TimerCountdown = FMath::RandRange(0.1, 0.3);
    }
}

void AA_PrimitiveFountain::gen_particle()
{
  
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }
    FVector SpawnLocation = GetActorLocation();
    FRotator SpawnRotation = FRotator::ZeroRotator;
    FActorSpawnParameters SpawnParameters;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    AMyParticle* particle = World->SpawnActor<AMyParticle>(AMyParticle::StaticClass(), SpawnLocation, SpawnRotation, SpawnParameters);
    if (!particle)
    {
        return;
    }
    particle->SetVal(Material, Mesh, Speed, Scale);
}

void AA_PrimitiveFountain::SetMM()
{
    Material = LoadObject<UMaterial>(nullptr, TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
    Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Script/Engine.StaticMesh'/Engine/EditorMeshes/ArcadeEditorSphere.ArcadeEditorSphere'"));
}


