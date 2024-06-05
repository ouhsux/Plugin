// Fill out your copyright notice in the Description page of Project Settings.

#include "MyParticle.h"
#include "Components/BoxComponent.h"

AMyParticle::AMyParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Create and set the static mesh component as root
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
    UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(RootComponent);
    if (PrimitiveComponent)
    {
         PrimitiveComponent->SetSimulatePhysics(true);
         PrimitiveComponent->SetEnableGravity(true);
         PrimitiveComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    };

     
    UBoxComponent* BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
    BoxCollision->SetupAttachment(RootComponent);
}
     

// Called when the game starts or when spawned
void AMyParticle::BeginPlay()
{
	Super::BeginPlay();
  
}

// Called every frame
void AMyParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    starttime += DeltaTime;
    if (starttime >= livetime) Destroy();

    if (setval) {
        FVector CurrentScale = MeshComponent->GetComponentScale();
        FVector NewScale = CurrentScale * Scale;
        MeshComponent->SetWorldScale3D(NewScale);

        FVector ConeVertex = GetActorLocation();
    
     /*   float ConeRadius = 100.0f;
        float ConeHeight = 1000.0f;*/
        FVector ConeDirection = FVector(0.0f, 0.0f, 1.0f);
        FVector RandomConeDirection = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(ConeDirection, 45.0f);
       
        FVector InitialVelocity = Speed * RandomConeDirection;
        UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetRootComponent());
        PrimitiveComponent->SetPhysicsLinearVelocity(InitialVelocity);
        setval = false;
    }
   
}

void AMyParticle::SetVal(UMaterialInterface* NewMaterial, UStaticMesh* NewMesh, float speed, float scale)
{ 
    if (MeshComponent && NewMaterial)
    {
        MeshComponent->SetMaterial(0, NewMaterial);
    }
    if (MeshComponent && NewMesh)
    {
        MeshComponent->SetStaticMesh(NewMesh);
    }
    Speed = speed;
    Scale = scale;
}



