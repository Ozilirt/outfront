;SDL
{"bridge"
	{id 7}
	{on hit
		{spawn "spheredust_small_short"}
	}
	{on detonate
		{if bullet "molotov_coctail"
			{spawn "ex_molot"}
			{spawn "fire_molot_ground"}
		else bullet "an_m14"
			{spawn "thermite"}
		else bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector}
			{spawn "fire_molot_ground"}
		else bullet "tntpack"
			{spawn "ex_bomb_big"}	
		else bullet "grenade big"
			{spawn "ex_grenade_big"}
		else bullet "grenade"
			{spawn "ex_grenade_sm"}
		else bullet "small bullet"
			{spawn "ex_bul_sm"}
		else bullet "zenite"
			{spawn "ex_bul_zenit"}
		else bullet "bullet"
			{spawn "ex_bul_big"}
		else bullet "big mortar"
			{spawn "ex_mort_big"}
		else bullet "mortar"
			{spawn "ex_bomb_big"}
		else bullet "big shell extra"
			{spawn "shockwave"}
			{spawn "ex_bomb_big"}
		else bullet "big shell fg bomb"
			{spawn "shockwave"}
			{spawn "ex_bomb_big"}
		else bullet "big shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big"}
		else bullet "big shell ap"
			{spawn "ex_arm_big"}
		else bullet "small shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_small"}
		else bullet "shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_medium"}
		else bullet "shell ap"
			{spawn "ex_arm_sm"}
		else bullet "small20 ap"
			{spawn "ex_arm_sm"}
		else bullet "shell az"
			{spawn "ex_arm_sm"}
		else bullet "shell sm"
			{spawn "ex_grenade_sm"}
			{spawn "shellhole_small"}
	                {spawn "smoke_sm"}
		else bullet "mine antipersonnel"
			{spawn "ex_grenade_big"}
		else bullet "mine antitank"
			{spawn "ex_bomb_big"}
		else bullet "dynamite"
			{spawn "ex_bomb_big"}
		else bullet "tnt"
			{spawn "ex_grenade_big"}
		else bullet "oz"
			{spawn "ex_grenade_big"}
		else bullet "eg"
			{spawn "egik"}
		else bullet "wires"
			{spawn "wires"}
		}
	}
}
