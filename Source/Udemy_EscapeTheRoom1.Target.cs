// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Udemy_EscapeTheRoom1Target : TargetRules
{
	public Udemy_EscapeTheRoom1Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Udemy_EscapeTheRoom1" } );
	}
}
