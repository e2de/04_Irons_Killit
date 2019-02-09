// copyright Alice Meng 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *  Tank Barrel Static Mesh Component
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))		//, hidecategories = ("collision")
class IRONSKILLIT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 10;	// sensible default

	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegrees = 40;	// sensible default

	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegrees = 0;	// sensible default
};
