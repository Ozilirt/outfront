;SDL

; moved to water.inc

;{"puddle"
;	{id 10}
;	{restitution 0.5}
;	{friction 1.0}
;	{on hit
;		{if min_mass 100
;			{spawn "spheredust_small"}
;		else min_mass 10
;			{spawn "spheredust_small_short"}
;		}
;	}
;	{on detonate
;		{if bullet "molotov_coctail"
;			{spawn "ex_molot"}
;		else bullet "grenade"
;			{spawn "ex_grenade_big"}
;			{spawn "shellhole_medium"}
;		else bullet "small bullet"
;			{spawn "ex_bul_sm_w2"}
;		else bullet "zenite"
;			{spawn "ex_bul_big_w"}
;			{spawn "shellhole_small"}
;		else bullet "bullet"
;			{spawn "ex_bul_sm_w2"}
;		else bullet "big mortar"
;			{spawn "ex_mort_big"}
;			{spawn "shellhole_big"}
;		else bullet "mortar"
;			{spawn "ex_mort_sm"}
;			{spawn "shellhole_medium"}
;		else bullet "big shell extra"
;			{spawn "shockwave"}
;			{spawn "ex_bomb_big"}
;			{spawn "crater_norm"}
;		else bullet "big shell fg"
;			{spawn "shockwave"}
;			{spawn "ex_anti_big"}
;			{spawn "crater_norm"}
;		else bullet "big shell ap"
;			{spawn "ex_arm_big"}
;			{spawn "crater_small"}
;		else bullet "small shell fg"
;			{spawn "shockwave"}
;			{spawn "ex_anti_small"}
;			{spawn "crater_norm"}
;		else bullet "shell fg"
;			{spawn "shockwave"}
;			{spawn "ex_anti_medium"}
;			{spawn "crater_norm"}
;		else bullet "shell ap"
;			{spawn "ex_arm_sm"}
;			{spawn "crater_small"}
;		}
;	}
;}
