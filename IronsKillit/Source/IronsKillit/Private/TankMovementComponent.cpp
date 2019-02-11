// copyright Alice Meng 2019

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Tank.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) 
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	// TODO review moving issue where moving forward is just turning
	if (!ensure(LeftTrack && RightTrack)) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Throw: %f"), Throw);
	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("%f throw for IntendMoveright"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForwardDirection);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(AIForwardIntention, TankForwardDirection).Z;
	IntendTurnRight(RightThrow);
}

