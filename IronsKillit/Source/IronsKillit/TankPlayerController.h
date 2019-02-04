// Copyright Alice Meng 2019
#pragma once

#include "IronsKillit.h"
#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
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

};



