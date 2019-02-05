// Copyright Alice Meng 2019
#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "Classes/Engine/World.h"
#include "IronsKillit.h"
#include "Public/Tank.h"
#include "IronsKillit.h"
#include "GameFramework/PlayerController.h"

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
		GetControlledTank()->AimAt(HitLocation);
	}

	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)const
{
	// Get world location of linetrace through crosshair

	// find crosshair
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(CrossHairXLocation*ViewportSizeX, CrossHairYLocation*ViewportSizeY);

	// De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// Line trace along the LookDirection and see what is hit:
		if (GetLookVectorHitLocation(HitLocation,LookDirection)) {
			return true;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;	// to be discarded
	return DeprojectScreenPositionToWorld(
			ScreenLocation.X,
			ScreenLocation.Y,
			CameraWorldLocation,
			LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	FCollisionQueryParams QueryParams = FCollisionQueryParams("", false, GetControlledTank());
	
	if (GetWorld()->LineTraceSingleByChannel(
					HitResult, 
					StartLocation, 
					EndLocation, 
					ECollisionChannel::ECC_Visibility,QueryParams))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	ATank* TestPawn = Cast<ATank>(GetPawn());
	return TestPawn;
}


