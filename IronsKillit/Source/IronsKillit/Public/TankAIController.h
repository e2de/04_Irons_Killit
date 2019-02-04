// copyright Alice Meng 2019

#pragma once

#include "IronsKillit.h"
#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class IRONSKILLIT_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay()  override;

	ATank* GetPlayerTank() const;

};
