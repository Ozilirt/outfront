{"tank"
;	{friction 1};
	{restitution 0.3}
	{on spawn
		{link_sound "flame"			"fire.big"}
		{link_sound "move"			"tracks.move00"}
		{link_sound "heavy_move"	"tracks.heavy_move"}

		{if not rain
			{add_view	"dustrun_big"			"on_ground"				"FXtraceR1"}
			{add_view	"dustrun_big"			"on_ground"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceL1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceR1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"			"FXfire1"}
    	}

		{add_view	"tank_grit_small"		"on_ground"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_ground"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceL2"}

		{add_view	"tank_grit_small"		"on_grass"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_grass"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceL2"}

		{add_view	"drops_water"			"on_water"				"FXtraceR1"}
		{add_view	"drops_water"			"on_water"				"FXtraceL1"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceR2"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceL2"}
		{add_view	"drops_water_moto"		"on_puddle"				"FXtraceR1"}
		{add_view	"drops_water_moto"		"on_puddle"				"FXtraceL1"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceR2"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceL2"}

;		{add_view	"flash_cannon_big"		"flashbarrel1"			"Foresight1"}
		{add_view	"powdersmoke_big"		"flashbarrel1s"			"Foresight1"}
;		{add_view	"powdersmoke_small2" 	"flashbarrel1s" 		"Foresight1"}
;		{add_view	"flash_gun_big"			"flashbarrel2"			"Foresight3"}

		{add_view	"smoke_black"			"smoke1"				"FXfire1"}
		{add_view	"smoke_black"			"smoke2"				"FXfire2"}
		{add_view	"smoke_black"			"smoke3"				"FXfire2"}
		{add_view	"smoke_black"			"smoke4"				"FXfire1"}
		{add_view	"exhaust_dark"			"exhaust"				"FXsmoke1"}
		{add_view	"exhaust_dark"			"exhaust"				"FXsmoke2"}
		{set "smoke3" 0}
		{set "smoke4" 0}

		{if operatable
			{ani_wind "open" begin}
		else
			{ani_wind "open" end}
		}
	}

	{on "add_movement_sound"
		{link_sound "engine"		"engine.tank"}
		{link_sound "engine_end"	"engine.tank_end"}
		{link_sound "exhaust"		"engine.tank_up"}

	}

	{on blast
		{if volume "track"
			{call "blast_track"}
		}
	}
	{on "blast_track"
		{if min_energy 0.5
			{component disable work}
		}
	}

	{on operatable on
		{ani_play "open" -1.0 resume}
	}
	{on operatable off
		{ani_play "open" +1.0 resume}
	}
	{on pierce
		{if volume "explosive"
			{call "explosion"}
		else not "no_burn_volumes"
			{if volume "body"
				{burn fx "smoke_dead_tank1" fake}
				{call "rand_burn"}
			else volume "track"
				{burn fx "smoke_dead_tank1" fake}
			}
		}
		{if volume "body"
			{if rand 0.1 {kill_crew "gunner"}}
			{if rand 0.1 {kill_crew "charger"}}
			{if rand 0.1 {kill_crew "commander"}}
			{if rand 0.1 {kill_crew "driver"}}
		}
	}
	{on "rand_burn"
		{if rand 0.2
			{delay 1
				{if not burned
					{call "_burn"}
				}
			}
		}
	}
	{on break
		{if component "body"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner"}}
				{if rand 0.5 {kill_crew "charger"}}
				{if rand 0.5 {kill_crew "commander"}}
				{if rand 0.5 {kill_crew "driver"}}
			}
			{spawn "tank_die_particle" "Body"}
;			{call "emit_crew"}
			{view start "smoke4"}
			{set "smoke4" 1}
			{call "check_burn_emit"}
    		{delay 30
    			{view stop "smoke4"}
				{set "smoke4" 0}
				{call "check_burn_emit"}
    		}
    	else component "engine"
			{spawn "tank_die_particle" "engine"}
			{view start "smoke1"}
			{set "smoke1" 1}
			{call "check_burn_emit"}
    		{delay 30
    			{view stop "smoke1"}
				{set "smoke1" 0}
				{call "check_burn_emit"}
    		}
		}
	}

	{on "_burn"
		{add_view		"smoke_dead_norm"	"burn_fire"		"FXfire1"}
		{view start "burn_fire"}
	}
	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{spawn "tank_die" "Basis"}
	}
	{on "spawn_shellhole"
		{spawn "crater_big_tank" "Basis" no_normal}
		{spawn "shellhole_dead_tank" "Basis"}
	}
	{on "cut_parts"
		{spawn "tank_die" "Basis"}
		{add_view "smoke_black_big" "deathfx" "basis"}
		{view start "deathfx"}
		(define "cut_part"
			{if rand 0.5
				{tear "piece_medium_steel" bone %0
					{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 20 5 "stop"}
				}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		{delay 25 5	{view stop "deathfx"}}
	}

	{on "check_burn_emit"
		{if not "burn_fire"
			{if not "smoke3"
				{if not "smoke4"
					{set "burning" 0}
				else
					{call "burn_emit"}
				}
			else
				{call "burn_emit"}
			}
		else
			{call "burn_emit"}
		}
	}
	{on "burn_emit"
		{if not "burning"
			{set "burning" 1}
            {reset_manual_control}
		}
	}
	{on fire "gun"
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{ani_play "fire"}
		{delay 0.8
			{view pause "flashbarrel1"}
		}
		{delay 0.2
			{view pause "flashbarrel1s"}
		}
	}
    {on "criticalhit" overload
    	{if component "body"
    		{if not hit_side front
    			{components "engine" disable work}
    		}
    	else component "turret"
			{components "gun" disable work}
    	}
    }
}

{"turret"
	{on spawn
		{call "update_turret"}
	}
	{on break
		{if component "turret"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner"}}
				{if rand 0.5 {kill_crew "charger"}}
				{if rand 0.5 {kill_crew "commander"}}
			}
			{call "update_turret"}
			{spawn "tank_die_particle" "Turret"}
			{spawn "circledust_norm" "Turret"}
;			{ani_play "open" -1.0 resume}
			{view start "smoke3"}
			{set "smoke3" 1}
			{call "check_burn_emit"}
    		{delay 10
    			{view stop "smoke3"}
				{set "smoke3" 0}
				{call "check_burn_emit"}
    		}
    	else component "body"
			{spawn "circledust_norm" "Turret"}
			{call "update_turret"}
		}
	}
	{on repair
		{if component "turret"
			{view stop "smoke3"}
			{call "update_turret"}
		else component "body"
			{view stop "smoke4"}
			{call "update_turret"}
		}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" disable work repair}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 20 5 "pause"}
				}
			}
		}
	}
	{on "slice_load"
		{if name "turret"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}

	{on "cut_parts"
		{if "turret_teared"
			{bone cut "turret"}
		else
		    {call "tear_turret"}
		}
	}
	{on "update_turret"
		{if work "turret"
			{if work "body"
				{ik_enable "turret" 1}
			 else 
				{ik_enable "turret" 0}
			}
		 else
			{ik_enable "turret" 0}
		}
	}
}

;{"medium tank turret"
;	{on bullet_hit
;		{if bullet "big shell fg"
;			{if rand 0.2
;				{call "tear_turret"}
;			}
;		}
;	}
;}

{"light tank turret"
	{on bullet_hit
		{if bullet "big shell fg"
			{if rand 0.8
				{call "tear_turret"}
			}
		}
	}
}

{"light_turret" ; turret for btr, car, ...
	{on bullet_hit
		{if volume "turret"
			{if bullet "shell"
				{call "tear_turret"}
			}
		}
	}
}

{"armored_car"
	{blast_absorption 1}
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on bullet_hit
 		{if bullet "big shell extra"
			{impulse up 6 2 dir 5 1}
		 else bullet "big shell"
			{impulse up 1.9 0.7 dir 1.7 0.8}
		 else bullet "shell"
		 	{ani_play "hit"}
		}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on blast_hit
		{if min_energy 8
			{impulse up 5 0.2 dir 3 0.1}
		 else min_energy 1
			{impulse up 0.5 0.2 dir 0.3 0.1}
		 else min_energy 0.4
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 1
				{call "explosion"}
			}
		}
	}
	{on "explosion"
		{impulse up 1.5 0.5 dir 0.4 0.2 } 
	}
}

{"light tank"
	{blast_absorption 1}
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on bullet_hit
 		{if bullet "big shell extra"
			{impulse up 7 1 dir 5 0.5}
		 else bullet "big shell"
			{impulse up 1.9 0.7 dir 1.7 0.8}
		 else bullet "shell"
		 	{ani_play "hit"}
		}
	}
	{on blast_hit
		{if min_energy  8
			{impulse up 7 1 dir 5 0.5}
		 else min_energy 1.5
			{impulse up 1.9 0.7 dir 1.7 0.8}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 1.5
				{call "explosion"}
			}
		}
	}
	{on "explosion"
		{impulse up 0.5}
	}
}

{"medium tank"
	{blast_absorption 2}
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	{on bullet_hit
 		{if bullet "big shell extra"
			{impulse up 5 dir 4}
		 else bullet "big shell"
			{impulse up 1.0 0.3 dir 1.0 0.3}
		 else bullet "shell"
		 	{ani_play "hit"}
		}
	}
	{on blast_hit
		{if min_energy 8
			{impulse up 5 dir 6}
		 else min_energy 4
			{impulse up 1.6 0.4 dir 1.5 0.5}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 7.9
				{call "explosion"}
			else min_energy 4
				{if rand 0.3
					{call "explosion"}
				else
					{components "body" disable work}
					{components "engine" disable work}
					{call "rand_burn"}
				}
			}
		}
	}
	{on "explosion"
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{set "sinking" 1}
		}
	}
}

{"heavy tank"
	{inflammation_time 30}
	{blast_absorption 3}
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_big" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	{on bullet_hit
 		{if bullet "big shell extra"
			{impulse up 4 1 dir 4}
		 	{ani_play "hit"}
		 else bullet "big shell"
			{impulse up 0.6 0.2 dir 0.3 0.05}
		 	{ani_play "hit"}
		 else bullet "shell"
		 	{ani_play "hit"}
		}
	}
	{on blast_hit
		{if min_energy 12
			{impulse up 3 1 dir 4}
		 else min_energy 10
			{impulse up 0.9 0.2 dir 0.6 0.2}
		 else min_energy 3
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 7.9
				{call "explosion"}
			}
		else volume "engine"
			{if min_energy 1.5
				{components "body" disable work}
				{components "engine" disable work}
			}
		}
	}
	{on "explosion"
		{impulse up 3 1 dir 0.6 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{set "sinking" 1}
		}
	}
}

{"self_propelled tank"
	{on "blast_track" overload
		{if min_energy 4
			{component disable work}
		}
	}
}

{"PZ-1B tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
}
{"t-26 tank"
	{on "add_movement_sound" overload
		{link_sound "engine"			"engine.t26"		}
		{link_sound "engine_end"		"engine.t26_end"	}
		{link_sound "exhaust"			"engine.t26_up"		}
		{link_sound "rotate_turret" 	"turret.lturret00"	}
	}
}
{"bt-7 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.bt_move"	}
		{link_sound "engine"			"engine.bt"			}
		{link_sound "engine_end"		"engine.bt_end"		}
		{link_sound "exhaust"			"engine.bt_up"		}
		{link_sound "rotate_turret" 	"turret.lturret00"	}
	}
}
{"bt-7a tank"
	{on "add_movement_sound" overload
		{link_sound "engine"			"engine.bt"			}
		{link_sound "engine_end"		"engine.bt_end"		}
		{link_sound "exhaust"			"engine.bt_up"		}
		{link_sound "rotate_turret" 	"turret.lturret00"	}
	}
}

(define "kv_sound"
	{on "add_movement_sound" overload
		{link_sound "move00"			"tracks.kv_move"	}
		{link_sound "rotate_turret" 	"turret.hturret1"	}
		{link_sound "engine"			"engine.kv"			}
		{link_sound "engine_end"		"engine.kv_end"		}
		{link_sound "exhaust"			"engine.kv_up"		}
	}
)
{"KV-1 tank"
	("kv_sound")
}
{"KV-2 tank"
	("kv_sound")
}
{"KV-85 tank"
	("kv_sound")
}
{"IS-2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.is_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.is"		}
		{link_sound "engine_end"		"engine.is_end"	}
		{link_sound "exhaust"			"engine.is_up"		}
	}
}
{"T-34-76-41 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t34_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t34"		}
		{link_sound "engine_end"		"engine.t34_end"	}
		{link_sound "exhaust"			"engine.t34_up"		}
	}
}
{"T-34-85 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t3485_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t3485"		}
		{link_sound "engine_end"		"engine.t3485_end"	}
		{link_sound "exhaust"			"engine.t3485_up"	}
	}
}
{"PZ-5 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.tank_move"	}
		{link_sound "engine"			"engine.heavy"		}
		{link_sound "engine_end"		"engine.heavy_end"	}
		{link_sound "rotate_turret" 	"turret.hturret1"	}
		{link_sound "exhaust"			"engine.heavy_up"	}
	}
}
{"Ferdinand tank"
	{on "add_movement_sound" overload
;		{link_sound "move"				"tracks.heavy_move"	}
		{link_sound "engine"			"engine.heavy"		}
		{link_sound "engine_end"		"engine.heavy_end"	}
		{link_sound "rotate_turret" 	"turret.hturret1"	}
		{link_sound "exhaust"			"engine.heavy_up"	}
	}
}
{"cromwell tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"tracks.crmwll_move"}
		{link_sound "engine"			"engine.crmwll"		}
		{link_sound "engine_end"		"engine.crmwll_end"	}
		{link_sound "exhaust"			"engine.crmwll_up"	}
		{link_sound "rotate_turret" 	"turret.hturret1"	}
	}
}
{"M4A2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m4a2_move"  }
		{link_sound "engine"			"engine.m4a2"		}
		{link_sound "engine_end"		"engine.m4a2_end"	}
		{link_sound "exhaust"			"engine.m4a2_up"	}
		{link_sound "rotate_turret" 	"turret.hturret1"	}
	}
}
{"M4A3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"tracks.m4_move"}
		{link_sound "engine"				"engine.m4"		}
		{link_sound "engine_end"			"engine.m4_end"	}
		{link_sound "exhaust"				"engine.m4_up"	}
		{link_sound "rotate_turret"     "turret.hturret1"   }
	}
}
{"M7priest tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"tracks.m7_move"}
		{link_sound "engine"				"engine.m7"		}
		{link_sound "engine_end"			"engine.m7_end"	}
		{link_sound "exhaust"				"engine.m7_up"	}
		{link_sound "rotate_turret" 	   "turret.hturret1"}
	}
}
{"jugdpanther tank"
	{on "add_movement_sound" overload
		{link_sound "move"				 "tracks.jdp_move"  }
		{link_sound "engine"				"engine.jdp"	}
		{link_sound "engine_end"		"engine.jdp_end"	}
		{link_sound "exhaust"			"engine.jdp_up" 	}
		{link_sound "rotate_turret" 	"turret.hturret2"	}
	}
}
(define "PZ6_sound"
	{on "add_movement_sound" overload
;		{link_sound "move"				"tracks.t34_move"	}
		{link_sound "engine"			"engine.pz6"		}
		{link_sound "engine_end"		"engine.pz6_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz6_up"	}
	}
)
{"PZ-6 tank"
	("PZ6_sound")
}
{"PZ-6b tank"
	("PZ6_sound")
}
{"PZ-6e tank"
	("PZ6_sound")
}
{"sdkfz-223 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.move"			}
		{link_sound "move_end"		"wheels.move_end"		}
		{link_sound "engine"		"engine.car"			}
		{link_sound "engine_end"	"engine.car_end"		}
		{link_sound "exhaust"		"engine.car_up"			}
	}
}
{"BA-20M tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot"	}
		{link_sound "engine"			"engine.ba20"		}
		{link_sound "engine_end"		"engine.ba20_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.ba20_up"	}
	}
}
{"pz-2f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz2_move"	}
		{link_sound "engine"			"engine.pz2"		}
		{link_sound "engine_end"		"engine.pz2_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz2_up" 	}
	}
}
{"pz-3g tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
(define "pz4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz4_move"	}
		{link_sound "engine"			"engine.pz4"		}
		{link_sound "engine_end"		"engine.pz4_end"	}
		{link_sound "rotate_turret" 	"turret.hturret2"	}
		{link_sound "exhaust"			"engine.pz4_up"	  	}
	}
)
{"pz-4d tank"  
	("pz4_sound")
}
{"pz-4g tank"
	("pz4_sound")
}
(define "sdkfz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot"	}
		{link_sound "engine"			"engine.sd232"		}
		{link_sound "engine_end"		"engine.sd232_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd232_up"	}
	}
)
{"sdkfz232 tank"
	("sdkfz_sound")
}
{"sdkfz-223 tank"
	("sdkfz_sound")
}
{"sdkfz234 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.sd234_move"	}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
(define "hanomag_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.sd250_move"	}
		{link_sound "engine"			"engine.sd250"		}
		{link_sound "engine_end"		"engine.sd250_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd250_up"	}
	}
)
{"sdkfz250_3 tank"
	("hanomag_sound")
}
{"SdKfz251_1 tank"
	("hanomag_sound")
}
{"m3a1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
;		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
