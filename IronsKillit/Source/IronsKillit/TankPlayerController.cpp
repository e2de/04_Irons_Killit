// Copyright Alice Meng 2019
#include "TankPlayerController.h"
#include "IronsKillit.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("THERE IS NO CONTROLLED TANK"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s posessed by PlayerController"), *(ControlledTank->GetName()));
	}

}


ATank* ATankPlayerController::GetControlledTank() const 
{
	ATank* TestPawn = Cast<ATank>(GetPawn());
	return TestPawn;
}


