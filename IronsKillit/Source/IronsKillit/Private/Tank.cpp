// copyright Alice Meng 2019

#include "Tank.h"
#include "TankAimingComponent.h"



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

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("FIRE"));
}

// Sets default values
ATank::ATank()
{
	// No need to protect ptrs, added at constrouction
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

