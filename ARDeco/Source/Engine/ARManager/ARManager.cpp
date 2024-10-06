#include "ARManager.h"
#include "ARBlueprintLibrary.h"
#include "ARSessionConfig.h"
#include "Materials/MaterialInterface.h"
#include "Components/StaticMeshComponent.h"

AARManager::AARManager()
{
    PrimaryActorTick.bCanEverTick = true;
    ARSessionConfig = CreateDefaultSubobject<UARSessionConfig>(TEXT("ARSessionConfig"));
    bShowSelectedPlane = true;
}

// Start AR
void AARManager::BeginPlay()
{
    Super::BeginPlay();
    StartARSession();
}

void AARManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateDetectedPlanes();
}

// Start new AR
void AARManager::StartARSession()
{
    if (ARSessionConfig)
    {
        UARBlueprintLibrary::StartARSession(ARSessionConfig);
    }
}

// Reset AR
void AARManager::ResetARSession()
{
    UARBlueprintLibrary::StopARSession();
    DetectedPlanes.Empty();
    StartARSession();
}

// Show plan
void AARManager::ToggleShowSelectedPlane()
{
    bShowSelectedPlane = !bShowSelectedPlane;
}

// Update plan
void AARManager::UpdateDetectedPlanes()
{
    TArray<UARTrackedGeometry*> Geometries = UARBlueprintLibrary::GetAllGeometries();
    
    for (UARTrackedGeometry* Geometry : Geometries)
    {
        
        if (Geometry && Geometry->IsA(UARPlaneGeometry::StaticClass()))
        {
            UARPlaneGeometry* Plane = Cast<UARPlaneGeometry>(Geometry);
            
            if (!DetectedPlanes.Contains(Plane))
            {
                DetectedPlanes.Add(Plane);

                if (PlaneMaterial && bShowSelectedPlane)
                {
                    UStaticMeshComponent* PlaneMesh = NewObject<UStaticMeshComponent>(this);
                    PlaneMesh->SetStaticMesh();
                    PlaneMesh->SetMaterial(0, PlaneMaterial);
                    PlaneMesh->SetWorldTransform(Plane->GetLocalToWorldTransform());
                    PlaneMesh->RegisterComponent();
                }
            }
        }
    }
}
