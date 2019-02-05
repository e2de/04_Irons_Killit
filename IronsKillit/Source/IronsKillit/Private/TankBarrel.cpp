// copyright Alice Meng 2019

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) 
{
	// if barrel current direction is not requested direction
	// set barrel direction to requested direction
		// can either do this in tick, or all at once with a curve
	auto AdjustedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = AdjustedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}