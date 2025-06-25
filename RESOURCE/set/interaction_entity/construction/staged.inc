{"watch_tower construction"
	{on "next_stage"
		{call "throw_human"}
	}
	{on "last_stage"
		{call "throw_human"}
	}
	{on "throw_human"
		{crew_throw_off "fly" up 4 1 dir 5 1 turn 0 180 forward 2 die}
	}
}

{"staged construction"
	{blast_absorption 0.5}
	{on spawn
		{set "stage1" 0}
		{set "last_stage" 0}
		{set "change_skeleton" 0}
		{set "first_stage" 1}
		{call "init_vars"}
	}
	{on bullet_hit
		{if volume "body"
			{if "first_stage"
				{if bullet "fg"
					{bullet_detonate}
				else bullet "shell ap"
					{delay 0.1
						{call "next_stage"}
					}
				}
			else
				{if bullet "fg"
					{bullet_detonate}
				else bullet "shell ap"
					{if rand 0.3
						{delay 0.1
							{call "next_stage"}
						}
					}
				}
			}
		}
	}
	{on blast_hit
		{if volume "body"
			{if not effector "human" 	;grenade from human
				{call "blast_effect"}
		 	}
		}
	}
	{on "blast_effect"
		{if min_energy 4
			{delay 0.1
            	{call "last_stage"}
			}
		 else min_energy 0.5
		 	{delay 0.1
				{call "next_stage"}
		 	}
		}
	}
	{on contact
		{if volume "body"
			{if effector "tank"
				{if min_speed 1
					{volumes disable contact}
					{delay 0.1
						{call "last_stage"}
					}
				}
			else effector "train_part"
				{volumes disable contact}
				{delay 0.1
					{call "last_stage"}
				}
			else effector "vehicle"
				{if min_speed 10
					{delay 0.1
						{call "next_stage"}
					}
				}
			}
		}
		{if volume "body"
			{if effector "molotov_coctail"
;				{con "burn from contact"}
				{call "burn_body"}
			else effector "vehicle"
				{if not volume "body"
					{volume disable contact}
				}
			}
		}
	}
	{on "switch_stage"
		{tags add "crushed"}
		{if "change_skeleton"
			{set "change_skeleton" 0}
			{call "set_skeleton"}
			{call "update_fx"}
		}
		{call "effects"}
		{volumes "roof" disable bullet contact blast visible}
	}
	{on "set_skeleton"
		{set_skeleton "_x" nosync}
	}
	{on "last_stage"
		{set "stop_burn" 1}
		{burn stop}
	}
	{on animation_end "crush1"
;		{con "crush2"}
		{if not "no_continue_anm"
			{ani_play "crush2" callback}
		}
		{set "no_continue_anm" 0}
		{update_shadow}
	}
	{on animation_end "crush2"
;		{con "vis_patch"}
		{update_visibility_patch}
		{update_shadow}
	}
	{on animation_end "crush3"
;		{con "vis_patch"}
		{update_visibility_patch}
		{update_shadow}
	}

	{inflammation_time 10}
;	{on "burn_volume"
;		(define "safe_burn_wall"
;		;if
;			volume "fire%0"
;				{if not "burn_fire%0"
;					{if not "first_burn"
;						{set "first_burn" 1}
;						{delay 20
;							{call "next_stage"}
;						}
;					}
;					{set "burn_fire%0" 1}
;					{burn volume "fire%0" fx "smoke_dead_tree1" time 30 2 fake}
;					{fire volume "fire%0" radius 5 time 30}
;				}
;		)
;		{if		("safe_burn_wall" args 0)
;		else 	("safe_burn_wall" args 1)
;		else 	("safe_burn_wall" args 2)
;		else 	("safe_burn_wall" args 3)
;		else 	("safe_burn_wall" args 4)
;		else 	("safe_burn_wall" args 5)
;		else 	("safe_burn_wall" args 6)
;		else 	("safe_burn_wall" args 7)
;		else 	("safe_burn_wall" args 8)
;		else 	("safe_burn_wall" args 9)
;		}
;	}
	(define "burn_volume"
		{delay %1 0.7
			{if not "stop_burn"
				{burn volume "fire%0" fx "smoke_dead_tree1" time 25 fake even_law}
				{fire volume "fire%0" radius 2 time 10}
			}
		}
	)
	(define "burn_from_volume"
		{if not burned
			{if volume %0
;				{con "construction burning"}
				("burn_volume" args %1 %2)
				("burn_volume" args %3 %4)
				("burn_volume" args %5 %6)
				("burn_volume" args %7 %8)
				("burn_volume" args %9 %10)
				("burn_volume" args %11 %12)
				("burn_volume" args %13 %14)
				("burn_volume" args %15 %16)
				("burn_volume" args %17 %18)
				{burn time 30 2}
				{delay 20
					{call "next_stage"}
				}
			}
		}
	)
	{on "burn_process"
		{if not "last_stage"
			("burn_from_volume" args "fire0"	0 1		1 2		2 4		3 6		4 8		5 9		6 8		7 6		8 4		9 2)
			("burn_from_volume" args "fire1"	1 1		2 2		3 4		4 6		5 8		6 9		7 8		8 6		9 4		0 2)
			("burn_from_volume" args "fire2"	2 1		3 2		4 4		5 6		6 8		7 9		8 8		9 6		0 4		1 2)
			("burn_from_volume" args "fire3"	3 1		4 2		5 4		6 6		7 8		8 9		9 8		0 6		1 4		2 2)
			("burn_from_volume" args "fire4"	4 1		5 2		6 4		7 6		8 8		9 9		0 8		1 6		2 4		3 2)
			("burn_from_volume" args "fire5"	5 1		6 2		7 4		8 6		9 8		0 9		1 8		2 6		3 4		4 2)
			("burn_from_volume" args "fire6"	6 1		7 2		8 4		9 6		0 8		1 9		2 8		3 6		4 4		5 2)
			("burn_from_volume" args "fire7"	7 1		8 2		9 4		0 6		1 8		2 9		3 8		4 6		5 4		6 2)
			("burn_from_volume" args "fire8"	8 1		9 2		0 4		1 6		2 8		3 9		4 8		5 6		6 4		7 2)
			("burn_from_volume" args "fire9"	9 1		0 2		1 4		2 6		3 8		4 9		5 8		6 6		7 4		8 2)
			("burn_from_volume" args "body"		1 1		2 2		3 4		4 6		5 8		6 9		7 8		8 6		9 4		0 2)
			("burn_from_volume" args "body1"	2 1		3 2		4 4		5 6		6 8		7 9		8 8		9 6		0 4		1 2)
		}
	}
	{on "burn_body"
		{if volume "fire"
			{if not burned
				{if not "last_stage"
					{burn volume fx "smoke_dead_tree1" time 30 2 fake even_law}
					{fire radius 2 time 30}
					{burn time 30 2}
					{delay 20
						{call "next_stage"}
					}
				}
			}
		else
			{call "burn_process"}
		}
	}
	{on "burn_volume"
		{if volume "body"
			{call "burn_body"}
		else volume "roof"
			{call "burn_body"}
		else volume "fire"
			{call "burn_process"}
		}
	}
}

{"two staged construction"
	{on "init_vars"
		{set "change_skeleton" 1}
	}
	{on "next_stage"
		{if not "stage1"
			{set "stage1" 1}
			{call "switch_stage"}
			{set "no_continue_anm" 1}
			{ani_play "crush1" callback}
;		else not "stage2"
;			{set "stage2" 1}
		else
			{call "last_stage"}
		}
	}
	{on "last_stage"
		{if not "last_stage"
			{set "last_stage" 1}
;			{con "switch to last stage"}
			{call "disable_volumes"}
			{call "switch_stage"}
			{if not "stage1"
				{set "stage1" 1}
;				{con "crush1"}
				{ani_play "crush1" callback}
			else
				{ani_play "crush2" callback}
			}
		}
	}
}

{"one staged construction"
	{on "init_vars"
		{set "change_skeleton" 1}
	}
	{on "next_stage"
		{if not "stage1"
			{call "last_stage"}
		}
	}
	{on "last_stage"
;		{con "last_stage entering"}
		{if not "last_stage"
			{set "last_stage" 1}
;			{con "switch to last stage"}
			{call "disable_volumes"}
			{call "switch_stage"}
			{if not "stage1"
				{set "stage1" 1}
;				{con "crush1"}
				{ani_play "crush1" callback}
			else
				{ani_play "crush2" callback}
			}
		}
	}
}

{"massive construction"
	{on "init_vars"
		{set "change_skeleton" 1}
	}
	{on "next_stage"
		{if not "stage1"
			{set "stage1" 1}
			{call "switch_stage"}
			{ani_play "crush1"}
;		else not "stage2"
;			{set "stage2" 1}
		else
			{call "last_stage"}
		}
	}
	{on "last_stage"
		{if not "last_stage"
			{set "last_stage" 1}
;			{con "switch to last stage"}
			{call "switch_stage"}
			{if not "stage1"
				{set "stage1" 1}
;				{con "crush1"}
				{ani_play "crush1" callback}
			else
				{ani_play "crush2" callback}
			}
		else
			{call "crush_stage"}
		}
	}
	{on "crush_stage"
		{call "disable_volumes"}
		{call "switch_stage"}
		{ani_play "crush3" callback}
	}
}

{"no_destroyed_stamp"
	{on "destroyed_stamp" overload
	}
}

{"no_disable_volumes"
	{on "disable_volumes" overload
	}
}

{"disable_area construction"
	{on "last_stage"
		{area disable}
	}
}

{"small staged construction"
	{on blast_hit overload
		{if volume "body"
			{call "blast_effect"}
		}
	}
}
