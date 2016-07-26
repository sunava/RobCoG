// Fill out your copyright notice in the Description page of Project Settings.

#include "RobCoG.h"
#include "SemLog/RSemEventsExporterSingl.h"
#include "SemanticContactTriggerBox.h"

// Set default values
ASemanticContactTriggerBox::ASemanticContactTriggerBox()
{
}

// Destructor
ASemanticContactTriggerBox::~ASemanticContactTriggerBox()
{
}

// Called when the games starts or when spawned
void ASemanticContactTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
	// Check if parent is set
	if (Parent)
	{
		// Bind overlap events
		OnActorBeginOverlap.AddDynamic(this, &ASemanticContactTriggerBox::BeginSemanticContact);
		OnActorEndOverlap.AddDynamic(this, &ASemanticContactTriggerBox::EndSemanticContact);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT(" %s's parent is not set!"), *GetName());
	}
}

// Callback on start overlap, end the semantic contact
void ASemanticContactTriggerBox::BeginSemanticContact(
	AActor* Self, AActor* OtherActor)
{
	if (FRSemEventsExporterSingl::Get().IsInit())
	{
		FRSemEventsExporterSingl::Get().BeginTouchingEvent(
			Parent, OtherActor, GetWorld()->GetTimeSeconds());
	}
}

// Callback on end overlap, end the semantic contact
void ASemanticContactTriggerBox::EndSemanticContact(
	AActor* Self, AActor* OtherActor)
{
	if (FRSemEventsExporterSingl::Get().IsInit())
	{
		FRSemEventsExporterSingl::Get().EndTouchingEvent(
			Parent, OtherActor, GetWorld()->GetTimeSeconds());
	}
}