// copyright Alice Meng 2019

#include "Tank.h"
#include "TankTrack.h"

// Sets default values
ATank::ATank()
{
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth0 = StartingHealth;
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	auto TotalDamage = FMath::Clamp(DamagePoints, 0, CurrentHealth0);
	CurrentHealth0 -= TotalDamage;
	UE_LOG(LogTemp, Warning, TEXT("%i: Damage amount, %i: Damage To Apply, Current Health: %i, Total Health: %i"), DamagePoints, TotalDamage, CurrentHealth0, StartingHealth);

	if (CurrentHealth0 <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("TANK DIED"));
		OnTankDeath.Broadcast();
	}
	return (float)TotalDamage;
}

float ATank::GetHealthPercent() const
{
	return (float)(CurrentHealth0) / (float)StartingHealth;
}


