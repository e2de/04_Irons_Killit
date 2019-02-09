// copyright Alice Meng 2019

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Tank.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) 
{
	if (!LeftTrackToSet || !RightTrackToSet) { return;  }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	UE_LOG(LogTemp, Warning, TEXT("%f throw for IntendMoveForward"), Throw);

	// TODO: fix movement
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}


