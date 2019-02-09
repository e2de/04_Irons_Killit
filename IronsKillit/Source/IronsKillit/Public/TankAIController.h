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
	
private:
	virtual void BeginPlay()  override;

	void Tick(float DeltaTime) override;

};
