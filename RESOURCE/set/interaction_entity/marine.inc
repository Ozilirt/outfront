{"marine"
	{on spawn
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_engine1"}
		{add_view	"smoke_black"		"on_move"	"FX_smoke"             }
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back2"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front1"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front2"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_engine_small"	"on_move"	"FX_bulb_small_engine1"}
		{add_view	"wash_engine_norm"	"on_move"	"FX_bulb_norm_engine1"}
		{view start "on_stead"}
		{ani_play "drift" loop}
	}
	{on move on
		{view start "on_move"}
		{view pause "on_stead"}
	}
	{on move off
		{view start "on_stead"}
		{view pause "on_move"}
	}
	{on pierce
		{component disable work}
		{if volume "float"
			{call "break_float"}
		}
	}
	{on blast
		{if min_energy 2
			{component disable work}
			{if volume "float"
				{call "break_float"}
			}
		}
	}
	{on "sinking"
		{delay 3
			{set "sinking" 1}
			{for_each_link
				{set "sinking" 1}
			}
		}
	}
	{on "break_float"
		{call "sinking"}
		{volume disable float bullet blast}
		{impulse up 0.2}
	}
	{on grounded on
		{ani_stop "drift"}
	}
	{on grounded off
		{ani_play "drift" loop}
	}
}

{"platforma"
	{on break
		{if component "body1"
			{spawn "TANK_DIE" "fxdead_1a"}
		}
		{if component "body2"
			{spawn "TANK_DIE" "fxdead_2a"}
		}
		{if component "ballast_l1"
			{spawn "ex_water_extra_big_test" "fxdead_l1a"}
			{spawn "platform_par1" "fxdead_l1a"}
		}
		{if component "ballast_r1"
			{spawn "ex_water_extra_big_test" "fxdead_r1a"}
			{spawn "platform_par1" "fxdead_r1a"}
		}
		{if component "ballast_l2"
			{spawn "ex_water_extra_big_test" "fxdead_l2a"}
			{spawn "platform_par1" "fxdead_l2a"}
		}
		{if component "ballast_r2"
			{spawn "ex_water_extra_big_test" "fxdead_r2a"}
			{spawn "platform_par1" "fxdead_r2a"}
		}
	}
	{on pierce overload
	}
	{on blast overload
		{if min_energy 10
			{component disable work repair}
			{if volume "float"
				{call "break_float"}
			}
		}
	}
}

{"torpedo_boat marine"
	{on spawn
		{if "torpedo1"
			{bone cut "torpedo1"}
		}
		{if "torpedo2"
			{bone cut "torpedo2"}
		}
	}
	{on fire "gun"
		{if not "torpedo1"
			{set "torpedo1" 1}
			{ani_play "torpedo1" callback}
		else not "torpedo2"
			{set "torpedo2" 1}
			{ani_play "torpedo2" callback}
		}
	}
	{on animation_end "torpedo1"
		{spawn "torpedo" "torpedo1" x no_normal no_position}
		{bone cut "torpedo1"}
	}
	{on animation_end "torpedo2"
		{spawn "torpedo" "torpedo2" x no_normal no_position}
		{bone cut "torpedo2"}
	}
	{on operatable on
		{delay 0.1
			{play_sound "engine_operatable" 1}
		}
	}
	{on operatable off
		{stop_sound "engine_operatable"}
	}
	(define "torpedo_detonate"
		{delay 0.1
;			{spawn "tank_die" "fx_exp_torpedo%0"}
			{blastwave c4 8 r0 3 r1 6 bone "fx_exp_torpedo%0"}
			{bone cut "torpedo%0"}
			{set "torpedo%0" 1}
			{call "explosion_sequence"}
		}
	)
	(define "pierce_torpedo_detonate"
		{if volume "torpedo_det%0"
			("torpedo_detonate" args %0)
		}
	)
	(define "blast_torpedo_detonate"
		{if volume "torpedo%0"
			("torpedo_detonate" args %0)
		}
	)
	{on pierce
		("pierce_torpedo_detonate" args 1)
		("pierce_torpedo_detonate" args 2)
		{if volume "body"
			{if bullet "shell big"
				("torpedo_detonate" args 1)
				("torpedo_detonate" args 2)
			}
		}
	}
	{on blast
		{if min_energy 2
			("torpedo_detonate" args 1)
			("torpedo_detonate" args 2)
		}
	}
	{on "_explosion"
		{call "break"}
	}
	{on "break"
		{stop_sound "engine_operatable"}
		{call "light_break"}
	}
	{on "light_break"}	; handled in extender
	{on "light_on"}		; handled in extender
	{on "light_off"}	; handled in extender
}

{"air-bag"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.lct_move"		}
		{link_sound "engine"			"engine.airbag"			}
		{link_sound "engine_end"		"engine.airbag_end"		}
		{link_sound "exhaust"			"engine.airbag_up"		}
	}
	{on break
		{chassis_work 0}
	}
}
{"fishboat"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.lct_move"}
		{link_sound "move_end"			"wheels.lct_move_end"}
		{link_sound "engine"			"engine.d3"		}
		{link_sound "engine_end"		"engine.lct_end"	}
		{link_sound "exhaust"			"engine.lct_up"	}
	}
	{on break
		{chassis_work 0}
	}
}
{"mtb_d3"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.d3_move"}
		{link_sound "move_end"			"wheels.d3_move_end"}
		{link_sound "engine"			"engine.d3"		}
		{link_sound "engine_end"		"engine.d3_end"	}
		{link_sound "exhaust"			"engine.d3_up"	}
	}
	(define "tear_marine_part"
		{components "%0" disable work repair}
		{tear "piece_large_steel" bone "%0"
;			{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
		}
	)
	{on "cut_parts"
		{bone cut "torpedo1"}
		{bone cut "torpedo2"}
		{bone cut "cabin"}
	}

	(define "sink_volume"
		{delay %1 1
			{volumes %0 disable float bullet blast}
			{impulse up 0.2}
		}
	)
	(define "sink_sequence"
		{call "sinking"}
		{impulse up 0.2}
		("sink_volume" args %0 %1)
		("sink_volume" args %2 %3)
		("sink_volume" args %4 %5)
		("sink_volume" args %6 %7)
		{delay 3
			{call "light_flash"}
			{delay 0.7 0.1
				{kill_delay "light_flash"}
				{call "light_off"}
			}
		}
	)
	{on "light_flash"
		{delay 0 "light_flash"
			{if rand 0.3
				{if "light_on"
					{call "light_off"}
					{set "light_on" 0}
				else
					{call "light_on"}
					{set "light_on" 1}
				}
			}
			{call "light_flash"}
		}
	}

	{on break
		{if component "body_front"
			("sink_sequence" args "ballast1" 2 "ballast3" 4 "ballast2" 7 "ballast4" 8)
		}
		{if component "body"
			("sink_sequence" args "ballast3" 2 "ballast1" 4 "ballast4" 7 "ballast2" 8)
		}
		{if component "body_rear"
			("torpedo_detonate" args torpedo1)
			("torpedo_detonate" args torpedo2)
			("sink_sequence" args "ballast2" 2 "ballast4" 4 "ballast3" 7 "ballast1" 8)
		}
	}
	{on "explosion_sequence"
		{if not "explode"
			("sink_sequence" args "ballast2" 2 "ballast4" 4 "ballast3" 7 "ballast1" 8)
			{set "explode" 1}
			{spawn "marine_die" "fx_exp1"}
			{delay 0.3 0.1
				{spawn "marine_die" "fx_exp2"}
				{blastwave c4 8 r0 5 r1 6 bone "fx_exp2"}
				{components "body_rear" disable work repair}
				{delay 0.3 0.1
					{volumes "float" disable float bullet blast}
					{components "body" disable work repair}
					("tear_marine_part" args cabin)
					{spawn "marine_die" "fx_exp3"}
					{blastwave c4 8 r0 5 r1 6 bone "fx_exp3"}
					{call "explosion"}
					{delay 0.3 0.1
						{spawn "marine_die" "fx_exp4"}
						{blastwave c4 8 r0 5 r1 6 bone "fx_exp4"}
						{components "body_front" disable work repair}
					}
				}
			}
		}
	}
}

{"torpedo"
	{on spawn
		{spawn "spherewater_big"}
		{spawn "spherewater_big2" local_offset -40 0 0}
		{spawn "spherewater_big2" local_offset -80 0 0}
		{spawn "spherewater_big2" local_offset -120 0 0}
		{add_view "wash_torpedo_small" "tail" "tail"}
		{view start "tail"}
	}
	{on "explosion"
		{blastwave c4 15 r0 8 r1 15}
		{spawn "shockwave"}
		{spawn "ex_bomb_big" offset 0 0 20}
		{spawn "spherewater_big"}
		{delete}
	}
	{on ground_hit
		{call "explosion"}
;		{spawn "crater_big" no_normal}
	}
	{on contact
		{call "explosion"}
	}
	{on bullet_hit
		{bullet_detonate}
	}
	{on blast
		{if min_energy 0.5
			{delay 0.2
				{call "explosion"}
			}
		}
	}
}
