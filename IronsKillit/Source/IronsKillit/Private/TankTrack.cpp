// copyright Alice Meng 2019

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	auto Name = GetName();

	//auto forward = GetOwner()->GetActorForwardVector();
	auto forward = GetForwardVector();
	// TODO: clamp actual throttle
	auto ForceApplied = forward * Throttle * TrackMaxDrivingForce;
	
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

