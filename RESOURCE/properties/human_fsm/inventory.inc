;SDL

{State "ground_drop"
	{to "ground_drop_out"}
	{tag "up"}
	{tag "ground-drop"}
}
{State "ground_drop_out"
	{to "stand"}
	{tag "up"}
}
{State "ground_pick"
	{condition "ground-pick"}
	{to "ground_pick_item"}
	{to "ground_pick_bazooka"}
	{tag "up"}
	{tag "ground-pick"}
}
{State "ground_pick_item"
	{to "stand"}
	{tag "up"}
}
{State "ground_pick_bazooka"
	{to "bazooka_with"}
	{tag "up"}
}
