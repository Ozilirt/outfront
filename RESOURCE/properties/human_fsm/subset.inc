;SDL

{subset "default"
	{disable "weapon"}
	{disable "open-with-item"}
}
{subset "with_item" from "default"
	{disable "down"}
	{disable "squat"}
	{disable "looking"}
	{disable "repair"}
	{enable "open-with-item"} ; to enable item ops in snipe cover
}
{subset "with_weapon" from "default"
	{enable  "weapon"}
	{disable "repair"}
}
{subset "on_board"
	{disable "up"}
	{disable "down"}
	{disable "squat"}
	{enable  "board"}
}
