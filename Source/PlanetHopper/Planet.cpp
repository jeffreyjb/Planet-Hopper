// Copyright Jeff Brown 2020

#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  PlanetRoot = CreateDefaultSubobject<UStaticMeshComponent>(FName("Planet Root"));
  SetRootComponent(PlanetRoot);

  Planet = CreateDefaultSubobject<UStaticMeshComponent>(FName("Planet"));
  Planet->SetupAttachment(PlanetRoot); // Slightly better than attachtocomponent, works only in constructor

  LandingPlane = CreateDefaultSubobject<UStaticMeshComponent>(FName("Landing"));
  LandingPlane->SetupAttachment(PlanetRoot); // Slightly better than attachtocomponent, works only in constructor
}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}

void APlanet::SetPlanetVelocity(float speed)
{
}
