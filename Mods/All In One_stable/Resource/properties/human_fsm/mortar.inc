;SDL

{State "bazooka_pick"
	{from "squat"}
	{condition "bazooka-pick"}
	{to "bazooka_with"}
	{tag "squat"}
	{tag "bazooka-pick"}
}
{State "bazooka_with"
	{to "bazooka_fire"}
	{to "bazooka_reload"}
	{to "bazooka_unload"}
	{to "bazooka_drop"}
	{to "bazooka_ground_drop"}
	{to "bazooka_idle"}
	{tag "squat"}
	{tag "weapon"}
	{tag "aim"}
	{tag "rotate"}
	{tag "hold-bazooka"}
	{tag "hold-back"}
	{tag "stop-hold-back"}
	{tag "stop-rotate"}
	{tag "stop-move"}
	{tag "stored"}
}
{State "bazooka_ground_drop" 
	{condition "ground-drop"}
	{to "squat"}
	{tag "squat"}
	{tag "ground-drop"}
}
{State "bazooka_idle"
	{to "bazooka_with"}
	{tag "idle"}
	{tag "squat"}
}
{State "bazooka_fire"
	{to "bazooka_recoil"}
	{tag "squat"}
	{tag "fire"}
	{tag "weapon"}
}
{State "bazooka_recoil"
	{transit "bazooka_with"}
	{tag "squat"}
	{tag "recoil"}
	{tag "weapon"}
}
{State "bazooka_reload"
	{transit "bazooka_load_delay"}
	{tag "squat"}
	{tag "reload"}
	{tag "weapon"}
}
{State "bazooka_load_delay"
	{transit "bazooka_with"}
	{tag "squat"}
	{tag "weapon"}
}
{State "bazooka_unload"
	{transit "bazooka_load_delay"}
	{tag "squat"}
	{tag "unload"}
	{tag "weapon"}
}
{State "bazooka_drop"
	{to "bazooka_unmount"}
	{tag "squat"}
	{tag "bazooka-drop"}
}
{State "bazooka_unmount"
	{to "squat"}
	{tag "squat"}
}
