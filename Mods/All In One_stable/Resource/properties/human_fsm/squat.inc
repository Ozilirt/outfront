;SDL

{State "squat"
	{to "squat_switch"}
	{to "squat_reload"}
	{to "squat_unload"}
	{to "squat_inventory_in"}
	{to "squat_inventory_out"}
	{tag "squat"}
	{tag "squat-cover"}
	{tag "idle"}
	{tag "rotate"}
	{tag "stop-rotate"}
	{tag "stop-move"}
	{tag "stop-hold-back"}
	{tag "stored"}
	{tag "hold-item"}
	{tag "hold-nothing"}
	{tag "hold-bazooka"}
	{tag "hold-mortar"}
}
{State "squat_holdback_in"
	{from "squat"}
	{to "squat_holdback_out"}
	{tag "squat"}
	{tag "weapon"}
	{tag "hold-back"}
}
{State "squat_holdback_out"
	{to "squat"}
	{tag "squat"}
	{tag "weapon"}
}
{State "squat_hide_in"
	{from "squat"}
	{tag "squat"}
	{transit "squat_hide"}
}
{State "squat_hide"
	{to "squat_hide_out"}
	{tag "squat"}
	{tag "squat-hide"}
}
{State "squat_hide_out"
	{transit "squat"}
	{tag "squat"}
}
{State "squat_switch"
	{to "squat"}
	{tag "squat"}
	{tag "switch-weapon"}
}
{State "squat_inventory_in"
	{to "squat"}
	{tag "squat"}
	{tag "inventory-drop"}
	{tag "bazooka-drop"}
	{tag "mortar-drop"}
}
{State "squat_inventory_out"
	{to "squat"}
	{tag "squat"}
	{tag "inventory-pick"}
	{tag "bazooka-pick"}
	{tag "mortar-pick"}
}
{State "squat_aim_prepare"
	{from "squat"}
	{to "squat_aim"}
	{tag "squat"}
	{tag "aim"}
	{tag "weapon"}
}
{State "squat_aim"
	{to "squat_fire"}
	{to "squat"}
	{tag "squat"}
	{tag "aim"}
	{tag "aim-thrower"}
	{tag "aim-bazooka"}
	{tag "aim-mortar"}
	{tag "weapon"}
        {tag "aim-heavy_mgun"}
}
{State "squat_fire"
   	{to "squat_recoil"}
	{tag "squat"}
	{tag "fire"}
	{tag "fire-bazooka"}
	{tag "fire-mortar"}
        {tag "fire-heavy_mgun"}
	{tag "weapon"}
}
{State "squat_recoil"
   	{transit "squat_aim"}
	{tag "squat"}
	{tag "weapon"}
	{tag "recoil"}
}
{State "squat_reload"
	{transit "squat"}
	{tag "squat"}
	{tag "reload"}
	{tag "reload-bazooka"}
	{tag "reload-mortar"}
	{tag "weapon"}
}
{State "squat_unload"
	{transit "squat"}
	{tag "squat"}
	{tag "unload"}
	{tag "unload-bazooka"}
	{tag "unload-mortar"}
	{tag "weapon"}
}
{State "squat_belt_in"
	{from "squat"}
	{to "squat_belt_out"}
	{tag "belt-drop"}
	{tag "pistol-drop"}
	{tag "squat"}
}
{State "squat_belt_out"
	{to "squat"}
	{tag "belt-pick"}
	{tag "pistol-pick"}
	{tag "squat"}
}
{State "squat_throw_begin"
	{from "squat"}
	{transit "squat_throw_end"}
	{tag "throw"}
	{tag "squat"}
}
{State "squat_throw_end"
	{transit "squat"}
	{tag "squat"}
}
{State "squat_to_stand"
	{from "squat"}
	{transit "stand"}
	{tag "up"}
}
{State "squat_to_lie"
	{from "squat"}
	{transit "squat_delay_lie"}
	{tag "down"}
}
{State "squat_delay_lie"
	{transit "lie"}
	{tag "down"}
}
{State "squat_from_stand"
	{from "stand"}
	{transit "squat"}
	{tag "squat"}
}
{State "squat_from_lie"
	{from "lie"}
	{transit "squat"}
	{tag "squat"}
}
