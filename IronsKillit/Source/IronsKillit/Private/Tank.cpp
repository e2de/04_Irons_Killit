// copyright Alice Meng 2019

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Classes/Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTrack.h"



void ATank::AimAt(FVector HitLocation) 
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) {
		UE_LOG(LogTemp, Error, TEXT("THERE IS NO BARREL ON TANK"));
	}
	else {
		TankAimingComponent->SetBarrelReference(BarrelToSet);
		Barrel = BarrelToSet;
	} 
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) {
		UE_LOG(LogTemp, Error, TEXT("THERE IS NO TURRET ON TANK"));
	}
	else {
		TankAimingComponent->SetTurretReference(TurretToSet);
	}

}

void ATank::SetTankTrack(UTankTrack * TrackToSet)
{

}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && bIsReloaded) 
	{
		// spawn projectile at the end of the barrel
		UE_LOG(LogTemp, Warning, TEXT("FIRE"));
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

// Sets default values
ATank::ATank()
{
	// No need to protect ptrs, added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

