{"car"
	{blast_absorption 1}
	{on spawn
		{link_sound "flame" "fire.big"}

		{if not rain
			{add_view	"dustrun_small"			"on_grass"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"			"FXtraceL1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceR1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceL1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"		"FXfire1"}
		}
		{add_view	"drops_water"			"on_water"			"FXtraceR1"}
		{add_view	"drops_water"			"on_water"			"FXtraceL1"}
;		{add_view	"drops_water"			"on_mud"			"FXtraceR1"}
;		{add_view	"drops_water"			"on_mud"			"FXtraceL1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtraceR1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtraceL1"}

		{add_view	"smoke_black"			"smoke1"			"FXfire1"}
		{add_view	"smoke_black"			"smoke2"			"engine"}
		{add_view	"steam"					"steam"				"FXsteam"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
	}

	{on "add_movement_sound"
		{link_sound "move"			"wheels.move"}
		{link_sound "move_end"		"wheels.move_end"}
		{link_sound "engine"		"engine.car"}
		{link_sound "engine_end"	"engine.car_end"}
		{link_sound "exhaust"		"engine.car_up"}
	}

	{on bullet_hit
		{if volume "wheel"
		 else volume "glass"
		 	{call "break_glass"}
		 else
		 	{if volume "cabin"
			 	{call "break_glass"}
		 	}
			{if bullet "small bullet"
;				{con "small bullet hit car"}
			else bullet "bullet"
				{if volume "engine"
;					{con "bullet in engine"}
					{if rand 0.2 {component disable work}}
				else volume "cabin"
					{if rand 0.2 {component disable work}}
				}
			else bullet "shell"
				{if volume "cabin"
;					{call "tear" }
;					{set "cabine_teared" 1}
				else volume "engine"
					{call "tear" }
					{set "engine_teared" 1}
				}
				{impulse dir 1 0.3}
				{if bullet "fg"
					{bullet_detonate}
				}
			}
		}
	}
	{on pierce
		{if volume "fuel"
			{volumes "fuel" disable bullet contact blast}
			{spawn "tank_die_particle"}
			{call "burn"}
		}
	}
	{on "break_glass"
		{volumes "glass" disable bullet contact}
	 	{spawn "glass_hit2" "glass" x}
	 	{delay 0.1
;	 		{con "cut glass"}
		 	{bone cut "glass"}
	 	}
	}
	{on contact
		{if effector_velocity 5
			{if effector "tank"
				{call "crush"}
			else effector "railway"
				{call "crush"}
			}
		else effector_velocity 3
			{if effector "big part"
				{component disable work}
			}
		}
	}
	{on break
		{if component "cabin"
			{spawn "car_die_particle"}
			{volumes "glass" disable bullet contact}
			{crew_enable group "crew" 0}
			{view start "smoke3"}
    		{delay 10 {view stop "smoke3"}}
    	else component "body"
			{spawn "car_die_particle"}
		else component "engine"
			{spawn "car_die_particle"}
			{view start "smoke2"}
			{delay 40 {view stop "smoke2"}}
			{view start "steam"}
			{delay 2  {view stop "steam"}}
		}
	}
	{on repair
		{if component "cabin"
			{crew_enable group "crew" 1}
			{view stop "smoke2"}
		}
	}
	{on blast_hit overload
		{if min_energy 0.8
			{impulse up 1.5 0.5 dir 1.5 0.5}
		 else min_energy 0.5
			{impulse up 0.8 0.3 dir 0.8 0.3}
		}
		{if min_energy 0.3
			{call "explosion"}
		}
	}
	{on "_burn"
		{add_view "smoke_dead_norm2" "burn_fire" "basis"}
		{view start "burn_fire"}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on "_explosion"
		{change_obstacle "broken"}
		{add_view "smoke_dead_norm2" "deathfx" "basis"}
		{if not "crush"
			{spawn "tank_die" "Basis"}
			{spawn "tank_die_particle"}
			{impulse up 2.5 1.5 dir 2 1}
		}
	}
	{on "spawn_shellhole"
		{spawn "crater_big" "Basis" no_normal}
		{spawn "shellhole_dead_car" "Basis"}
	}
	{on "tear"
		{spawn	"spheredust_small"}
		{component disable work repair}
		{if volume "bodyback"
			{volume disable visible bullet contact}
		}
		{tear "piece_big_steel" bone from_volume
			{impulse up 2 1 dir 2 1}
;			{burn first_volume fx "smoke_black" time 10 5}
			{add_view "smoke_black" "smoke" "basis"}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
	}
	{on "slice_load"
		{if name "car_part"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "basis"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
;				{burn first_volume fx "smoke_dead_wheel" time 20 5}
				{add_view "smoke_dead_wheel" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		;cut teared bones after SetSkeleton
		{if "cabine_teared"
			{bone cut "cabin"}
		}
		{if "engine_teared"
			{bone cut "engine"}
		}
		{delay 14 5 {view stop "deathfx"}}
	}
	{on "break_light"
		{if component "engine"
			{bone cut "headlightL"}
			{bone cut "headlightR"}
			{bone cut "fxlight"}
		}
	}
	{on "repair_light"
		{if component "engine"}
	}
	{on "lights_on"
		{view start "light"}
		{view show "light"}
	}
	{on "lights_off"
		{view stop "light"}
		{view hide "light"}
	}
	{on "update_lights"
		{if not sunlight
			{if operatable
				{call "lights_on"}
			else
				{call "lights_off"}
			}
		}
	}
	{on "crush"
    	{component disable work repair}
    	{if volume "body"
    		{set "crush" 1}
    		{call "explosion"}
    	}
	}
	{on "update_obstacle"
		{if operatable
			{change_obstacle "operatable"}
		else
			{change_obstacle "empty"}
		}
	}
	{on operatable on
		{call "update_lights"}
	}
	{on operatable off
		{call "update_lights"}
	}
}

{"wheeled vehicle"
	{on bullet_hit
		{if volume "wheel"
			{if bullet "shell fg" {bullet_detonate}}
		}
	}
	{on pierce
		{if volume "wheel"
			{if bullet "shell ap"
				{call "tear_wheel"}
			else bullet "zenite"
				{component disable work}
			else bullet "bullet"
				{call "pierce_bullet"}
			}
		}
	}
	{on "pierce_bullet"
		{if rand 0.2 {component disable work}}
	}
	{on blast
		{if volume "wheel"
			{if min_energy 0.3
				{call "tear_wheel"}
			}
		}
	}

;	{on "check_work_mover" overload
;		{if "wheel_teared"
;			{chassis_work 0}
;		else
;			{if not work "track"
;				{chassis_work 0}
;			else work "wheel"
;				{chassis_work 1}
;				{movement_limit fast}
;			else
;				{chassis_work 1}
;				{movement_limit slow}
;			}
;		}
;	}

	{on "tear_wheel"
		{set "wheel_teared" 1}
		{spawn	"spheredust_small"}
		{component disable work repair}
;		{con "effect tear wheel"}
		{tear "piece_medium_steel" bone from_volume id "wheel"
			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{impulse up 6 4 dir 7 3}
;			{burn first_volume fx "smoke_dead_wheel" time 10 5}
			{add_view "smoke_dead_wheel" "smoke" "basis"}
			{fire radius 0.5 time 12 followowner}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
		{impulse up 0.3}
	}
;	{on "slice_load"
;		{if name "wheel"
;			{with_effector
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;			}
;		}
;	}
	{on break
		{if component "wheel"
			{if not linked
		 		{if bullet "bullet"	{if not velocity 0.5 {impulse up 0.05}}}
			}
		}
	}
	{on "_explosion"
		(define "rand_tear_wheel"
			{if rand 0.5
;				{con "rnd tear wheel"}
				{components %0 disable work repair}
				{tear "piece_medium_steel" bone %0 id "wheel"
					{volumes disable bullet contact blast}	;prevent destroing at spawn moment
					{impulse up 7 4 dir 7 4}
;					{burn first_volume fx "smoke_dead_wheel" time 10 5}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)
;		("rand_tear_wheel" args "wheelleft1")
;		("rand_tear_wheel" args "wheelleft2")
;		("rand_tear_wheel" args "wheelright1")
;		("rand_tear_wheel" args "wheelright2")
	}
}

{"wheeled vehicle armored_car"
	{on "pierce_bullet" overload}
}

{"tent vehicle"
	{on blast
		{if volume "bodyback"
			{if min_energy 0.5
				{call "tear"}
			}
		}
	}
	{on bullet_hit overload
		{if volume "bodyback"
			{if bullet "bullet"
				{component disable work}
				{spawn "spheredust_small_short"}
			else bullet "shell ap"
				{component disable work}
				{spawn "spheredust_small_short"}
			else bullet "shell fg"
				{spawn "ex_air_big"}
				{bullet_detonate}
			}
		else
			{inherited}
		}
	}
}

{"katusha car"
	{on fire "gun"
		{spawn "startsmoke_big" inv_normal}
		{spawn "startdust_big" "FXdust"}
	}
	{on bullet_hit
		{if bullet "shell"
			{call "explosion"}
		}
	}
	{on "_explosion"
		{blastwave c4 15 r0 20 r1 30}
		{spawn "train_die" "basis"}
	}
	{on "spawn_shellhole"
		{spawn "crater_extra_big" "basis"}
		{spawn "shellhole_big_dead" "basis"}
	}
}

{"fuel_tank"
	{on pierce
		{if not "explosed"
			{if volume "bodyback"
				{if bullet "bullet"
					{burn fx "drops_water_small_short" fake}
				}
			}
		}
	}
	{on "_explosion"
		{spawn "aero_die"}
	}
}

{"dead_vehicle"
	{on blast
		{if volume "body"
			{if min_energy 0.7
				{call "explosion"}
			}
		}
	}
	{on "explosion"
		{if not "explosed"
			{set "explosed" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion"
		{start_sound "death.tank"}
		{delay_ex 0
			{set_skeleton "_x" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_wheel" "smoke" "basis"}
		{view start "smoke"}
		{delay 20 10
			{view stop "smoke"}
		}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{add_view "smoke_dead_wheel" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}
}

{"sdkfz7 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.sd250_move"	}
		{link_sound "engine"			"engine.sd250"		}
		{link_sound "engine_end"		"engine.sd250_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd250_up"	}
	}
}

{"zis-5 car"
	{on "add_movement_sound" overload
		{link_sound "engine"			"engine.zis"		}
		{link_sound "engine_end"		"engine.zis_end"	}
		{link_sound "exhaust"			"engine.zis_up"		}
	}
}
{"dodgewc56 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.dodge_move"	}
;		{link_sound "move_end"			"wheels.d3_move_end"}
		{link_sound "engine"			"engine.dodge" 		}
		{link_sound "engine_end"		"engine.dodge_end" 	}
		{link_sound "exhaust"			"engine.dodge_up"	}
	}
}
(define "kubel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.kubel_move"	}
		{link_sound "engine"			"engine.kubel" 		}
		{link_sound "engine_end"		"engine.kubel_end" 	}
		{link_sound "exhaust"			"engine.kubel_up"	}
	}
)
{"kubel car"
	("kubel_sound")
}
{"willysmb car"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.MB_move"	}
		{link_sound "engine"			"engine.MB" 		}
		{link_sound "engine_end"		"engine.MB_end" 	}
		{link_sound "exhaust"			"engine.MB_up"	}
	}
}
(define "horch_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.horch_move"	}
		{link_sound "engine"			"engine.horch" 		}
		{link_sound "engine_end"		"engine.horch_end" 	}
		{link_sound "exhaust"			"engine.horch_up"	}
	}
)
{"horch car"
	("horch_sound")
}
{"gaz-m1 car"
	("horch_sound")
}
{"gmc car"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.gmc_move"	}
		{link_sound "move_end"		"wheels.gmc_end"	}
		{link_sound "engine"			"engine.gmc" 		}
		{link_sound "engine_end"		"engine.gmc_end" 	}
		{link_sound "exhaust"			"engine.gmc_up"		}
	}
}
(define "opel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.Opel_move"	}
		{link_sound "move_end"		"wheels.Opel_move_end"	}
		{link_sound "engine"			"engine.Opel"   	}
		{link_sound "engine_end"		"engine.Opel_end"	}
		{link_sound "exhaust"			"engine.Opel_up"	}
	}
)
{"Blitz-3.6"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.blitz_move"	}
		{link_sound "engine"			"engine.Blitz"   	}
		{link_sound "engine_end"		"engine.Blitz_end"	}
		{link_sound "exhaust"			"engine.Blitz_up"	}
	}
}
{"Blitz-Fuel"
	("opel_sound")
}
{"Blitz-Medic"
	("opel_sound")
}
{"sdkfz10-5 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.sd10_move"	}
		{link_sound "engine"			"engine.sd10"		}
		{link_sound "engine_end"		"engine.sd10_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd10_up"	}
	}
}
