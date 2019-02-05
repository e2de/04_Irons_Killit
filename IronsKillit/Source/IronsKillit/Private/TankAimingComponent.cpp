// copyright Alice Meng 2019


#include "TankAimingComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "Tank.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.


	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}




void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (!Barrel) { return; }

	FVector TossVelocity;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
								this,
								TossVelocity,
								BarrelLocation,
								HitLocation,
								LaunchSpeed,
								false,
								0.0f,
								0.0f,
								ESuggestProjVelocityTraceOption::TraceFullPath,
								FCollisionResponseParams::DefaultResponseParam,
								TArray<AActor*>(),
								true);

	if (bHaveAimSolution) {
		auto AimDirection = TossVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from %s"), *OurTankName, *HitLocation.ToString(), *(BarrelLocation.ToString()));
		UE_LOG(LogTemp, Warning, TEXT("%s will fire in this direction: %s"), *OurTankName, (*AimDirection.ToString()));

		//MoveBarrel();
	}
	
}


void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	// find Difference between the current barrel rotation and aim direction
	auto CurrentBarrel = GetOwner();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5); // TODO remove magic number
}
