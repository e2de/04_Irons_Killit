// copyright Alice Meng 2019

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "IronsKillit.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameStateBase.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto AIControlledTank = GetPawn();
	auto PlayerControlledTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (ensure(AIControlledTank)) {
		MoveToActor(PlayerControlledTank, AcceptanceRadius);

		// Aim towards the player
		auto AimComponent = AIControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimComponent->AimAt(PlayerControlledTank->GetActorLocation());

		// FIRE if ready(aiming or locked) (limit fire rate)
		if (AimComponent->GetFiringState() == EFiringStatus::Locked) {
			AimComponent->Fire();
		}

	}
	
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// subscribe our local method to the tank's death event
		PossessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAIController::OnDeath);
	}
}

void ATankAIController::OnDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Tank Death delegate call AI"));
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay(); 
}
