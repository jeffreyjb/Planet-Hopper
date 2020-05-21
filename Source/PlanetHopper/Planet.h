// Copyright Jeff Brown 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PlanetHopperGameMode.h"
#include "Planet.generated.h"

UCLASS()
class PLANETHOPPER_API APlanet : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  APlanet();

  // Called every frame
  virtual void Tick(float DeltaTime) override;

  void UpdateScore();

  // Properties
  UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
  UStaticMeshComponent *PlanetRootObj = nullptr;

  UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
  UStaticMeshComponent *PlanetBodyMesh = nullptr;

  UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
  UStaticMeshComponent *JumpPlatform = nullptr;

  UPROPERTY(EditDefaultsOnly, Category = "Components")
  UBoxComponent *LandingZone = nullptr;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

private:
  void GetGameModeReference();

  // Properties
  bool bHasScored = false;
  APlanetHopperGameMode *PlanetGameMode = nullptr;
};
