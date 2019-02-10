// copyright Alice Meng 2019

#pragma once
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
class UTankTrack;
class UTankMovementComponent;

UCLASS()
class IRONSKILLIT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint; //alternative is TSubclass

	// Local barrel reference
	UTankBarrel * Barrel = nullptr;  
	//TODO: Remove

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;
};
