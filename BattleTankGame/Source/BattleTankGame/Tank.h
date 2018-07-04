// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

	// Sets default values for this pawn's propertie

protected:

	UTankAimingComponent * TankAimingComponent = nullptr;

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();



private:
	ATank();
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; //TODO find good speed
	
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;
};
