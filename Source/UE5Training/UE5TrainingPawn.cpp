// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5TrainingPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


// Sets default values
AUE5TrainingPawn::AUE5TrainingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));	
	if (CubeMesh.Succeeded())
		MeshComponent->SetStaticMesh(CubeMesh.Object);


	//TODO remove when adding real camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->SetRelativeLocation(FVector(-500.f, 0.f, 300.f)); // pulled back and up
	CameraComponent->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));   // angled down slightly at the cube
}

// Called when the game starts or when spawned
void AUE5TrainingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUE5TrainingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input112
void AUE5TrainingPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUE5TrainingPawn::Move);
	}
}

void AUE5TrainingPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (APlayerController* PC = Cast<APlayerController>(NewController))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AUE5TrainingPawn::Move(const struct FInputActionValue& Value)
{
	const FVector2D MoveInput = Value.Get<FVector2D>();
	const FVector Delta = (GetActorForwardVector() * MoveInput.Y + GetActorRightVector() * MoveInput.X) * 5.0f;
	AddActorWorldOffset(Delta);
}

