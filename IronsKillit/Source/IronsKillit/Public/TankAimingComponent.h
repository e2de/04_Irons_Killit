// copyright Alice Meng 2019

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel; 

//Hold barrel's props and methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IRONSKILLIT_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel * BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel *Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
};
