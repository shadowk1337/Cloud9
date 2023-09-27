﻿// ReSharper disable CppMemberFunctionMayBeConst
#include "Cloud9KeyboardController.h"

#include "Cloud9/Character/Enums/Cloud9WeaponSlot.h"

void UCloud9KeyboardController::OnMoveForward(float Value)
{
	if (IsValid(GetPawn()) && FMath::Abs(Value) > 0.0f)
		GetPawn()->AddMovementInput(FVector::XAxisVector, Value);
}

void UCloud9KeyboardController::OnMoveRight(float Value)
{
	if (IsValid(GetPawn()) && FMath::Abs(Value) > 0.0f)
		GetPawn()->AddMovementInput(FVector::YAxisVector, Value);
}

void UCloud9KeyboardController::OnWalkPressed()
{
	if (IsValid(GetPawn()))
		GetPawn()->Sneak();
}

void UCloud9KeyboardController::OnWalkReleased()
{
	if (IsValid(GetPawn()))
		GetPawn()->UnSneak();
}

void UCloud9KeyboardController::OnCrouchPressed()
{
	if (IsValid(GetPawn()))
		GetPawn()->Crouch(false);
}

void UCloud9KeyboardController::OnCrouchReleased()
{
	if (IsValid(GetPawn()))
		GetPawn()->UnCrouch(false);
}

void UCloud9KeyboardController::OnJumpPressed()
{
	if (IsValid(GetPawn()))
		GetPawn()->Jump();
}

void UCloud9KeyboardController::OnJumpReleased()
{
	if (IsValid(GetPawn()))
		GetPawn()->StopJumping();
}

void UCloud9KeyboardController::OnSlot1()
{
	if (IsValid(GetPawn()))
		GetPawn()->GetInventory()->SelectWeapon(EWeaponSlot::Main);
}

void UCloud9KeyboardController::OnSlot2()
{
	if (IsValid(GetPawn()))
		GetPawn()->GetInventory()->SelectWeapon(EWeaponSlot::Pistol);
}


void UCloud9KeyboardController::OnSlot3()
{
	if (IsValid(GetPawn()))
		GetPawn()->GetInventory()->SelectWeapon(EWeaponSlot::Knife);
}


void UCloud9KeyboardController::OnSlot4()
{
	if (IsValid(GetPawn()))
		GetPawn()->GetInventory()->SelectWeapon(EWeaponSlot::Grenade);
}


void UCloud9KeyboardController::OnSlot5()
{
	if (IsValid(GetPawn()))
		GetPawn()->GetInventory()->SelectWeapon(EWeaponSlot::Stuff);
}

void UCloud9KeyboardController::Reload()
{
	if (IsValid(GetPawn()))
	{
		// TODO: Reload	
	}
}
