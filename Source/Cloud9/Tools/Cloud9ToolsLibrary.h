﻿#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Cloud9ToolsLibrary.generated.h"

class ACloud9GameMode;


/**
 * Class provides different tools/helpers functions to minimize boilerplate code.
 */
UCLASS()
class CLOUD9_API UCloud9ToolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Function sets collision complexity for StaticMesh.
	 * This required to fix CS:GO map collision (a lot of simple collisions are mess after import from Blender).
	 * StaticMesh->GetBodySetup()->CollisionTraceFlag can't be accessed directly from Python API.
	 */
	UFUNCTION(BlueprintCallable)
	static void SetCollisionComplexity(UStaticMesh* StaticMesh, uint8 CollisionTraceFlag);

	/**
	 * Function calculates a volume ratio between bounding box and simple collision mesh volume.
	 * Research variant to fix collisions of CS:GO map. 
	 */
	UFUNCTION(BlueprintCallable)
	static float CalculateCollisionVolumeScale(UStaticMesh* StaticMesh);

	UFUNCTION(BlueprintCallable)
	static UWorld* GetWorld();

	UFUNCTION(BlueprintCallable)
	static ACloud9GameMode* GetGameMode();

	template <class Cls>
	static Cls* GetActorOfClass()
	{
		return Cast<Cls>(UGameplayStatics::GetActorOfClass(GetWorld(), Cls::StaticClass()));
	}

	template <class Cls>
	static TArray<Cls*> GetAllActorsOfClass()
	{
		TArray<AActor*> Actors = {};
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), Cls::StaticClass(), Actors);
		return reinterpret_cast<TArray<Cls*>&>(Actors);
	}

	template <class T, class U>
	static T InverseLerp(const T& A, const T& B, const U& X) { return static_cast<T>((X - A) / (B - A)); }

	static FBox GetAccurateReferencePoseBounds(const USkeletalMesh* Mesh);

	UFUNCTION(BlueprintCallable)
	static void GetWidthHeightDepth(const FBox& Box, float& Width, float& Height, float& Depth);

	static FRotator RadiansToDegrees(const FRotator Rotator);
};
