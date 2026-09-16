// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5TrainingPlayerController.h"




void AUE5TrainingPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    UE_LOG(LogTemp, Warning, TEXT("PlayerController OnPossess: %s"), *InPawn->GetName())
}

void AUE5TrainingPlayerController::OnUnPossess()
{
    UE_LOG(LogTemp, Warning, TEXT("PlayerController OnUnPossess"));
    Super::OnUnPossess();
}
