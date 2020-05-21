// Copyright Jeff Brown 2020

#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  PlanetRootObj = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlanetRootObj"));
  SetRootComponent(PlanetRootObj);
  PlanetRootObj->SetEnableGravity(false);

  PlanetBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlanetBodyMesh"));
  PlanetBodyMesh->SetupAttachment(PlanetRootObj); // Slightly better than attachtocomponent, works only in constructor
  PlanetBodyMesh->SetEnableGravity(false);

  JumpPlatform = CreateDefaultSubobject<UStaticMeshComponent>(FName("JumpPlatform"));
  JumpPlatform->SetupAttachment(PlanetRootObj); // Slightly better than attachtocomponent, works only in constructor
  JumpPlatform->SetEnableGravity(false);
  JumpPlatform->SetVisibility(false);

  LandingZone = CreateDefaultSubobject<UBoxComponent>(FName("LandingZone"));
  LandingZone->SetupAttachment(JumpPlatform);
}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
  Super::BeginPlay();

  GetGameModeReference();
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  UpdateScore();
}

void APlanet::UpdateScore()
{
  if (bHasScored || !LandingZone)
  {
    return;
  }

  // Find all overlapping actors
  TArray<AActor *> OverlappingActors;

  LandingZone->GetOverlappingActors(OverlappingActors);
  if (OverlappingActors.Num() != 0)
  {
    FString SomeGuy = OverlappingActors[0]->GetName();
    APawn *CollidingActor = Cast<APawn>(OverlappingActors[0]);
    if (!CollidingActor)
    {
      return;
    }
    bool bIsPlayer = CollidingActor->IsPlayerControlled();
    if (bIsPlayer)
    {
      bHasScored = true;
      PlanetGameMode->SetCurrentScore(PlanetGameMode->GetCurrentScore() + 1);
    }
  }
}

void APlanet::GetGameModeReference()
{
  // Get reference to game mode
  auto CurrentGameMode = GetWorld()->GetAuthGameMode();
  if (!CurrentGameMode)
  {
    return;
  }
  PlanetGameMode = Cast<APlanetHopperGameMode>(CurrentGameMode);
}
