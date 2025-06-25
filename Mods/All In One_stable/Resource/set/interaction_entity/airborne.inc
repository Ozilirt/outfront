{"airborne"
	{friction 0.2}
	{restitution 0.3}
	{on spawn
		{link_sound "fall"				"airborne.fw_deep"			}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke1"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke2"	}
	}
	{on "add_movement_sound"
		{link_sound "fly"			"airborne.fw_move"			}
		{link_sound "engine_start"		"airborne.fw_start"			}
		{link_sound "engine_work"		"airborne.fw_work"			}
		{link_sound "engine_stop"		"airborne.fw_stop"			}
	}
	{on "takeoff"
		{if not dead
			{ani_play "wheels" 0.2}
			{play_sound "fly" 1}
			{set "on_air" 1}
		}
	}
	{on "landing"
		{ani_play "wheels" -0.2}
		{stop_sound "fly"}
		{set "on_air" 0}
	}
	{on engine on overload
		{if not "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
			{view start "engine_exhaust"}
			{delay 1
				{view pause "engine_exhaust"}
			}
		}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on engine off overload
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	{on "update_moveable" overload
		{if not "on_air"
			{inherited}
		}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
		}
	}
	{on pierce
		{if bullet "shell"
;			{call "explosion"}
		else bullet "zenite"
			{if rand 0.3
				{call "pierce_zenite"}
			}
		}
	}
	{on "pierce_zenite"
		{if work
			{component disable work}
			{spawn "aero_die_particle"}
			{if volume "engine"
				{burn fx "smoke_aero_big" fake}
			else volume "body"
				{burn fx "smoke_aero_big" fake}
			}
		}
		{if "on_air"
			{if volume "body"
				{impulse up 0.3 com}
				{call "fall"}
			}
		else
			{if rand 0.05
				{call "explosion"}
			}
		}
	}
	{on "fall"
		{if not "fall"
			{set "fall" 1}
			{explosive 1}
			{play_sound "fall"}
			{call "fall_fx"}
		}
	}
	{on "fall_fx"
		{delay 2
			{add_view "smoke_aero_dead_big" "fire" "body"}
			{view start "fire"}
			{delay 10
				{view stop "fire"}
			}
			{burn volume "body" fx "smoke_aero_big" time 10 fake}
			{burn volume "engine" fx "smoke_aero_big" time 10 fake}
			{delay 10.1
				{burn volume "body" fx "smoke_black" time 40 10 fake}
			}
		}
	}
	{on ground_hit
		{if volume "body"
			{call "explosion"}
		else
			{if volume "part"
				{if min_speed 1
					{call "tear_part"}
   	 			}
			}
		}
	}
	{on blast
		{if min_energy 2
			{if volume "body"
				{impulse up 1 0.5 dir 0.3 0.2}
				{call "explosion"}
			}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "collide"}
		else effector "construction"
			{call "collide"}
		else effector "tree"
			{call "collide"}
		else effector "fence"
			{if volume "part"
				{call "tear_part"}
			}
		}
	}
	{on "collide"
		{if volume "body"
			{call "explosion"}
		else volume "part"
			{call "tear_part"}
		}
	}
	{on "tear_part"
		{spawn "spheredust_big_short"}
		{component disable work repair}
		{chassis_work 0}
		{tear "piece_big_airborne" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
		{impulse up 0.1 com}
		{tags add "broken"}
	}
	{on "die"
		{chassis_work 0}
		{drop_orders}
		{components disable work repair}
		{clear_inventory}
		{call "engine_stop"}
		{stop_sound "fall"}
		{stop_sound "fly"}
		{stop_sound "engine_start"}
		{stop_sound "engine_stop"}
		{stop_sound "engine_work"}
		{explosive 0}
		{burn stop}
		{bone hide "engine_work"}
	}
	{on "_explosion" overload
		{kill_crew}
		{able select 0}
		{call "die"}
		{add_view "aero_die" "fire" "body"}
		{add_view "aero_die_fire" "fire" "body"}
		{view start "fire"}
		{spawn "aero_die_particle"}
		{start_sound "death.tank"}

		{impulse up 0.1 com}
		{delay 0.1
			(define "cut_part"
				{if rand %1
					{tear "piece_big_airborne" bone %0
						{impulse up 2 1 dir 2 1}
					}
				}
			)
			("cut_part" args "wingr1"		0.5)
			("cut_part" args "wingl1"		0.5)
			("cut_part" args "wingr2"		0.5)
			("cut_part" args "wingl2"		0.5)
			("cut_part" args "body_back"	0.5)
			("cut_part" args "propeller"	1.0)
		}
		{blastwave c4 7 r0 5 r1 8}
		{tags add "broken"}
	}
	{on "spawn_bomb"
		{spawn "air_bomb_small"}
	}
	{on "kick"
		{impulse up 0.1 com}
	}
}

{"airborne no_explosion"
	{on contact
		{components "wingleft" disable work repair}
		{components "wingright" disable work repair}
	}
	{on ground_hit
		{call "die"}
		{impulse up 0.1 com}
		{volumes "propeller" disable contact_ground}
	}
	{on "_explosion" overload
		{call "die"}
		{impulse up 0.1 com}
		("cut_part" args "wingr2"		0.5)
		("cut_part" args "wingl2"		0.5)
	}
	{on "fall_fx" overload
	}
}

{"air_part"
	{on spawn
		{add_view "smoke_black" "smoke" "root"}
		{view start "smoke"}
		{delay 180 30
			{view stop "smoke"}
		}
	}
	{on ground_hit
		{if min_speed 5
			{spawn "spheredust_big_short"}
		}
	}
}

{"air_part wing"
	{on ground_hit
		{if min_speed 5
			{call "tear_part"}
		}
	}
	{on "tear_part"
		{tear "piece_big_airborne" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
	}
}

{"airborne c-47"
	{friction 0.02}
	{on "tear_part" overload
		{spawn "spheredust_big_short"}
		{component disable work repair}
		{if volume "wing"
			{tear "piece_big_airborne_wing" bone from_volume
				{impulse up 2 1 dir 2 1}
			}
		else
			{tear "piece_big_airborne" bone from_volume
				{impulse up 2 1 dir 2 1}
			}
		}
		{impulse up 0.1 com}
	}
}

{"airborne P-51Mustang"
	{on "add_movement_sound" overload
		{link_sound "fly"				"airborne.p51_move"}
		{link_sound "engine_start"		"airborne.p51_start"}
		{link_sound "engine_work"		"airborne.p51_work"}
		{link_sound "engine_stop"		"airborne.fw_stop"}
	}
}
{"airborne burning"
	{on spawn
		{add_view "smoke_aero_dead_big"	"fire" "fx_fire1"}

		{add_view "smoke_aero_big"	"fire" "fx_fire1"}
		{add_view "smoke_train_grey_slow"	"fire" "fx_fire2"}
		{add_view "smoke_aero_big"	"fire" "fx_fire3"}
		{add_view "smoke_dead_big"	"fire" "fx_fire4"}
		{add_view "smoke_train_grey_slow2"	"fire" "fx_fire5"}
		{view start "fire"}
	}
	{on "stop_burn"
		{view stop "fire"}
	}
}
{"airborne i-16"
	{on "takeoff"
		{if not dead
			{bone hide "retract_wheelR"}
			{bone hide "retract_wheelL"}
			{play_sound "fly" 1}
			{set "on_air" 1}
		}
	}
	{on "landing"
		{bone show "retract_wheelR"}
		{bone show "retract_wheelL"}
		{stop_sound "fly"}
		{set "on_air" 0}
	}
}