;SDL
{"ground"
	{id 1}
	{restitution 0.5}
	{friction 1.0}
	{on hit
		{if min_mass 100
			{if effector "tree"
				{spawn "tree_crush"}
			else
				{spawn "spheredust_small"}
			}
		else min_mass 10
			{spawn "spheredust_small_short"}
		}
	}
	{on detonate
		{if bullet "molotov_coctail"
			{spawn "ex_molot"}
			{spawn "fire_molot_ground"}
			{spawn "fire_shellhole"}
		else bullet "grenade big"
			{spawn "ex_grenade_big"}
			{spawn "shellhole_big"}
		else bullet "grenade"
			{spawn "ex_grenade_sm"}
			{spawn "shellhole_medium"}
		else bullet "small bullet"
			{spawn "ex_bul_sm"}
		else bullet "zenite"
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small"}
		else bullet "bullet"
			{spawn "ex_bul_big"}
		else bullet "big mortar"
			{spawn "ex_mort_big"}
			{spawn "shellhole_big"}
		else bullet "mortar"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_medium"}
		else bullet "big shell extra"
			{spawn "shockwave"}
			{spawn "ex_bomb_big" offset 0 0 20}
			{spawn "crater_norm"}
		else bullet "big shell fg bomb"
			{spawn "shockwave"}
			{spawn "ex_bomb_big"}
			{spawn "crater_norm"}
		else bullet "big shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big"}
			{spawn "crater_norm"}
		else bullet "big shell ap"
			{spawn "ex_arm_big"}
			{spawn "shellhole_big_ground"}
		else bullet "small shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_small"}
			{spawn "shellhole_big_ground"}
		else bullet "shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_medium"}
			{spawn "crater_norm"}
		else bullet "shell ap"
			{spawn "ex_arm_sm"}
			{spawn "shellhole_big_ground"}
		else bullet "mine antipersonnel"
			{spawn "ex_grenade_big"}
			{spawn "shellhole_medium"}
		else bullet "mine antitank"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		else bullet "dynamite"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		}
	}
}
