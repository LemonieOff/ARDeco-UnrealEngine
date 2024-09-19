// Fill out your copyright notice in the Description page of Project Settings.


#include "RenderTexture_Base64.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ImageUtils.h"
#include "Misc/Base64.h"

FString URenderTexture_Base64::ConvertRenderTargetToBase64(UTextureRenderTarget2D* RenderTarget)
{
    if (!RenderTarget)
    {
        UE_LOG(LogTemp, Warning, TEXT("RenderTarget est nul."));
        return FString();
    }

    FTextureRenderTargetResource* RenderTargetResource = RenderTarget->GameThread_GetRenderTargetResource();
    if (!RenderTargetResource)
    {
        UE_LOG(LogTemp, Warning, TEXT("Impossible d'obtenir la ressource du RenderTarget."));
        return FString();
    }

    TArray<FColor> PixelData;

    // Lire les pixels du RenderTarget
    RenderTargetResource->ReadPixels(PixelData);

    // Vérifier si des données ont été lues
    if (PixelData.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Aucune donnée pixel lue du RenderTarget."));
        return FString();
    }

    // Compresser les pixels en PNG
    TArray<uint8> CompressedPNG;
    FImageUtils::CompressImageArray(RenderTarget->SizeX, RenderTarget->SizeY, PixelData, CompressedPNG);

    // Encoder les données compressées en base64
    FString Base64String = FBase64::Encode(CompressedPNG);

    return Base64String;
}
