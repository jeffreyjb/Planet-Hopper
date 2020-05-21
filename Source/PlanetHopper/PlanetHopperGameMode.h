// Copyright Jeff Brown 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SaveGameData.h"
#include "PlanetHopperGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLANETHOPPER_API APlanetHopperGameMode : public AGameModeBase
{
  GENERATED_BODY()

public:
  APlanetHopperGameMode();

  UFUNCTION(BlueprintCallable, Category = "Scoring")
  void SetHighScore(int32 ScoreToSet);

  UFUNCTION(BlueprintCallable, Category = "Scoring")
  int32 GetHighScore() const;

  UFUNCTION(BlueprintCallable, Category = "Scoring")
  void SetCurrentScore(int32 ScoreToSet);

  UFUNCTION(BlueprintCallable, Category = "Scoring")
  int32 GetCurrentScore() const;

private:
  UPROPERTY(EditDefaultsOnly, Category = "Scoring")
  int32 CurrentScore = 0;

  UPROPERTY(VisibleAnywhere, Category = "Scoring")
  int32 HighScore = 0;

  USaveGameData *SaveGameInst = nullptr;
  USaveGameData *LoadGameInst = nullptr;

  void LoadSavedHighScore();
};
