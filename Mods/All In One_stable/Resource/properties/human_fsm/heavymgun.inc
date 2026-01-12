;SDL

{State "heavymgun_pick"
	{from "squat"}
	{condition "heavymgun-pick"}
	{to "heavymgun_with"}
	{tag "squat"}
	{tag "heavymgun-pick"}
}
{State "heavymgun_with"
	{to "heavymgun_fire"}
	{to "heavymgun_reload"}
	{to "heavymgun_unload"}
	{to "heavymgun_drop"}
	{to "heavymgun_ground_drop"}
	{to "heavymgun_idle"}
	{tag "squat"}
	{tag "weapon"}
	{tag "aim"}
	{tag "rotate"}
	{tag "hold-heavymgun"}
	{tag "hold-back"}
	{tag "stop-hold-back"}
	{tag "stop-rotate"}
	{tag "stop-move"}
	{tag "stored"}
}
{State "heavymgun_ground_drop" 
	{condition "ground-drop"}
	{to "squat"}
	{tag "squat"}
	{tag "ground-drop"}
}
{State "heavymgun_idle"
	{to "heavymgun_with"}
	{tag "idle"}
	{tag "squat"}
}
{State "heavymgun_fire"
	{to "heavymgun_recoil"}
	{tag "squat"}
	{tag "fire"}
	{tag "weapon"}
}
{State "heavymgun_recoil"
	{transit "heavymgun_with"}
	{tag "squat"}
	{tag "recoil"}
	{tag "weapon"}
}
{State "heavymgun-reload"
	{transit "heavymgun_load_delay"}
	{tag "squat"}
	{tag "reload"}
	{tag "weapon"}
}
{State "heavymgun_load_delay"
	{transit "heavymgun_with"}
	{tag "squat"}
	{tag "weapon"}
}
{State "heavymgun_unload"
	{transit "heavymgun_load_delay"}
	{tag "squat"}
	{tag "unload"}
	{tag "weapon"}
}
{State "heavymgun_drop"
	{to "heavymgun_unmount"}
	{tag "squat"}
	{tag "heavymgun-drop"}
}
{State "heavymgun_unmount"
	{to "squat"}
	{tag "squat"}
}


;;;;=========================== END OF STANDARD BEHAVIOUR NNPLAYA

{State "lie_heavymgun_pick"
	{from "lie"}
	{to "lie"}
	;{tag "up"}
	{tag "heavymgun-pick"}
}
{State "lie_heavymgun_aim"
	{from "lie"}
	{to "lie_heavymgun_fire"}
	{to "lie"}
;	{tag "up"}
	{tag "aim-heavymgun"}
	{tag "weapon"}
}
{State "lie_heavymgun_fire"
	{from "lie"}
	{to "lie_heavymgun_recoil"}
;	{tag "up"}
	{tag "fire-heavymgun"}
	{tag "weapon"}
}
{State "lie_heavymgun_recoil"
	{transit "lie"}
;	{tag "up"}
	{tag "recoil"}
	{tag "weapon"}
}
{State "lie_heavymgun_reload"
	{from "stand"}
	{transit "stand"}
;	{tag "up"}
	{tag "reload-heavymgun"}
	{tag "weapon"}
}
{State "lie_heavymgun_unload"
	{from "lie"}
	{transit "lie"}
;	{tag "up"}
	{tag "unload-heavymgun"}
	{tag "weapon"}
}
{State "lie_heavymgun_drop"
	{from "lie"}
	{to "lie"}
;	{tag "up"}
	{tag "heavymgun-drop"}
}
