﻿#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Cloud9/Character/Cloud9Character.h"
#include "Cloud9ControllerBase.generated.h"

UCLASS()
class CLOUD9_API UCloud9ControllerBase : public UActorComponent
{
	GENERATED_BODY()

public:
	ACloud9Character* GetPawn() const;
};
