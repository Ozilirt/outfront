;SDL
{"grass"
	{id 8}
	{friction  1.5}
	{restitution 0.3}
	{on hit
		{if min_mass 100
			{if effector "tree"
				{spawn "tree_crush"}
			else
				{spawn "spheredust_small"}
			}
		else min_mass 10
			{if not effector "tree"
				{spawn "spheredust_small_short"}
			}
		}
		{if bullet "shell sm"
			{spawn "fire_molot_ground"}
			{spawn "ex_grenade_sm"}
			{spawn "shellhole_medium"}
			{call "activate"}
		}
	}
	{on detonate
		{if bullet "molotov_coctail"
			{spawn "ex_molot"}
			{spawn "fire_molot_ground"}
			{spawn "fire_shellhole"}
		else bullet "an_m14"
			{spawn "thermite"}
			{spawn "fire_shellhole"}
		else bullet "flame"
			{spawn "fire_molot_ground"}
			{fire radius 1.5 time 2 heating 20 effector}
		else bullet "tntpack"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}	
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
			{spawn "ex_bomb_big"}
			{spawn "crater_big"}
		else bullet "big shell fg bomb"
			{spawn "shockwave"}
			{spawn "ex_bomb_big"}
			{spawn "crater_big"}
		else bullet "big shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big"}
			{spawn "crater_norm"}
		else bullet "big shell ap"
			{spawn "ex_arm_big"}
			{spawn "shellhole_medium"}
		else bullet "small shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_small"}
			{spawn "shellhole_big"}
		else bullet "shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_medium"}
			{spawn "shellhole_big"}
		else bullet "shell ap"
			{spawn "ex_arm_sm"}
			{spawn "shellhole_big"}
		else bullet "shell sm"
			{spawn "ex_grenade_sm"}
			{spawn "shellhole_small"}
	                {spawn "smoke_sm"}
		else bullet "shell az"
			{spawn "ex_az"}
			{spawn "ex_arm_sm"}
			{spawn "shellhole_big"}
		else bullet "small20 az"
			{spawn "ex_az"}
			{spawn "ex_arm_sm"}
			{spawn "shellhole_big"}
		else bullet "mine antipersonnel"
			{spawn "ex_grenade_big"}
			{spawn "shellhole_medium"}
		else bullet "mine antitank"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		else bullet "dynamite"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		else bullet "tnt"
			{spawn "ex_grenade_big"}
			{spawn "shellhole_big"}
		else bullet "oz"
			{spawn "ex_grenade_big"}
			{spawn "crater_okop"}
		else bullet "eg"
			{spawn "egik"}
		else bullet "wires"
			{spawn "wires"}
		}
	}
}
