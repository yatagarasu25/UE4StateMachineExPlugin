using UnrealBuildTool;



public class StateMachineEx : ModuleRules
{
	public StateMachineEx(ReadOnlyTargetRules Target)
		: base(Target)
	{
#if UE_4_21_OR_LATER
		PrivatePCHHeaderFile = "Private/StateMachineExPrivatePCH.h";
#endif

		PublicIncludePaths.AddRange(new string[] {
				"StateMachineEx/Public"
			});


		PrivateIncludePaths.AddRange(new string[] {
				"StateMachineEx/Private",
			});


		PublicDependencyModuleNames.AddRange(new string[] {
				"Core",
			});

		PublicDependencyModuleNames.AddRange(new string[] {
			});


		PrivateDependencyModuleNames.AddRange(new string[] {
				"CoreUObject",
				"Engine",
			});

		PrivateDependencyModuleNames.AddRange(new string[] {
			});


		DynamicallyLoadedModuleNames.AddRange(new string[]{});
	}
}
