;SDL

{State "lie"
	{to "lie_idle"}
	{to "lie_fire"}
	{to "lie_reload"}
	{to "lie_unload"}
	{to "lie_rotate"}
	{to "lie_inventory_in"}
	{to "lie_inventory_out"}
	{to "crawl"}
	{tag "down"}
	{tag "quick-down"}
	{tag "switch-move"}
	{tag "stop-move"}
	{tag "stop-rotate"}
	{tag "stop-hold-back"}
	{tag "hold-item"}
	{tag "hold-nothing"}
	{tag "stored"}
}
{State "lie_holdback_in"
	{from "lie"}
	{to "lie_holdback_out"}
	{tag "down"}
	{tag "weapon"}
	{tag "hold-back"}
}
{State "lie_holdback_out"
	{to "lie"}
	{tag "down"}
	{tag "weapon"}
}
{State "lie_from_stand"
	{condition "quick-down"}
	{from "stand"}
	{transit "lie"}
	{tag "up"}
}
{State "lie_switch"
	{from "lie"}
	{to "lie"}
	{tag "down"}
	{tag "switch-weapon"}
}
{State "lie_idle"
	{to "lie"}
	{tag "idle"}
	{tag "down"}
}
{State "lie_inventory_in"
	{to "lie"}
	{tag "down"}
	{tag "inventory-drop"}
}
{State "lie_inventory_out"
	{to "lie"}
	{tag "down"}
	{tag "inventory-pick"}
}
{State "lie_aim_prepare"
	{from "lie"}
	{to "lie_aim"}
	{tag "down"}
	{tag "weapon"}
}
{State "lie_aim"
	{to "lie_fire"}
	{to "lie"}
	{tag "down"}
	{tag "aim"}
	{tag "aim-thrower"}
	{tag "aim-heavy_mgun"}
	{tag "weapon"}
}
{State "lie_fire"
	{to "lie_recoil"}
	{tag "down"}
	{tag "fire"}
	{tag "fire-heavy_mgun"}
	{tag "weapon"}
}
{State "lie_recoil"
	{transit "lie_aim"}
	{tag "down"}
	{tag "recoil"}
	{tag "weapon"}
}
{State "lie_reload"
	{transit "lie"}
	{tag "down"}
	{tag "reload"}
	{tag "weapon"}
}
{State "lie_unload"
	{transit "lie"}
	{tag "down"}
	{tag "unload"}
	{tag "weapon"}
}
{State "crawl"
	{to "lie"}
	{tag "move"}
	{tag "down"}
}
{State "lie_rotate"
	{to "lie"}
	{to "lie_rotate_l45"}
	{to "lie_rotate_r45"}
	{tag "rotate"}
	{tag "down"}
}
{State "lie_rotate_l45"
	{to "lie_rotate"}
	{tag "rotate-l45"}
	{tag "down"}
}
{State "lie_rotate_r45"
	{to "lie_rotate"}
	{tag "rotate-r45"}
	{tag "down"}
}
{State "lie_throw_begin"
	{from "lie"}
	{transit "lie_throw_end"}
	{tag "throw"}
	{tag "down"}
}
{State "lie_throw_end"
	{transit "lie"}
	{tag "down"}
}
{State "lie_belt_in"
	{from "lie"}
	{to "lie_belt_out"}
	{tag "belt-drop"}
	{tag "pistol-drop"}
	{tag "down"}
}
{State "lie_belt_out"
	{to "lie"}
	{tag "belt-pick"}
	{tag "pistol-pick"}
	{tag "down"}
}
