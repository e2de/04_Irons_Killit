// copyright Alice Meng 2019

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Classes/Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTrack.h"



void ATank::AimAt(FVector HitLocation) 
{
	auto TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
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

