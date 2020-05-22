// Copyright Jeff Brown 2020

#include "PlanetHopperGameMode.h"
#include "Kismet/GameplayStatics.h"

APlanetHopperGameMode::APlanetHopperGameMode()
{
  bAlteringHighScore = true;
  SaveGameInst = Cast<USaveGameData>(UGameplayStatics::CreateSaveGameObject(USaveGameData::StaticClass()));
  LoadSavedHighScore();
  bAlteringHighScore = false;
}

void APlanetHopperGameMode::SetHighScore(int32 ScoreToSet)
{
  bAlteringHighScore = true;
  HighScore = ScoreToSet;
  if (!SaveGameInst)
  {
    bAlteringHighScore = false;
    return;
  }
  SaveGameInst->SavedHighScore = ScoreToSet;
  UGameplayStatics::SaveGameToSlot(SaveGameInst, SaveGameInst->SaveSlotName, SaveGameInst->UserIndex);
  bAlteringHighScore = false;
}

int32 APlanetHopperGameMode::GetHighScore() const
{
  if (bAlteringHighScore)
  {
    return -1;
  }
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
  bAlteringHighScore = true;
  if (!SaveGameInst)
  {
    bAlteringHighScore = false;
    return;
  }
  LoadGameInst = Cast<USaveGameData>(UGameplayStatics::LoadGameFromSlot(FString("HighScore"), 0));
  if (!LoadGameInst)
  {
    bAlteringHighScore = false;
    return;
  }
  HighScore = LoadGameInst->SavedHighScore;
  bAlteringHighScore = false;
}