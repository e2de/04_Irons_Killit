// Copyright Alice Meng 2019
#pragma once

#include "IronsKillit.h"
#include "Tank.h"
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

public:
	ATank_BP* GetControlledTank() const;
	
};



