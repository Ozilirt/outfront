{"railway_part"
	{on "switch"
		{rail_switch -1}
	}
	{on "switchr"
		{rail_switch 0}
	}
	{on "switchl"
		{rail_switch 1}
	}
	{on "break"
		{tags add "broken"}
		{rail_break}
	}
	{on blast
		{if min_energy 10
			{call "break"}
		}
	}
	{on "switch_left"
		{volumes "body" disable touch}
		{volumes "body1" enable touch}
	}
	{on "switch_right"
		{volumes "body" enable touch}
		{volumes "body1" disable touch}
	}
}
{"steam_locomotive"
	{on spawn
		{call "update_fx"}
		{link_sound "accelerating"	"wheels.locomotive_acc"}
		{link_sound "moving"		"wheels.locomotive_move"}
		{link_sound "braking"		"wheels.locomotive_brake"}
	}
	{on "update_fx"
		{add_view	"smoke_train_grey"		"warm_smoke"				"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"warm_steam1"				"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"warm_steam2"				"fxsmoke2"}
		{add_view	"smoke_train_steam_norm"	"warm_steam3"				"fxsmoke3"}
		{add_view	"smoke_train_steam_norm"	"warm_steam4"				"fxsmoke4"}
		{add_view	"smoke_train_grey_slow"		"accelerate_smoke"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"accelerate_steam"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"accelerate_steam"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"accelerate_steam"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"accelerate_steam"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow2"	"move_smoke_slow"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"move_steam_slow"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"move_steam_slow"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"move_steam_slow"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"move_steam_slow"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow2"	"move_smoke_fast"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"move_steam_fast"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"move_steam_fast"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"move_steam_fast"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"move_steam_fast"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow"		"brake_smoke"				"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"brake_steam"				"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"brake_steam"				"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"brake_steam"				"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"brake_steam"				"fxsmoke4"}
		{add_view	"smoke_train_steam_norm"	"engine_steam"				"fx_smoke_engine1"}
		{add_view	"smoke_train_steam_norm"	"engine_steam"				"fx_smoke_engine2"}

		{add_view "aero_die_fire"		"fire_big"	"fx_fire_big_engine"}
		{add_view "smoke_dead_norm2"	"fire1"		"fx_fire_small_engine1"}
		{add_view "smoke_dead_norm2"	"fire2"		"fx_fire_small_engine2"}
		{add_view "smoke_dead_norm2"	"fire3"		"fx_fire_small_engine3"}
		{add_view "smoke_dead_norm2"	"fire4"		"fx_fire_small_engine4"}
		{add_view "smoke_dead_norm2"	"fire5"		"fx_fire_small_engine5"}
		{add_view "smoke_dead_small3"	"smoke"		"fx_smoke_engine1"}
		{add_view "smoke_dead_small3"	"smoke"		"fx_smoke_engine2"}

		{add_view "steam"				"steam"		"fx_steam_small_engine1"}
		{add_view "steam"				"steam"		"fx_steam_small_engine2"}
		{add_view "steam"				"steam"		"fx_steam_small_engine3"}
		{add_view "steam"				"steam"		"fx_steam_small_engine4"}
		{add_view "steam"				"steam"		"fx_steam_small_engine5"}
		{add_view "steam"				"steam"		"fx_steam_small_engine6"}
		{add_view "steam"				"steam"		"fx_steam_small_engine7"}

		{add_view "smoke_train_steam_norm" "steam_big"	"fx_steam_big_engine1"}
		{add_view "smoke_train_steam_norm" "steam_big"	"fx_steam_big_engine2"}
	}
	{on "warm"
		{if name "on"
			{delay 0.1
				{view start	"warm_smoke"}
			}
			{call "warming"}
		else name "off"
			{kill_delay "warming"}
			{delay 1
				{view pause "warm_smoke"}
			}
		}
	}
	{on "warming"
		{delay 5 2 "warming"
			{if not velocity 0 ; == 0 km/h
				(define "rand_start"
					{if rand 0.25
									{view start %0} {delay 0.7 {view pause %0}}
					else rand 0.5
						{delay 0.3	{view start %0} {delay 0.7 {view pause %0}}}
					else rand 0.75
						{delay 0.6	{view start %0} {delay 0.7 {view pause %0}}}
					else
						{delay 0.9	{view start %0} {delay 0.7 {view pause %0}}}
					}
				)
				("rand_start" args "warm_steam1")
				("rand_start" args "warm_steam2")
				("rand_start" args "warm_steam3")
				("rand_start" args "warm_steam4")
				{call "warming"}
			}
		}
	}
	{on accelerate on
		{play_sound "accelerating"}
		{delay 1
			{view pause "warm_smoke"}
		}
		{view start "accelerate_smoke"}
		{view start "accelerate_steam"}
		{delay 2
			{view pause "accelerate_steam"}
		}
	}
	{on accelerate off
		{stop_sound "accelerating"}
		{delay 2
			{view pause "accelerate_smoke"}
		}
		{if not simulating
			{if velocity 0 ; > 0 km/h
				{play_sound "moving" 1}
				{if velocity 8 ;fast
					{view start "move_smoke_fast"}
				else
					{view start "move_smoke_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on "moving"
		{if velocity 8
			{delay 15 2 "moving"
				{view start "move_steam_fast"}
				{delay 0.7
					{view pause "move_steam_fast"}
				}
				{call "moving"}
			}
		else
			{delay 8 2 "moving"
				{view start "move_steam_slow"}
				{delay 0.5
					{view pause "move_steam_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on brake on
		{stop_sound "moving"}
		{play_sound "braking"}
		{view pause "move_smoke_fast"}
		{view pause "move_smoke_slow"}
		{kill_delay "moving"}
		{view start "brake_smoke"}
		{view start "brake_steam"}
		{delay 2
			{view pause "brake_steam"}
		}
	}
	{on brake off
		{stop_sound "braking"}
		{view pause "brake_smoke"}
	}
	{on move off
		{stop_sound "moving"}
		{play_sound "braking"}
	}
	{on "slice_load"
		{if name "hatch"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "_explosion"
		{delay 1
			{stop_sound "accelerating"}
			{stop_sound "moving"}
			{stop_sound "braking"}
		}
	}
	{on "cut_parts"
		{call "update_fx"}

		{tear "piece_big_steel" bone "hatch" id "hatch"
			{impulse forward 10 3 no_position cx 5 2 cy 5 2 cz 5 2}
			{add_view "smoke_black" "smoke" "root"}
			{view start "smoke"}
			{delay_effect 20 5 "pause"}
		}

		(define "rand_fire"
			{if rand 0.7
				{delay 0.3 0.2
					{view start "fire%0"}
				}
				{delay 40 10
					{view stop "fire%0"}
				}
			}
		)
		("rand_fire" args 1)
		("rand_fire" args 2)
		("rand_fire" args 3)
		("rand_fire" args 4)
		("rand_fire" args 5)
		{view start "fire_big"}
		{view start "smoke"}
		{view start "steam"}
		{view start "steam_big"}
		{delay 3
			{view stop "steam_big"}
		}
		{delay 10
			{view stop "steam"}
		}
		{delay 40 10
			{view stop "smoke"}
		}
	}    
	{on break
		{if component "engine"
			{set "crush" 1}
			{call "explosion"}
		}
	}
}
{"shield_locomotive"
	{on spawn
		{call "update_fx"}
		{link_sound "accelerating"	"wheels.locomotive_acc"}
		{link_sound "moving"		"wheels.locomotive_move"}
		{link_sound "braking"		"wheels.locomotive_brake"}
	}
	{on "update_fx"
		{add_view	"smoke_train_grey"		"warm_smoke"				"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"warm_steam1"				"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"warm_steam2"				"fxsmoke2"}
		{add_view	"smoke_train_steam_norm"	"warm_steam3"				"fxsmoke3"}
		{add_view	"smoke_train_steam_norm"	"warm_steam4"				"fxsmoke4"}
		{add_view	"smoke_train_grey_slow"		"accelerate_smoke"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"accelerate_steam"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"accelerate_steam"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"accelerate_steam"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"accelerate_steam"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow2"	"move_smoke_slow"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"move_steam_slow"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"move_steam_slow"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"move_steam_slow"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"move_steam_slow"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow2"	"move_smoke_fast"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"move_steam_fast"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"move_steam_fast"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"move_steam_fast"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"move_steam_fast"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow"		"brake_smoke"				"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"brake_steam"				"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"brake_steam"				"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"brake_steam"				"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"brake_steam"				"fxsmoke4"}
		{add_view	"smoke_train_steam_norm"	"engine_steam"				"fx_smoke_engine1"}
		{add_view	"smoke_train_steam_norm"	"engine_steam"				"fx_smoke_engine2"}

		{add_view "aero_die_fire"		"fire_big"	"fx_fire_big_engine"}
		{add_view "smoke_dead_norm2"	"fire1"		"fx_fire_small_engine1"}
		{add_view "smoke_dead_norm2"	"fire2"		"fx_fire_small_engine2"}
		{add_view "smoke_dead_norm2"	"fire3"		"fx_fire_small_engine3"}
		{add_view "smoke_dead_norm2"	"fire4"		"fx_fire_small_engine4"}
		{add_view "smoke_dead_norm2"	"fire5"		"fx_fire_small_engine5"}
		{add_view "smoke_dead_small3"	"smoke"		"fx_smoke_engine1"}
		{add_view "smoke_dead_small3"	"smoke"		"fx_smoke_engine2"}

		{add_view "steam"				"steam"		"fx_steam_small_engine1"}
		{add_view "steam"				"steam"		"fx_steam_small_engine2"}
		{add_view "steam"				"steam"		"fx_steam_small_engine3"}
		{add_view "steam"				"steam"		"fx_steam_small_engine4"}
		{add_view "steam"				"steam"		"fx_steam_small_engine5"}
		{add_view "steam"				"steam"		"fx_steam_small_engine6"}
		{add_view "steam"				"steam"		"fx_steam_small_engine7"}

		{add_view "smoke_train_steam_norm" "steam_big"	"fx_steam_big_engine1"}
		{add_view "smoke_train_steam_norm" "steam_big"	"fx_steam_big_engine2"}
	}
	{on "warm"
		{if name "on"
			{delay 0.1
				{view start	"warm_smoke"}
			}
			{call "warming"}
		else name "off"
			{kill_delay "warming"}
			{delay 1
				{view pause "warm_smoke"}
			}
		}
	}
	{on "warming"
		{delay 5 2 "warming"
			{if not velocity 0 ; == 0 km/h
				(define "rand_start"
					{if rand 0.25
									{view start %0} {delay 0.7 {view pause %0}}
					else rand 0.5
						{delay 0.3	{view start %0} {delay 0.7 {view pause %0}}}
					else rand 0.75
						{delay 0.6	{view start %0} {delay 0.7 {view pause %0}}}
					else
						{delay 0.9	{view start %0} {delay 0.7 {view pause %0}}}
					}
				)
				("rand_start" args "warm_steam1")
				("rand_start" args "warm_steam2")
				("rand_start" args "warm_steam3")
				("rand_start" args "warm_steam4")
				{call "warming"}
			}
		}
	}
	{on accelerate on
		{play_sound "accelerating"}
		{delay 1
			{view pause "warm_smoke"}
		}
		{view start "accelerate_smoke"}
		{view start "accelerate_steam"}
		{delay 2
			{view pause "accelerate_steam"}
		}
	}
	{on accelerate off
		{stop_sound "accelerating"}
		{delay 2
			{view pause "accelerate_smoke"}
		}
		{if not simulating
			{if velocity 0 ; > 0 km/h
				{play_sound "moving" 1}
				{if velocity 8 ;fast
					{view start "move_smoke_fast"}
				else
					{view start "move_smoke_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on "moving"
		{if velocity 8
			{delay 15 2 "moving"
				{view start "move_steam_fast"}
				{delay 0.7
					{view pause "move_steam_fast"}
				}
				{call "moving"}
			}
		else
			{delay 8 2 "moving"
				{view start "move_steam_slow"}
				{delay 0.5
					{view pause "move_steam_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on brake on
		{stop_sound "moving"}
		{play_sound "braking"}
		{view pause "move_smoke_fast"}
		{view pause "move_smoke_slow"}
		{kill_delay "moving"}
		{view start "brake_smoke"}
		{view start "brake_steam"}
		{delay 2
			{view pause "brake_steam"}
		}
	}
	{on brake off
		{stop_sound "braking"}
		{view pause "brake_smoke"}
	}
	{on move off
		{stop_sound "moving"}
		{play_sound "braking"}
	}
	{on "slice_load"
		{if name "hatch"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "_explosion"
		{delay 1
			{stop_sound "accelerating"}
			{stop_sound "moving"}
			{stop_sound "braking"}
		}
	}
	{on "cut_parts"
		{call "update_fx"}

		{tear "piece_big_steel" bone "hatch" id "hatch"
			{impulse forward 10 3 no_position cx 5 2 cy 5 2 cz 5 2}
			{add_view "smoke_black" "smoke" "root"}
			{view start "smoke"}
			{delay_effect 20 5 "pause"}
		}

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{add_view "smoke_dead_wheel" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")

		(define "rand_fire"
			{if rand 0.7
				{delay 0.3 0.2
					{view start "fire%0"}
				}
				{delay 40 10
					{view stop "fire%0"}
				}
			}
		)
		("rand_fire" args 1)
		("rand_fire" args 2)
		("rand_fire" args 3)
		("rand_fire" args 4)
		("rand_fire" args 5)
		{view start "fire_big"}
		{view start "smoke"}
		{view start "steam"}
		{view start "steam_big"}
		{delay 3
			{view stop "steam_big"}
		}
		{delay 10
			{view stop "steam"}
		}
		{delay 40 10
			{view stop "smoke"}
		}
	}    
	{on break
		{if component "engine"
			{set "crush" 1}
			{call "explosion"}
		}
	}
}

{"train_part"
	{on blast
		{if min_energy 1.5
			{component disable work}
		else min_energy 3.0
			{components disable work}
		}
	}
	{on "_explosion"
		{impulse up 2 1 dir 2 1}
		{chassis_work 0}
	}
	{on pierce
		{if volume "wheel"
			{if bullet "shell"
				{component disable work}
			}
		}
	}
}

{"cistern"
	{on pierce
		{if bullet "shell"
			{if volume "fuel"
				{bullet_detonate}
				{call "explosion"}
			}
		}
	}
	{on blast
		{if volume "fuel"
			{if min_energy 0.5
				{call "explosion"}
			}
		}
	}
	{on contact
		{if volume "fuel"
			{if effector "vehicle"
				{call "explosion"}
			}
		}
	}
	{on "cut_parts"
		{blastwave c4 15 r0 8 r1 12}

		{spawn "aero_die" "fx_exp3"}
		{delay 0.15 0.05 {spawn "aero_die" "fx_exp3a"}}
		{delay 0.15 0.05 {spawn "aero_die" "fx_exp3b"}}
		{spawn "aero_die_particle" "fx_exp4a"}
		{spawn "aero_die_particle" "fx_exp4d"}

		{add_view "smoke_black_big" "deathfx" "basis"}
		{view start "deathfx"}
		{delay 40 5	{view stop "deathfx"}}

		(define "fire_start"
			{add_view "smoke_dead_wheel" "fire%0" "fx_fire%0"}
			{view start "fire%0"}
			{delay 30 5
				{view stop "fire%0"}
			}
		)
		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)
		("fire_start" args 4)
		("fire_start" args 5)
		("fire_start" args 6)

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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

{"tradevan_explosive"
	{on pierce
		{if bullet "shell"
			{if volume "inventory"
				{bullet_detonate}
				{call "explosion"}
			}
		}
	}
	{on blast
		{if volume "inventory"
			{if min_energy 0.5
				{call "explosion"}
			}
		}
	}
	{on contact
		{if volume "inventory"
			{if effector "airborne"
				{call "explosion"}
			}
		}
	}
	{on "cut_parts"
		{blastwave c4 15 r0 20 r1 30}

		{spawn "train_die" "basis"}
		{spawn "crater_extra_big" "basis"}
		{spawn "shellhole_big_dead" "basis"}

		{add_view "smoke_black_big" "deathfx" "basis"}
		{view start "deathfx"}
		{delay 40 5	{view stop "deathfx"}}

		(define "fire_start"
			{add_view "smoke_dead_wheel" "fire%0" "fx_fire%0"}
			{view start "fire%0"}
			{delay 30 5
				{view stop "fire%0"}
			}
		)
		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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
		("cut_part" args "part7")
		("cut_part" args "part8")
	}
}


{"platform"
	{on blast
		{if volume "body"
			{if min_energy 2
				{call "explosion"}
			}
		}
	}
	{on pierce
		{if bullet "shell"
			{if volume "body"
;				{bullet_detonate}
			}
		}
	}
	{on "cut_parts"
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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

{"platform_can"
	{on break
		{if component "body"
			{spawn "sandbags_crush" "fx_shield1"}
			{spawn "sandbags_crush" "fx_shield2"}
			{spawn "sandbags_crush" "fx_shield3"}
			{spawn "sandbags_crush" "fx_shield4"}
		}
	}
}

{"crane_m"
	{on spawn
		{add_view	"smoke_train_grey_slow" "smoke" "fxsmoke1"}
		{add_view	"exhaust_dark" "work_smoke" "fxsmoke1"}
		{link_sound "rotate_turret" "turret.mortar"}
	}
	{on ik begin "turret"
		{view start "smoke"}
		{delay 1
			{view pause "smoke"}
		}
		{if not "started"
			{if name "forward"
				{ani_play "hook_swing" -1 loop callback}
			else
				{ani_play "hook_swing" loop callback}
			}
			{set "started" 1}
		}
	}
	{on ik end "turret"
		{set "started" 0}
	}
	{on animation_end "hook_swing"
		{if not "started"
			{ani_stop "hook_swing"}
		}
	}
	{on operatable on
		{delay 0.1
			{view start "work_smoke"}
		}
	}
	{on operatable off
		{view pause "work_smoke"}
	}
}

{"carriage"
	{on break
		{if volume "body"
			{spawn "tank_die_particle"}
		}
	}
	{on "cut_parts"
		("fire_start" args 1)
		("fire_start" args 1a)
		{spawn "aero_die" "fx_exp3"}
		{spawn "aero_die" "fx_exp4"}

		(define "cut_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{add_view "smoke_dead_wheel" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part_big1")
		("cut_part" args "part_big2")
		("cut_part" args "part_big3")
		("cut_part" args "part_big4")
		("cut_part" args "part_big5")
		("cut_part" args "part_big6")
	}
}
{"platform2"
	{on blast
		{if volume "body"
			{if min_energy 2
				{call "explosion"}
			}
		}
	}
	{on pierce
		{if bullet "shell"
			{if volume "body"
				{bullet_detonate}
			}
		}
	}
	{on "cut_parts"
		("fire_start" args 1)
		("fire_start" args 1a)
		{spawn "aero_die" "fx_exp3"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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
{"tradevan"
	{on spawn
		{ani_play "doorright" 1}
		{ani_play "doorleft" 1}
	}
	{on "cut_parts"
		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)
		{spawn "wood_hit_big" "fx_wood1"}
		{spawn "wood_hit_big" "fx_wood2"}
		{spawn "hay_hit_big" "fx_haulm1"}
	}
}
