// copyright Alice Meng 2019

#pragma once
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankTrack;
class UTankMovementComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS(meta = (BlueprintSpawnableComponent))
class IRONSKILLIT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	UPROPERTY(BlueprintAssignable)
	FTankDelegate OnTankDeath;
	
private:
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category="Health")
	int32 CurrentHealth;
};
