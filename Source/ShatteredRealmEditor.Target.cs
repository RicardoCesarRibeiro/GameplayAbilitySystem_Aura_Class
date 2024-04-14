// Copyright Spellbound Studios.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShatteredRealmEditorTarget : TargetRules
{
	public ShatteredRealmEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ShatteredRealm" } );
	}
}