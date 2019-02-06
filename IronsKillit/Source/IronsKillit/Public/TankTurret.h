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
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 25;	// sensible default

	UPROPERTY(EditAnywhere)
		float MaxAzimuthDegrees = 0;	// sensible default

	UPROPERTY(EditAnywhere)
		float MinAzimuthDegrees = -360;	// sensible default
};
