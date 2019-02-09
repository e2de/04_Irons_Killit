// copyright Alice Meng 2019


#include "TankAimingComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "Tank.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (!Barrel) { return; }

	// TODO: fix bad math on projectile aim

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
								ESuggestProjVelocityTraceOption::DoNotTrace,
								FCollisionResponseParams::DefaultResponseParam,
								TArray<AActor*>(),
								true);

	if (bHaveAimSolution) {
		auto AimDirection = TossVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from %s"), *OurTankName, *HitLocation.ToString(), *(BarrelLocation.ToString()));
		//UE_LOG(LogTemp, Warning, TEXT("%s will fire in this direction: %s"), *OurTankName, (*AimDirection.ToString()));

		MoveBarrel(AimDirection);
		/*auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: aim solve called with %s"), Time, (*AimDirection.ToString()) );*/
	}
	else {
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: NO aim solve called already"), Time);
	}

	
	
}



void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }

	// find Difference between the current barrel rotation and aim direction
	auto CurrentBarrel = GetOwner();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch); 
	Turret->Azimuth(DeltaRotator.Yaw);
}
