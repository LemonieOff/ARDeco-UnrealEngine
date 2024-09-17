

using UnrealBuildTool;
using System.Collections.Generic;

public class ARDecoEditorTarget : TargetRules
{
	public ARDecoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ARDeco" } );
	}
}
