// Copyright Alice Meng 2019
#include "TankPlayerController.h"
#include "IronsKillit.h"


ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}