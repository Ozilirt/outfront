{"human"
	{inflammation_time 1}
	{on spawn
		{add_view	"cigarettesmoke"		"smoke"		"head"}
		{add_view	"drops_water_small2"	"on_water"	"foot3r"}
		{add_view	"drops_water_small2"	"on_water"	"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"foot3r"}
		{add_view	"drops_water_small3"	"swim"		"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"hand2r"}
		{add_view	"drops_water_small3"	"swim"		"hand2l"}
		{add_view	"wash_human_small"		"swim_move"	"head"}
		{add_view	"drops_puddle_small"	"on_puddle"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_puddle"	"foot3l"}
		{add_view	"drops_puddle_small"	"die_in_swamp"	"foot3r"}
		{add_view	"drops_puddle_small"	"die_in_swamp"	"foot3l"}
		{add_view	"human_selection" 		 "selection" "basis"}
		{add_view	"human_linked_selection" "linked_selection" "head"}
		{link_sound "move" "human.move"}
		{if "burning"
			{call "add_burn_fx"}
			{view start "burn_fire"}
		}
	}
	{on contact 
		{kill_flags reset}
		{if effector "tank"
			{volumes disable contact}
			{health_damage_crush "die" "crush"}
		else effector "vehicle"
			{volumes disable contact}
			{if not dead
				{call "die"}
			else
				{spawn "bloodsparks_small"}
				{delay 2
					{volumes enable contact}
				}
			}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count "hit" "damage" "die_from_knife" "die_from_knife" 110}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count "hit" "damage" "die" "die" 180}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count "hit" "damage" "die" "crush" 60}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count "hit" "damage" "die" "crush" 40}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count "hit" "damage" "die" "die" 20}
			}
		else effector "wire"
			{health_damage_count "hit" "damage" "die" "die" 20}
		}
	}
	{on bullet_hit
		{if bullet "shell fg"
			{bullet_detonate}
		else bullet "bazooka"
			{bullet_detonate}
		else bullet "bullet"
			{if volume_armored
				{bullet_detonate}
			}
		}
		{kill_flags reset}
		{if hit_side front	{kill_flags front}
		else hit_side back	{kill_flags back}
		}
		{if velocity 7
			{kill_flags run}
		else velocity 0.1
			{kill_flags go}
		}
		{if	bullet "rifle"	{kill_flags rifle}}
		{if	bullet "mgun"	{kill_flags mgun}}
		{if	bullet "smg"	{kill_flags smg}}
		{if	bullet "pistol"	{kill_flags smg}}

		{health_damage_pierce "hit" "damage" "die" "die_throw_high"}
		{if volume "head"
			{if rand 0.5
				{take_off "head"
					{impulse up 5 2 dir 7 3}
				}
			}
		}
	}
	{on blow
		{if name "knife"
			{health_damage_blow "hit" "hit" "die_from_knife" "die_from_knife"}
		else
			{start_sound "man_blow"}
			{health_damage_blow "hit" "hit" "die" "die"}
		}
	}
	{on blast_hit overload
		{kill_flags reset}
		{if hit_side front	{kill_flags front}}
		{if hit_side back	{kill_flags back}}
		{if min_energy 0.6
			{kill_flags exp_big}
		else min_energy 0.4
			{kill_flags exp}
		}

;		{throw_off "fly" up 6 1 dir 4 1}

		{set "die_after_throw" 0}
		{health_damage_blast "hit" "hit" "die" "die_throw_high"
			{0.1	10}
			{10		10000}
			{1000	1000000}
		}
		{if not "die_after_throw"
			{if min_energy 2.0
				{call "throw_high"}
			}
		}
	}
	{on "die_throw_high"
		{set "die_after_throw" 1}
		{spawn "bloodsparks_small"}
		{call "die_scream"}
		{call "throw_high"}
	}
	{on "hit"
		{if not "say"
			{set "say" 1}
			{say "enemy attack"}
			{delay 10 2
				{set "say" 0}
			}
		}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{call "hit"}
	}

	(define "throw"
		{if senseless
			{if not dead
				{call "die"}
			}
		else
			{if not dead
				{if not lying
					{volumes disable bullet blast contact}
					{if "die_after_throw"
						{throw_off "fly" up %0 %1 dir %2 %3 forward %4 %5 die}
					else
						{throw_off "fly" up %0 %1 dir %2 %3 forward %4 %5}
					}
				else
					{if "die_after_throw"
						{call "die"}
					}
				}
			else
				{call "explosion"}
			}
		}
	)
	{on "throw_high"
		("throw" args 6 1 4 1 0 0)
	}
	{on "throw_off_end"
		{health_damage_count "hit" "damage" "die" "die" 50}
		{volumes enable bullet blast contact}
		{delay 4 2
			{if lying
				{if not dead
					{if not senseless
						{movement_type normal}
					}
				}
			}
		}
	}
	{on "throw_off_end_die"
		{volumes enable bullet blast contact}
		{call "die"}
	}
	{on "throw_off_from_tower"
		{throw_off "fly" up 1 forward 2 die force}
	}
	{on "throw_off_from_ladder"
		{throw_off "fly" up 1 forward -2 die force}
	}
	{on "throw_off_from_ship"
		{throw_off "fly" up 4 dir 3 1 die force}
	}
	{on "linker_simulation"
		{if not effector "airborne"
			{if altitude 3
				{throw_off "fly" up 1 forward 2 die force}
			}	
		}
	}

	{on "die_without_blood"
;		{con "die"}
		{view pause "swim"}
		{call "die_scream"}
		{die}
;		{able collect 1}
		{delay 3
			{volumes enable contact}
		}
;		{delay 30 {delete}}
	}
	{on "die"
		{spawn "bloodsparks_small"}
		{if linked
			{if linked "shipflak"
				{call "throw_off_from_ship"}
			else linked "doublecolt"
				{call "throw_off_from_ship"}
			else altitude 2
				{if boarding
					{call "throw_off_from_ladder"}
				else
					{call "throw_off_from_tower"}
				}
			else
				{call "die_with_blood"}
			}
		else
			{call "die_with_blood"}
		}
	}
	{on "die_with_blood"
		{spawn "blood"}
		{call "die_without_blood"}
	}
	{on "die_scream"
		{if not "die_sound"
			{set "die_sound" 1}
			{if "die_from_knife"
				{start_sound "man_die_from_knife"}
			else
				{start_sound "man_die"}
			}
			{able talk 0}
		}
	}
	{on "die_from_knife"
		{set "die_from_knife" 1}
		{call "die"}
	}
	{on ground_hit
		{spawn "blood"}
	}
	
	(define "imp"
		{spawn %0 %1
			{impulse	up 1 0.5 dir 8 4
						cx 0 12 cy 0 12
						fx 0 60 fy 0 60 fz 80 40
			}
		}
	)
	{on "explosion"
		{spawn "bloodsparks_big"}
		{if rand 0.2 	("imp" args "hand1" "hand1l")
		 else rand 0.2 	("imp" args "hand2" "hand1l")
		 else rand 0.2 	("imp" args "hand3" "hand1l")
		}
		{if rand 0.2 	("imp" args "hand1" "hand1r")
		 else rand 0.2 	("imp" args "hand2" "hand1r")
		 else rand 0.2 	("imp" args "hand3" "hand1r")
		}

		{if rand 0.3	("imp" args "leg1" "foot1l")}
		{if rand 0.3	("imp" args "leg1" "foot1r")}
		{if rand 0.3	("imp" args "head" "head")	}
		{delete}
	}
	(define "imp_small"
		{spawn %0 %1
			{impulse	up 0.1 0.1
						fx 0 7 fy 0 7 fz 0 7
			}
		}
	)
	{on "crush"
		{spawn "bloodsparks_big"}
		{if rand 0.2 	("imp_small" args "hand1" "hand1l")
		 else rand 0.2 	("imp_small" args "hand2" "hand1l")
		 else rand 0.2 	("imp_small" args "hand3" "hand1l")
		}
		{if rand 0.2 	("imp_small" args "hand1" "hand1r")
		 else rand 0.2 	("imp_small" args "hand2" "hand1r")
		 else rand 0.2 	("imp_small" args "hand3" "hand1r")
		}

		{if rand 0.3	("imp_small" args "leg1" "foot1l")}
		{if rand 0.3	("imp_small" args "leg1" "foot1r")}
		{if rand 0.3	("imp_small" args "head" "head")  }
		{delete}
	}
	
	{on "burn"
		{if not burned
;			{if not terrain "shallow water"
;				{fire radius 1 time 14 followowner}
				{set "burning" 1}
				{tex_morph "burned" 14}
				{call "add_burn_fx"}
				{view start "burn_fire"}
				{delay_effect 0.5 0.2 "burn_scream"}
				{delay 6 2 "burn_die"
					{set "burning" 0}
					{kill_flags reset}
					{if not dead
						{stat_notify die burned}
						{call "die"}
					}
					{view stop "burn_fire"}
					{if terrain "puddle"
						{call "stop_burn"}
					else
						{add_view "smoke_dead_small2" "burn_fire_b" 	"body"}
						{add_view "smoke_dead_small3" "burn_fire_hl"	"hand1l"}
						{add_view "smoke_dead_small3" "burn_fire_hr"	"hand1r"}
						{add_view "smoke_dead_small3" "burn_fire_fl"	"foot2l"}
						{add_view "smoke_dead_small3" "burn_fire_fr"	"foot2r"}
						{view start "burn_fire_b"}
						{view start "burn_fire_hl"}
						{view start "burn_fire_hr"}
						{view start "burn_fire_fl"}
						{view start "burn_fire_fr"}
						{delay 7.5 1.5	{view stop "burn_fire_b"}}
						{delay 3.5 2.0	{view stop "burn_fire_hl"}}
						{delay 3.8 1.5	{view stop "burn_fire_hr"}}
						{delay 4.3 1.5	{view stop "burn_fire_fl"}}
						{delay 4.5 1.5	{view stop "burn_fire_fr"}}
					}
				}
				{burn time 17} ; total burn time
;			}
		}
	}
	{on "add_burn_fx"
		{add_view "smoke_dead_small"  "burn_fire"	"body"}
		{add_view "smoke_dead_small1" "burn_fire"	"hand1l"}
		{add_view "smoke_dead_small1" "burn_fire"	"hand1r"}
		{add_view "smoke_dead_small1" "burn_fire"	"hand2l"}
		{add_view "smoke_dead_small1" "burn_fire"	"hand2r"}
		{add_view "smoke_dead_small1" "burn_fire"	"foot2l"}
		{add_view "smoke_dead_small1" "burn_fire"	"foot2r"}
	}
	{on "burn_scream"
		{if not dead
			{if not senseless
				{if not "quench"
					{start_sound "man_die"}
					{delay_effect 1.2 0.5 "burn_scream"}
				else
					{kill_delay "burn_die"}
					{view stop "burn_fire"}
					{set "quench" 0}
					{set "burning" 0}
				}
			}
		}
	}
	
	{on fire "hand_right"
		{view start "flashbarrel"}
;		{bone hide "faustrocket"}
	}
	{on "smoking"
;		{con "smoke start"}
		{view start "smoke"}
		{delay 0.3 0.1
			{view pause "smoke"}
;			{con "smoke end"}
		}
	}
	{on "take"
		{if name "pistol"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
		 else name "rifle"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
		 else name "smg"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
		 else name "mgun"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
		 else name "nothing"
		 	{view hide "flashbarrel"}
		}
	}

	(define "terrain_fx_human"
		{on terrain %0 enter
			{if not "swimming"
				{view start "on_%1"}
				{view start "on_%1_time_short"}
				{delay 0.1
					{view pause "on_%1_time_short"}
				}
			}
		}
		{on terrain %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_human" args "water" 			water)
	("terrain_fx_human" args "shallow water"	water)
	("terrain_fx_human" args "deep water"		water)
	("terrain_fx_human" args "mud" 				mud)
	("terrain_fx_human" args "puddle"			puddle)
	("terrain_fx_human" args "shallow puddle"	puddle)
	("terrain_fx_human" args "shallow swamp"	puddle)

	{on terrain "swamp" enter
		{delay 0							; without delay will crash in Die()
			{call "die_without_blood"}
			{view start "die_in_swamp"}
			{delay 10
				{view stop "die_in_swamp"}
				{delete}
			}
		}
	}

	{on "diving"
		{delay 0.3
			{spawn "spherewater_big"}
		}
	}
	{on swim on
		{set "swimming" 1}
		{view pause "on_water"}
		{view start "swim"}
		{view start "swim"}
		{call "stop_burn"}
		{kill_delay "after_swim"}
	}
	{on swim off
		{set "swimming" 0}
		{delay 1.5 "after_swim"
			{view pause "swim"}
		}
	}
	{on move on
		{if "swimming"
			{view start "swim_move"}
		}
		{if velocity 11
			{play_sound "move" 1}
		}
	}
	{on "stop_burn"
		{if burned
			{burn stop_retry}
			{set "quench" 1}
		}
	}
	{on move off
		{view pause "swim_move"}
		{stop_sound "move"}
	}
	{on "falldown"
		{if altitude 3
			{throw_off "fly" up 1 forward 0.01 die force}
		else altitude 1
			{throw_off "fly" up 1 forward 0.01 force}
		else       
			{throw_on_ground}
		}
	}
	{on board out
		{if effector "mtb_d3"
			{if name "emit1" "emit2" "emit3" "emit4"
				{delay 0.7
					{spawn "spherewater_big"}
				}
			}
		}
	}
}

{"wound_human"
	{on spawn
		{ani_play "flattern" loop}
		{set "dead" 0}
	}
	{on bullet_hit
		{call "hit"}
		{if rand 0.5
			{call "die"}
		}
	}
	{on "hit"
		{spawn "bloodsparks_small"}
		{if not "say"
			{start_sound "man_hit"}
			{set "say" 1}
			{delay 10 2
				{set "say" 0}
			}
		}
	}
	{on blast_hit
		{if min_energy 0.3
			{spawn "bloodsparks_big"}
			("imp" args "hand1" "skin02")
			("imp" args "hand2" "skin02")
			("imp" args "leg1" "skin02")
			("imp" args "head" "skin02")
			{delete}
		}
	}
	{on "die"
		{if not "dead"
			{set "dead" 1}
			{tags add "dead"}
			{ani_stop "flattern"}
		}
	}
}
