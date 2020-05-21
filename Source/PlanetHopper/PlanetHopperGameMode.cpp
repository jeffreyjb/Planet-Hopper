// Copyright Jeff Brown 2020

#include "PlanetHopperGameMode.h"
#include "Kismet/GameplayStatics.h"

APlanetHopperGameMode::APlanetHopperGameMode()
{
  //SaveGameInst = Cast<USaveGameData>(UGameplayStatics::CreateSaveGameObject(USaveGameData::StaticClass()));
  //LoadSavedHighScore();
}

void APlanetHopperGameMode::SetHighScore(int32 ScoreToSet)
{
  HighScore = ScoreToSet;
  if (!SaveGameInst)
  {
    return;
  }
  //SaveGameInst->SavedHighScore = ScoreToSet;
  //UGameplayStatics::SaveGameToSlot(SaveGameInst, SaveGameInst->SaveSlotName, SaveGameInst->UserIndex);
}

int32 APlanetHopperGameMode::GetHighScore() const
{
  return HighScore;
}

void APlanetHopperGameMode::SetCurrentScore(int32 ScoreToSet)
{
  CurrentScore = ScoreToSet;
}

int32 APlanetHopperGameMode::GetCurrentScore() const
{
  return CurrentScore;
}

void APlanetHopperGameMode::LoadSavedHighScore()
{
  if (!SaveGameInst)
  {
    return;
  }
  LoadGameInst = Cast<USaveGameData>(UGameplayStatics::LoadGameFromSlot(FString("HighScore"), 0));
  if (!LoadGameInst)
  {
    return;
  }
  HighScore = LoadGameInst->SavedHighScore;
}