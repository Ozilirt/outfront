game_entity
	{volume "post"
		{thickness 3}
	}
	{simulatorId "pillar"}
	{colliderID "tree"}
	{obstacleID "tree"}
	{mass 200}
	{props "post" "pillar"}
;	(include "/properties/shadow/construction.inc" sx(1) sy(0.18))
	(include "seasons.inc")
	{extender "light"
		{lightfx "light_post"}
		{breakfx "glass_hit"}
	}
