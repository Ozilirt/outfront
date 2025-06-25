game_entity
	{simulation {able 1} {state 1}}
	{constrain none}
	{obstacleID "construction"}
	{colliderId "particle"}
	{collideWith  "bush" "human" "vehicle" "tank" "armored" "construction"}
	{props "big" "part"}
	{mass 50}
	{DecalView
		{ownershadow 32 32}
		{name "shadow"}
		{Sprite "/properties/shadow/human.ebm"
			{Scale 0.85 }
			{Visibility 0.4}
		}
		{UseDirection}
		{Layer groundshadow}
	}
