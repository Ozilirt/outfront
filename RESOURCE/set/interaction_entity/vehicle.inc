{"explosion_throw_crew vehicle"
	{on "_explosion"
		{crew_throw_off "fly" up 4 1 dir 5 1 turn 0 180 forward 2 rnd_die 0.5}
	}
}

{"turret_rotator"
	{on spawn
		{set "rotate_turret" 0}
	}
	{on ik begin "turret"
		{kill_delay "rotate_turret"}
		{if not "rotate_turret"
			{play_sound "rotate_turret" 1}
			{set "rotate_turret" 1}
		}
	}
	{on ik end "turret"
		{delay 0.5 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
		}
	}
}

{"vehicle"
	{inflammation_time 20}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel2"	"Foresight3"}

		{add_view	"stop_signal"	"stop_signal"	"FXstop1"}
		{add_view	"stop_signal"	"stop_signal"	"FXstop2"}

		{add_view 	"headlight"		"light"			"headlightL"}
		{add_view 	"headlight"		"light"			"headlightR"}
		{add_view 	"light_vehicle"	"light"			"fxlight"}

		{view hide "stop_signal"}
		{view hide "light"}

		{call "add_movement_sound"}
		{call "update_moveable"}
		{call "update_lights"}
		{call "update_obstacle"}
		{set "burn_fire" 0}
	}
	
	{on "stop_on"
		{ani_stop "start"}
		{ani_play "stop"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on "exhaust_on"
		{play_sound "exhaust" 1}
		{view start "exhaust"}
	}
	{on "exhaust_off"
		{stop_sound "exhaust"}
		{view pause "exhaust"}
	}
	
	{on turn on
		{call "stop_on"}
		{call "exhaust_on"}
	}
	{on turn off
		{call "exhaust_off"}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop"}
		{ani_play "start"}
	}
	{on move off
		{stop_sound "move"}
		{play_sound "move_end"}
		{call "exhaust_off"}
	}
	{on accelerate on
		{call "exhaust_on"}
	}
	{on accelerate off
		{call "exhaust_off"}
	}
	{on brake on
		{call "stop_on"}
	}
	{on engine on
		{kill_delay "engine_stopped"}
		{kill_delay "engine_steam_stopped"}
		{stop_sound "engine_end"}
		{play_sound "engine" 1}
		{view start "engine_steam"}
	}
	{on engine off
		{delay 2 "engine_stopped"
			{stop_sound "engine"}
			{play_sound "engine_end"}
		}
		{delay 12 "engine_steam_stopped"
			{view pause "engine_steam"}
		}
	}
	
	
	{on break
		{if component "body"
			{stat_notify break}
		else component "turret"
			{stat_notify break}
		}
		{call "update_moveable"}
		{call "break_light"}
	}
	{on repair
		{call "update_moveable"}
		{call "repair_light"}
	}
	
	{on fire "mgun"
		{view start "flashbarrel2"}
	}
	{on contact
		{if effector_velocity 3
			{if effector "air_part"
				{component disable work}
			else effector "piece_big_stone"
				{component disable work}
			else effector "airborne"
				{call "contact_airborne"}
			}
		}
	}
	{on "contact_airborne"
		{if not "contact_airborne_first"
			{set "contact_airborne_first" 1}
			{component disable work}
			{delay 0.1
				{set "contact_airborne_second" 1}
				{delay 0.1
					{set "contact_airborne_first" 0}
					{set "contact_airborne_second" 0}
				}
			}
		else "contact_airborne_second"
			{call "explosion"}
		}
	}

	{on "update_moveable"
		{if work "body"
			{view stop "smoke4"}
		else
			{view start "smoke4"}
		}
		{if work "engine"
			{call "check_work_mover"}
		else
			{chassis_work 0}
		}
	}
	{on "check_work_mover"
		{if work "mover"
			{chassis_work 1}
		else
			{chassis_work 0}
		}
	}

	{on "explosion"
		{if not "explosed"
			{set "explosed" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion"
		{stat_notify break}
		{call "break_all"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{view stop "fire1"}
		{view stop "fire2"}
		{tags add "destroyed"}

		{if "crush"
			{start_sound "death_veh"}
		else
			{blastwave c4 4 r0 3 r1 6}
			{start_sound "death.tank"}
		}
		{if not terrain "bridge"
			{call "spawn_shellhole"}
		}

		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}

	{on operatable on
		{call "update_obstacle"}
	}
	{on operatable off
		{call "update_obstacle"}
	}

	{on "break_all"
		{kill_crew}
		{drop_orders}
		{components disable work repair}
		{able select 0}
		{clear_inventory}
	}
	
	{on "_burn"
		{add_view	"smoke_black" "burn_fire" "FXfire1"}
		{stat_notify die burned}
		{play_sound "flame" 1}
		{view start "burn_fire"}
		{set "burn_fire" 1}
		{call "check_burn_emit"}
;		{explosive 1}
		{delay 5 1
			{components "body" disable work}
		}
		{delay 8 1
			{components "engine" disable work}
		}
		{delay 15 5
;			{explosive 0}
			{view stop "burn_fire"}
			{stop_sound "flame"}
			{set "burn_fire" 0}
			{call "check_burn_emit"}
			{if multiplayer
				{call "explosion"}
			else rand 0.8
				{call "explosion"}
			}
		}
		{burn time 17}
	}

	{on "burn_volume"
		{if not burned
			{if volume "engine"
				{call "_burn"}
			else
				{burn volume fx "smoke_dead_small2" time 5 1 fake even_law}
			}
		}
	}

	(define "terrain_fx"
		{on terrain %0 enter
			{view start "on_%1"}
			{view start "on_%1_time_short"}
			{delay 0.1
				{view pause "on_%1_time_short"}
			}
		}
		{on terrain %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx" args "ground"			ground)
	("terrain_fx" args "sand"			sand)
	("terrain_fx" args "grass" 			grass)
	("terrain_fx" args "water" 			water)
	("terrain_fx" args "shallow water"	water)
	("terrain_fx" args "country road"	country_road)
	("terrain_fx" args "mud"			mud)
	("terrain_fx" args "puddle"			puddle)
	("terrain_fx" args "shallow puddle"	puddle)
}

{"emit_on_sink vehicle"
	{on spawn
		{call "check_sinking"}
	}
	(define "sink_terrain"
		{on terrain "%0" enter
			{reset_manual_control}
			{set "sinking" 1}
		}
		{on terrain "%0" leave
			{reset_manual_control}
;			{set "sinking" 0} ;do not use this because of leaving terrain on stop
		}
	)
;	("sink_terrain" args water)
	("sink_terrain" args swamp)
	{on "check_sinking"
		{call "check_water_level"}
		{if "sinking"
			{reset_manual_control}
		}
		{delay 0.5 "check_sinking"
			{call "check_sinking"}
		}
	}
	{on "check_water_level"
		{if water_level 1.2
			{set "sinking" 1}
		}
	}
	{on "_explosion"
		{kill_delay "check_sinking"}
	}
}

{"with_gun vehicle"
	{on spawn
		{call "update_gun"}
	}
	{on break
		{if component "gun"
			{call "update_gun"}
		}
	}
	{on repair
		{if component "gun"
			{call "update_gun"}
		}
	}
	{on "update_gun"
		{if work "gun"
			{weapon_work "gun" 1}
		 else
			{weapon_work "gun" 0}
		}
	}
}
