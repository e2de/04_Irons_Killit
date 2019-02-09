// copyright Alice Meng 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class IRONSKILLIT_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);
	
private:
	// Called from the pathfinding logic by the AI controllers
	void RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack * LeftTrack = nullptr;
	UTankTrack * RightTrack = nullptr;

	

};
