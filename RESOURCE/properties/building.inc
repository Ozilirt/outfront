game_entity
	{colliderID "construction"}
	{obstacleID "building"}
	{volume "body"
		{thickness hollow 5}
		{tags "body"}
	}
	{volume "body1"
		{thickness hollow 5}
		{tags "body"}
	}
	{mass 3000}
;	(include "/properties/shadow/construction.inc" sx(1) sy(0.18))
	(include "burning.inc")
	(include "texmod.inc")
