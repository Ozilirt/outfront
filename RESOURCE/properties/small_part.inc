game_entity
	{simulation {able 1} {state 1}}
	{constrain none}
	{obstacleID "construction"}
	{colliderId "particle"}
	{collideWith  "bush" "human"}
	{props "small" "part"}
	{mass 10}
	{DecalView
		{ownershadow 32 32}
		{name "shadow"}
		{Sprite "/properties/shadow/human.ebm"
			{Scale 0.35 }
			{Visibility 0.5}
		}
		{UseDirection}
		{Layer groundshadow}
	}
	{volume "body"
		{able {obstacle 0}}
		{thickness 1}
	}