// Copyright Alice Meng 2019
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;

UCLASS()
class IRONSKILLIT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	
	void Tick(float DeltaTime) override;

	virtual void BeginPlay()  override;

	// start tank moving the barrel so show will hit where crosshair intersects world
	void AimTowardsCrosshair();

	// find where the crosshair is hitting
	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		int LineTraceRange = 1000000;



};



