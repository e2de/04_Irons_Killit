// copyright Alice Meng 2019

#include "TankTurret.h"

void UTankTurret::Azimuth(float RelativeSpeed) {
	auto AdjustedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto AzimuthChange = AdjustedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewAzimuth = RelativeRotation.Yaw + AzimuthChange;
	this->SetRelativeRotation(FRotator(0, NewAzimuth, 0));

}