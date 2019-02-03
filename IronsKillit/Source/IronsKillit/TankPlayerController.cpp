// Copyright Alice Meng 2019
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const {
	Cast<ATank>(GetPawn());
}
