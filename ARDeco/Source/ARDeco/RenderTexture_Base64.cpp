#include "RenderTexture_Base64.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ImageUtils.h"
#include "Misc/Base64.h"
#include "Engine/Engine.h"

FString URenderTexture_Base64::ConvertRenderTargetToBase64(UTextureRenderTarget2D* RenderTarget)
{
    // Vérifier si le RenderTarget est valide
    if (!RenderTarget)
    {
        UE_LOG(LogTemp, Warning, TEXT("RenderTarget est nul."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Erreur: RenderTarget est nul."));
        }
        return FString();
    }

    // Récupérer la ressource du RenderTarget
    FTextureRenderTargetResource* RenderTargetResource = RenderTarget->GameThread_GetRenderTargetResource();
    if (!RenderTargetResource)
    {
        UE_LOG(LogTemp, Warning, TEXT("Impossible d'obtenir la ressource du RenderTarget."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Erreur: Impossible d'obtenir la ressource du RenderTarget."));
        }
        return FString();
    }

    // Tableau pour stocker les données de pixels
    TArray<FColor> PixelData;

    // Lire les pixels du RenderTarget dans le tableau de pixels
    RenderTargetResource->ReadPixels(PixelData);

    // Vérifier si des données de pixels ont été lues
    if (PixelData.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Aucune donnée pixel lue du RenderTarget."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Erreur: Aucune donnée pixel lue du RenderTarget."));
        }
        return FString();
    }

    // Vérifier que les dimensions du RenderTarget sont valides
    int32 Width = RenderTarget->SizeX;
    int32 Height = RenderTarget->SizeY;
    if (Width <= 0 || Height <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Dimensions du RenderTarget invalides : Largeur=%d, Hauteur=%d"), Width, Height);
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Erreur: Dimensions du RenderTarget invalides : Largeur=%d, Hauteur=%d"), Width, Height));
        }
        return FString();
    }

    // Compresser les pixels en PNG
    TArray<uint8> CompressedPNG;
    FImageUtils::CompressImageArray(Width, Height, PixelData, CompressedPNG);

    // Vérifier que la compression a réussi et qu'il y a des données
    if (CompressedPNG.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Données PNG compressées vides."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Erreur: Données PNG compressées vides."));
        }
        return FString();
    }

    // Encoder les données compressées en base64
    FString Base64String = FBase64::Encode(CompressedPNG);

    return Base64String;
}
