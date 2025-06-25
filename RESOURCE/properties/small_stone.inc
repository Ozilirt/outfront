{colliderID "particle"}
{collideWith  "bush" "human" "armored" "vehicle" "construction"}
{obstacleID "unbreakable"}
;(include "shadow/stone.inc" sx(%sx) sy(%sy))
(include "seasons.inc")
{props "concrete" "big" "part" "stone"}
{simulation {able 1} {state 0}}
{mass 100}

{Volume "rock"
	{thickness 500}
}
{Volume "body"
	{thickness 500}
}
