// Copyright Alice Meng 2019
#include "TankPlayerController.h"
#include "IronsKillit.h"


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("THERE IS NO CONTROLLED TANK"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s posessed by PlayerController"), *(ControlledTank->GetName()));
	}

}

// start tank moving the barrel so show will hit where crosshair intersects world
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Error, TEXT("HitLocation: %s"), *HitLocation.ToString());

			// TODO tell controlled tank to aim at this point
	}

	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)const
{
	// Get world location of linetrace through crosshair

	// Get player location
	// get player rotation
	// 
	HitLocation = FVector(1.0);
	return false;
}


ATank* ATankPlayerController::GetControlledTank() const 
{
	ATank* TestPawn = Cast<ATank>(GetPawn());
	return TestPawn;
}


