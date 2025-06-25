(include "/properties/construction.inc")
{DecalView
	{ownershadow  128 128}
	{name "shadow"}
}
{Extension "wood-tower.mdl"}

{Volume "techo"
	{Thickness 10}
	{able {visible 0}}
}
{Volume "body"
	{Thickness 10}
	{able {visible 0}}
}
{Volume "fire5"
	{able {visible 0}}
}
{Volume "fire4"
	{able {visible 0}}
}
{Volume "fire3"
	{able {visible 0}}
}
{Volume "fire2"
	{able {visible 0}}
}
{Volume "fire1"
	{able {visible 0}}
}
{Volume "fire0"
	{able {visible 0}}
}

{Placer
	{place "mgun"
		{linkbone 	"attach"}
		{entity 	"type1_tower"}
		{handlebone "basis"}
		{turnoff {shadow}}
	}
	{place "mgun1"
		{linkbone 	"attach1"}
		{entity 	"type1_tower"}
		{handlebone "basis"}
		{turnoff {shadow}}
	}
}
{Boarder
	{door "emit1" {queue 0}}
	{door "emit2" {queue 0}}
	{node "node_ladder_bottom1"}
	{node "node_ladder_bottom2"}
	{node "node_ladder_top1"}
	{node "node_ladder_top2"}
	{anm "ladder_bind"
		{forward	{begin	"stand_climb_stairs"}}
		{reverse	{end	"stand_climb_stairs" -1}}
	}
	{anm "ladder"
		{forward	{speed 1} {loop "stand_upstairs"}}
		{reverse	{speed 1} {loop "stand_upstairs" -1}}
	}
	{link "emit1" "node_ladder_bottom1" {anm "ladder_bind"} {forward putoff} {reverse puton}}
	{link "emit2" "node_ladder_bottom2" {anm "ladder_bind"} {forward putoff} {reverse puton}}
	{link "node_ladder_bottom1" "node_ladder_top1" {anm "ladder"}}
	{link "node_ladder_bottom2" "node_ladder_top2" {anm "ladder"}}
	{link "node_ladder_top1" "mgun"}
	{link "node_ladder_top2" "mgun1"}
}
("declare_fire_volumes")
