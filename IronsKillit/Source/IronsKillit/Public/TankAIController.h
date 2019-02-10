// copyright Alice Meng 2019

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declaration
class ATank;

/**
 * 
 */
UCLASS()
class IRONSKILLIT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// How close can the AI tank be to the player
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 80000;

	
private:
	virtual void BeginPlay()  override;

	void Tick(float DeltaTime) override;


};
