// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5TrainingGameMode.h"
#include "UE5TrainingPlayerController.h"
#include "UE5TrainingPawn.h"


AUE5TrainingGameMode::AUE5TrainingGameMode()
{
    PlayerControllerClass = AUE5TrainingPlayerController::StaticClass();
    DefaultPawnClass = AUE5TrainingPawn::StaticClass();
}

