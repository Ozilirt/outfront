;SDL

{State "stand"
	{split "stand" "linked"}
	{to "stand_animation"}
	{to "stand_inventory_in"}
	{to "stand_inventory_out"}
	{to "stand_reload"}
	{to "stand_unload"}
	{to "stand_throw_begin"}
	{to "stand_switch"}
	{to "walk"}
	{to "repair"}
	{to "idle"}

	{tag "up"}
	{tag "stored"}
	{tag "look-out"}
	{tag "rotate"}
	{tag "hold-item"}
	{tag "hold-nothing"}
	{tag "hold-bazooka"}
	;{tag "hold-mortar"}
	{tag "unboard-to-ground"}
	{tag "board-begin"}
	{tag "switch-move"}
	{tag "stop-move"}
	{tag "stop-repair"}
	{tag "stop-rotate"}
	{tag "stop-animation"}
	{tag "stop-hold-back"}
}
{State "idle"
	{split "stand" "linked"}
	{to "stand"}
	{tag "idle"}
	{tag "up"}
}
{State "stand_switch"
	{split "stand" "switch_begin"}
	{to "stand"}
	{tag "switch-weapon"}
	{tag "up"}
}
{State "stand_inventory_in"
	{split "stand" "inventory_in"}
	{to "stand"}
	{tag "up"}
	{tag "inventory-drop"}
}
{State "stand_inventory_out"
	{split "stand" "inventory_out"}
	{to "stand"}
	{tag "up"}
	{tag "inventory-pick"}
	{tag "inventory-pick-stand"}
}
{State "stand_holdback_in"
	{split "stand" "holdback_in"}
	{from "stand"}
	{to "stand_holdback_out"}
	{tag "up"}
	{tag "weapon"}
	{tag "hold-back"}
	{tag "rotate"}
	{tag "stop-rotate"}
}
{State "stand_holdback_out"
	{split "stand" "holdback_out"}
	{to "stand"}
	{tag "up"}
	{tag "weapon"}
}
{State "stand_aim_prepare"
	{split "stand" "aim_prepare"}
	{from "stand"}
	{to "stand_aim"}
	{tag "up"}
	{tag "weapon"}
}
{State "stand_aim"
	{split "stand" "aim"}
	{to "stand_fire"}
	{to "stand"}
	{tag "up"}
	{tag "aim"}
	{tag "aim-thrower"}
	{tag "weapon"}
}
{State "stand_fire"
	{split "stand" "fire"}
	{to "stand_recoil"}
	{tag "up"}
	{tag "fire"}
	{tag "weapon"}
}
{State "stand_recoil"
	{split "stand" "recoil"}
	{transit "stand_aim"}
	{tag "up"}
	{tag "weapon"}
	{tag "recoil"}
}
{State "stand_reload"
	{split "stand" "reload"}
	{transit "stand"}
	{tag "up"}
	{tag "reload"}
	{tag "weapon"}
}
{State "stand_unload"
	{split "stand" "unload"}
	{transit "stand"}
	{tag "up"}
	{tag "unload"}
	{tag "weapon"}
}
{State "stand_throw_begin"
	{transit "stand_throw_end"}
	{tag "throw"}
	{tag "up"}
}
{State "stand_throw_end"
	{transit "stand"}
	{tag "up"}
}
{State "stand_belt_in"
	{split "stand" "belt_in"}
	{from "stand"}
	{to "stand_belt_out"}
	{tag "belt-drop"}
	{tag "up"}
}
{State "stand_belt_out"
	{split "stand" "belt_out"}
	{to "stand"}
	{tag "belt-pick"}
	{tag "up"}
}
{State "stand_pistol_in"
	{split "stand" "pistol_in"}
	{from "stand"}
	{to "stand_pistol_out"}
	{tag "pistol-drop"}
	{tag "up"}
}
{State "stand_pistol_out"
	{split "stand" "pistol_out"}
	{to "stand"}
	{tag "pistol-pick"}
	{tag "up"}
}
{State "stand_item_in_begin"	; 2hand & 1hand items
	{from "stand"}
	{to "stand_item_in_end"}
	{tag "item-drop"}
	{tag "up"}
}
{State "stand_item_in_end"		; 2hand & 1hand items
	{to "stand"}
	{tag "up"}
}
{State "stand_item_out_begin"   ; 2hand & 1hand items
	{from "stand"}
	{to "stand_item_out_end"}
	{tag "up"}
}
{State "stand_item_out_end"   ; 2hand & 1hand items
	{to "stand"}
	{tag "item-pick"}
	{tag "up"}
}
{State "stand_animation"
	{to "stand"}
	{tag "up"}
	{tag "animation"}
}
{State "repair"
	{to "stand"}
	{tag "repair"}
	{tag "up"}
}
