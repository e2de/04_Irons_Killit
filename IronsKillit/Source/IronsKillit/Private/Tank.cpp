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
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	auto TotalDamage = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	UE_LOG(LogTemp, Warning, TEXT("%i: Damage amount, %i: Damage To Apply"), DamagePoints, TotalDamage);

	CurrentHealth -= TotalDamage;

	if (CurrentHealth <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("TANK DIED"));
		OnTankDeath.Broadcast();
	}
	return FMath::RoundToFloat(TotalDamage);
}

float ATank::GetHealthPercent() const
{
	return (float)(CurrentHealth) / (float)StartingHealth;
}


