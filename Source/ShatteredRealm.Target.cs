// Copyright Spellbound Studios.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShatteredRealmTarget : TargetRules
{
	public ShatteredRealmTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ShatteredRealm" } );
	}
}
