// copyright Alice Meng 2019

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	auto Name = GetName();

	auto forward = GetOwner()->GetActorForwardVector();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle forward is: %s"), *(Name),*(forward.ToString()));

	// TODO: clamp actual throttle
	auto ForceApplied = forward * Throttle * TrackMaxDrivingForce;
	
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

