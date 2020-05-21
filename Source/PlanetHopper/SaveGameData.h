// Copyright Jeff Brown 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameData.generated.h"

/**
 * 
 */
UCLASS()
class PLANETHOPPER_API USaveGameData : public USaveGame
{
  GENERATED_BODY()

public:
  USaveGameData();

  UPROPERTY(VisibleAnywhere, Category = "Basic")
  FString SaveSlotName;

  UPROPERTY(VisibleAnywhere, Category = "Basic")
  uint32 UserIndex;

  UPROPERTY(VisibleAnywhere, Category = "Basic")
  int32 SavedHighScore;
};
