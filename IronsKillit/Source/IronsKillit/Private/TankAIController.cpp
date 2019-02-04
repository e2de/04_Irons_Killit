// copyright Alice Meng 2019

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "IronsKillit.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetControlledTank();
	if (!AIControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("THERE IS NO AI CONTROLLED TANK"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s posessed by TankAIController"), *(AIControlledTank->GetName()));
	}

	auto PlayerControlledTank = GetPlayerTank();
	if (!PlayerControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("THERE IS NO PLAYER-CONTROLLED TANK"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController %s found the Tank %s"), *(AIControlledTank->GetName()), *(PlayerControlledTank->GetName()));
	} 
}

ATank * ATankAIController::GetPlayerTank() const
{
	// either do getworld -> get first player controller protect ptr cast to tank, log to check if worked
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank) { return nullptr; }
	else 
	{
		ATank * CastedPlayerTank = Cast<ATank>(PlayerTank);
		return CastedPlayerTank;
	}
}
