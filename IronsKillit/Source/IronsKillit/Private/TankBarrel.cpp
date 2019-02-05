// copyright Alice Meng 2019

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond) 
{
	// if barrel current direction is not requested direction
	// set barrel direction to requested direction
		// can either do this in tick, or all at once with a curve

	UE_LOG(LogTemp, Warning, TEXT("Barrel Call %f"), DegreesPerSecond);
}