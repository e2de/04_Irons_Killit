// copyright Alice Meng 2019

#include "TankTrack.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "SprungWheel.h"
#include "Components/SceneComponent.h"
#include "SpawnPoint.h"

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel *> Wheels;

	// get the spawn points
	TArray<USceneComponent *> SpawnPoints;
	GetChildrenComponents(false, SpawnPoints);

	for (USceneComponent * SpawnPoint : SpawnPoints)
	{
		// make sure it's a spawnpoint
		auto Point = Cast<USpawnPoint>(SpawnPoint);
		if (!Point) continue;

		auto Wheel = Cast<ASprungWheel>(Point->GetSpawnedActor());
		if (!Wheel) continue;

		Wheels.Add(Wheel);
	}
	return Wheels;
}

UTankTrack::UTankTrack()
{
	//PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::SetThrottle(float Throttle) 
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1.f, 1.f);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack (float Throttle)
{
	auto ForceApplied = Throttle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();

	for (ASprungWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}


// deprecated:
//void UTankTrack::ApplySidewaysForce()
//{
//	auto DeltaTime = GetWorld()->GetDeltaSeconds();
//	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetOwner()->GetActorRightVector());
//
//	// Work out the required acceleration this frame to correct
//	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
//
//	// Calculate and apply sideways for (F = ma)
//	auto ForceLocation = GetComponentLocation();
//	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
//	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
//	TankRoot->AddForce(CorrectionForce);
//}

//void UTankTrack::BeginPlay() 
//{
//	Super::BeginPlay();
//	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
//}

//void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
//{
//	//Drive the Tracks
//	DriveTrack(CurrentThrottle);
//
//	//Apply sideways force
//	ApplySidewaysForce();
//	CurrentThrottle = 0;
//}
