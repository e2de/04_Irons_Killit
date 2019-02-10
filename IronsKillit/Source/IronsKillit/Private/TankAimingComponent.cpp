// copyright Alice Meng 2019


#include "TankAimingComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
//#include "Tank.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Classes/Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (!ensure(Barrel)) { return; }

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
								false);		// change to true for debug line

	if (bHaveAimSolution) {
		auto AimDirection = TossVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from %s"), *OurTankName, *HitLocation.ToString(), *(BarrelLocation.ToString()));
		//UE_LOG(LogTemp, Warning, TEXT("%s will fire in this direction: %s"), *OurTankName, (*AimDirection.ToString()));
		MoveBarrel(AimDirection);
	}	
}

void UTankAimingComponent::Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}



void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }

	// find Difference between the current barrel rotation and aim direction
	auto CurrentBarrel = GetOwner();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch); 
	Turret->Azimuth(DeltaRotator.Yaw);
}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel && ProjectileBlueprint)) { return; }

	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (bIsReloaded)
	{
		// spawn projectile at the end of the barrel
		bool bSocketExist = Barrel->DoesSocketExist("Projectile");

		if (bSocketExist) {
			auto ProjectileLocation = Barrel->GetSocketLocation(FName("Projectile"));
			auto ProjectileRotation = Barrel->GetSocketRotation(FName("Projectile"));
			auto Projectile = GetWorld()->SpawnActor <AProjectile>(ProjectileBlueprint, ProjectileLocation, ProjectileRotation);

			//launch projectile
			Projectile->LaunchProjectile(LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
		}
	}



}

