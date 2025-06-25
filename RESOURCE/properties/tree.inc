game_entity
	(include "seasons.inc")
	{volume "bole"
		{able {touch 0}}
		{thickness 3}
	}
	{volume "crown"
		{able
			{contact 0} {contact_ground 0}
			{bullet 0} {obstacle 0}
			{overlap 1}
			{touch 0}
		}
		{density 0.007}
	}
	{simulatorId "pillar"}
	{colliderID "tree"}
	{obstacleID "tree"}
	{mass 200}
	{props "tree" "pillar"}
;	{NoCastShadows}
	{NoGetShadows}
