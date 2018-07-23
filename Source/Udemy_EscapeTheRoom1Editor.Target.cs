// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Udemy_EscapeTheRoom1EditorTarget : TargetRules
{
	public Udemy_EscapeTheRoom1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Udemy_EscapeTheRoom1" } );
	}
}
