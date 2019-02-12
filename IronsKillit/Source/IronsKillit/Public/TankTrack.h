// copyright Alice Meng 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 *  Tank track is used to set the track information to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IRONSKILLIT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max Per-force track in N
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000;	// assume a 40ton tank and 1g acceleration
private:
	TArray<ASprungWheel *> GetWheels() const;

	UTankTrack();

	void DriveTrack(float Throttle);
};

// deprecated:
// void ApplySidewaysForce(); 

// virtual void BeginPlay() override;

//UFUNCTION()
//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);