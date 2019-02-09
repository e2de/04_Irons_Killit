// copyright Alice Meng 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IRONSKILLIT_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Azimuth(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 25;	// sensible default

	UPROPERTY(EditDefaultsOnly)
		float MaxAzimuthDegrees = 0;	// sensible default

	UPROPERTY(EditDefaultsOnly)
		float MinAzimuthDegrees = -360;	// sensible default
};
