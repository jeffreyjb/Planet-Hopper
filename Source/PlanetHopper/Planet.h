// Copyright Jeff Brown 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
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

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

private:
  UPROPERTY(VisibleAnywhere, Category = "Components")
  UStaticMeshComponent *PlanetRoot = nullptr;

  UPROPERTY(VisibleAnywhere, Category = "Components")
  UStaticMeshComponent *Planet = nullptr;

  UPROPERTY(VisibleAnywhere, Category = "Components")
  UStaticMeshComponent *LandingPlane = nullptr;

  UFUNCTION(BlueprintCallable, Category = "Movement")
  void SetPlanetVelocity(float speed);
};
