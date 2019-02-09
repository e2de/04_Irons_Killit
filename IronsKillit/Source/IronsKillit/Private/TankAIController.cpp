// copyright Alice Meng 2019

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "IronsKillit.h"



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto AIControlledTank = Cast<ATank>(GetPawn());
	auto PlayerControlledTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (AIControlledTank) {
		// TODO move towards player
		MoveToActor(PlayerControlledTank, AcceptanceRadius);

		// Aim towards the player
		AIControlledTank->AimAt(PlayerControlledTank->GetActorLocation());

		// FIRE if ready (limit fire rate)
		AIControlledTank->Fire();
	}
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay(); 
}
