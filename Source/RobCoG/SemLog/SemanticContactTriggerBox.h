// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerBox.h"
#include "SemanticContactTriggerBox.generated.h"

/**
 *  Trigger box sending contact information to the semantic events exporter
 */
UCLASS()
class ROBCOG_API ASemanticContactTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	// Constructor
	ASemanticContactTriggerBox();
	
	// Destructor
	~ASemanticContactTriggerBox();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Callback on begin overlap
	UFUNCTION()
	void BeginSemanticContact(AActor* Self, AActor* OtherActor);

	// Callback on end overlap
	UFUNCTION()
	void EndSemanticContact(AActor* Self, AActor* OtherActor);

	// Static mesh actor parent for the trigger
	UPROPERTY(EditAnywhere, Category = "Semantic Contact")
	AStaticMeshActor* Parent;
};
