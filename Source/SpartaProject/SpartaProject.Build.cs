// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpartaProject : ModuleRules
{
	public SpartaProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"UMG"
		});//현재 포함하고 있는 모듈

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
