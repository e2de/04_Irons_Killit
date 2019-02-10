// copyright Alice Meng 2019

#include "TankTrack.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) 
{
	UE_LOG(LogTemp, Warning, TEXT("HIT"));

}

void UTankTrack::BeginPlay() 
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType,ThisTickFunction);

	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetOwner()->GetActorRightVector());

	// Work out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways for (F = ma)
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle) {
	auto Name = GetName();

	auto forward = GetForwardVector();
	// TODO: clamp actual throttle
	auto ForceApplied = forward * Throttle * TrackMaxDrivingForce;
	
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

