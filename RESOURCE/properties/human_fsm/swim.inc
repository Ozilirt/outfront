;SDL

{state "swim_in_from_stand"
	{condition "swim"}
	{from "stand"}
	{transit "swim_idle"}
	{tag "swim"}
}
{state "swim_in_from_lie"
	{condition "swim"}
	{from "lie"}
	{transit "swim_idle"}
	{tag "swim"}
}
{state "swim_idle"
	{to "swim_out_to_stand"}
	{to "swim_out_to_lie"}
	{to "swim"}
	{to "swim_inventory"}
	{tag "board-begin"}
	{tag "swim"}
	{tag "idle"}
	{tag "rotate"}
	{tag "stop-move"}
	{tag "stop-rotate"}
	{tag "switch-move"}
	{tag "stored"}
	{tag "unboard-to-water"}
}
{state "swim_inventory";inventory stuffing tags support
	{to "swim_idle"}
	{tag "inventory-pick"}
	{tag "inventory-drop"}
	{tag "hold-item"}
	{tag "hold-nothing"}
	{tag "reload"}
	{tag "unload"}
	{tag "ground-drop"}
	{tag "belt-drop"}
	{tag "pistol-drop"}
	{tag "swim"}
}
{state "swim"
	{to "swim_idle"}
	{tag "swim"}
	{tag "move"}
}
{state "swim_out_to_stand"
	{condition "up"}
	{transit "stand"}
	{tag "swim"}
}
{state "swim_out_to_lie"
	{condition "down"}
	{transit "lie"}
	{tag "swim"}
}
