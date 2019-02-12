// copyright Alice Meng 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnPoint.generated.h"

class AActor;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IRONSKILLIT_API USpawnPoint : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnPoint();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	AActor * GetSpawnedActor() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AActor> SpawnClass;

	UPROPERTY()
		AActor* SpawnedActor;
		
};
