;SDL
{"air"
	{on detonate
		{if bullet "molotov_coctail"
			{spawn "ex_molot"}
		else bullet "flame"
			{spawn "ex_flamethrower"}
		else bullet "grenade"
			{spawn "ex_air_big"}
;		else bullet "zenite"
;			{spawn "ex_air_norm"}
;		else bullet "shell fg"
;			{spawn "ex_air_big"}
;		else bullet "mortar"
;			{spawn "ex_air_big"}
;		else bullet "bazooka"
;			{spawn "ex_air_big"}
		}
	}
}
