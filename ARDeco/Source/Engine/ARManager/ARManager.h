#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARManager.generated.h"

class UARSessionConfig;
class UMaterialInterface;

// Déclaration de la classe AARManager héritant de AActor
UCLASS()
class MYPROJECT_API AARManager : public AActor
{
    GENERATED_BODY()

public:
    AARManager();

protected:
    virtual void BeginPlay() override; //Begin = Chaque lancement d'app
    virtual void Tick(float DeltaTime) override; //Tick = Directement (chaque frame)

public:
    // Start session AR
    UFUNCTION(BlueprintCallable, Category = "AR Functionality")
    void StartARSession();

    // Reset la session AR
    UFUNCTION(BlueprintCallable, Category = "AR Functionality")
    void ResetARSession();

    // Affichage du plan
    UFUNCTION(BlueprintCallable, Category = "AR Functionality")
    void ToggleShowSelectedPlane();

    // Texture affichage plan
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AR Visualization")
    UMaterialInterface* PlaneMaterial;

    // Configuration AR (utilisée pour gérer les fonctionnalités ARCore/ARKit)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AR Settings")
    UARSessionConfig* ARSessionConfig;

private:
    // Update plan
    void UpdateDetectedPlanes();
    TArray<UARPlaneGeometry*> DetectedPlanes;
    bool bShowSelectedPlane;
};
