// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RenderTexture_Base64.generated.h"

/**
 * 
 */
UCLASS()
class ARDECO_API URenderTexture_Base64 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "Utils")
    static FString ConvertRenderTargetToBase64(UTextureRenderTarget2D* RenderTarget);
};
