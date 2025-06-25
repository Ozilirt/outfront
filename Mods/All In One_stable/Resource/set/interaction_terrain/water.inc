;SDL

(define "water_bullets"
	{if bullet "zenite"
		{spawn "ex_bul_big_w"}
	else bullet "bullet"
		{spawn "ex_bul_sm_w"}
	else bullet "big shell extra"
		{spawn "shockwave"}
		{spawn "ex_water_extra_big"}
	else bullet "big shell ap"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "big shell fg"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "shell ap"
		{spawn "ex_water_sm"}
	else bullet "shell az"
		{spawn "ex_water_sm"}
	else bullet "small20 az"
		{spawn "ex_water_sm"}
	else bullet "mortar"
		{spawn "ex_water_extra_big"}
	else bullet "big mortar"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	}
)

(define "water_hits"
	{if min_mass 50
		{spawn "spherewater_big"}
	else min_mass 0.5
		{spawn "spherewater_small"}
	else effector "human"
		{spawn "spherewater_big"}
	else effector "steel"
		{spawn "spherewater_small"}
	}
)

(define "water_detonate"
        {if bullet "molotov_coctail"
		{spawn "spherewater_small"}
	else bullet "an_m14"
		{spawn "spherewater_small"}
	else bullet "tntpack"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "grenade big"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "grenade"
		{spawn "shockwave"}
		{spawn "ex_water_sm"}
	else bullet "mine antipersonnel"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "mine antitank"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "dynamite"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	else bullet "tnt"
		{spawn "ex_grenade_big"}
		{spawn "shellhole_big"}
	else bullet "shell fg"
		{spawn "shockwave"}
		{spawn "ex_water_big"}
	}
)

{"bad old water"
	{id 2}
	{noedit}
}
{"bad old water2"
	{id 9}
	{noedit}
}

{"shallow water"
	{id 128}
	{noedit}
	{friction  2.0}
	{restitution 0.0}
	{on bullet	("water_bullets")	}
	{on hit		("water_hits")		}
	{on detonate("water_detonate")}
}
{"water"
	{id 129}
	{friction  2.0}
	{restitution 0.0}
}
{"deep water"
	{id 130}
	{noedit}
	{friction  2.0}
	{restitution 0.0}
}
{"underwater"
	{friction  4.0}
	{restitution 0.0}
	{on detonate
		("water_detonate")
		{if bullet "shell"
			{spawn "shellhole_big_ground"}
		}
	}
}


{"puddle" ;same as shallow water, without human swimming support
	{id 10}
	{restitution 0.5}
	{friction 1.0}
	{on bullet	("water_bullets")	}
	{on hit		("water_hits")		}
	{on detonate("water_detonate")
				("water_bullets")}
}

{"shallow puddle"
	{id 14}
	{restitution 0.5}
	{friction 1.0}
	{on hit
		{if min_mass 100
			{spawn "spheredust_small"}
		else min_mass 10
			{spawn "spheredust_small_short"}
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
			{fire radius 1.5 time 1 heating 20 effector}
		else bullet "grenade big"
			{spawn "ex_grenade_big"}
			{spawn "shellhole_big"}
		else bullet "grenade"
			{spawn "ex_grenade_sm"}
			{spawn "shellhole_medium"}
		else bullet "small bullet"
			{spawn "ex_bul_sm_w"}
		else bullet "zenite"
			{spawn "ex_bul_big_w"}
		else bullet "bullet"
			{spawn "ex_bul_sm_w"}
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
			{spawn "crater_small"}
		else bullet "shell ap"
			{spawn "ex_arm_sm"}
			{spawn "shellhole_big_ground"}
		else bullet "mine antipersonnel"
			{spawn "ex_grenade_big"}
			{spawn "shellhole_medium"}
		else bullet "mine antitank"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		else bullet "shell az"
			{spawn "ex_water_sm"}
	    	else bullet "small20 az"
			{spawn "ex_water_sm"}
		else bullet "shell sm"
			{spawn "ex_water_sm"}
		else bullet "dynamite"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		else bullet "tnt"
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big"}
		else bullet "wires"
			{spawn "wires"}
		}
	}
}

(define "swamp_terrain"
	{restitution 0.5}
	{friction 1.0}
	{on hit		("water_hits")		}
	{on bullet	("water_bullets")	}
	{on detonate("water_detonate")
				("water_bullets")
		{if bullet "shell"
			{spawn "shellhole_big_ground"}
		}
	}
)

{"swamp"
	{id 3}
	("swamp_terrain")
}

{"shallow swamp"
	{id 13}
	("swamp_terrain")
}
