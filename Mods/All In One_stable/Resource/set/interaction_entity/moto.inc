{"moto"
	{blast_absorption 0.4}
	{on spawn
		{link_sound "flame" "fire.big"}

		{if not rain
			{add_view	"dustrun_small"			"on_ground"			"FXtrace2"}
			{add_view	"dustrun_small"			"on_ground"			"FXtrace3"}
			{add_view	"dustrun_small"			"on_grass"			"FXtrace2"}
			{add_view	"dustrun_small"			"on_grass"			"FXtrace3"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtrace2"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtrace3"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtrace2"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtrace3"}
		}
		{add_view	"drops_water"			"on_water"			"FXtrace1"}
;		{add_view	"drops_water"			"on_mud"			"FXtrace1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtrace1"}

		{add_view	"smoke_black"			"smoke4"			"basis"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
	}
	{on "update_obstacle"
		{if operatable
			{change_obstacle "operatable"}
		else
			{change_obstacle "empty"}
		}
	}
	{on "add_movement_sound"
		{link_sound "move"			"wheels.bmw_move"}
		{link_sound "move_end"		"wheels.move_end"}
		{link_sound "engine"		"engine.bmw"}
		{link_sound "engine_end"	"engine.moto_end"}
		{link_sound "exhaust"		"engine.bmw_up"}
	}

	{on bullet_hit
		{if volume "wheel"
		 else
			{if bullet "small bullet"
			else bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			else bullet "bullet"
				{if rand 0.2
					{component disable work repair}
					{if volume "explosive"	{call "burn"}}
				}
			else bullet "shell"
				{if bullet "fg"
					{bullet_detonate}
				}
				{call "explosion"}
			}
		}
	}
	{on "test_heavy_contact"
		{if min_speed 30
			{if effector "construction"
				{call "explosion"}
			 else effector "shed"
				{call "explosion"}
			}
		else min_speed 20
			{component disable work}
;		else min_speed 5
;			{component disable work}
		}
	}
	{on contact
		{if not impregnable
			{if effector_velocity 5
				{if effector "vehicle"
					{component disable work repair}
					{if volume "body"
						{set "crush" 1}
						{call "explosion"}
					}
				}
			else effector "concrete"
				{call "test_heavy_contact"}
			else effector "steel"
				{call "test_heavy_contact"}
			}
		}
	}
	{on break
		{if component "body"
			{spawn "tank_die_particle"}
			{crew_enable group "crew" 0}
			{view start "smoke3"}
    		{delay 10 {view stop "smoke3"}}
		else component "engine"
			{spawn "tank_die_particle"}
		}
	}
	{on repair
		{if component "body"
			{crew_enable group "crew" 1}
		}
	}
	{on blast_hit
		{if min_energy 0.8
			{impulse up 2 1 dir 2 1}
		 else min_energy 0.5
			{impulse up 1 1 dir 1 1}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.3
				{call "explosion"}
			}
		}
	}
;	{on "_burn"
;		{add_view "smoke_dead_norm2" "burn_fire" "basis"}
;		{view start "burn_fire"}
;	}
	{on "_burn" overload
		{add_view "smoke_dead_norm2" "burn_fire" "basis"}
;		{add_view	"smoke_black" "burn_fire" "FXfire1"}
		{play_sound "flame" 1}
		{view start "burn_fire"}
		{explosive 1}
		{delay 5 1
			{explosive 0}
			{view stop "burn_fire"}
			{stop_sound "flame"}
			{call "explosion"}
		}
		{burn time 7}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on "check_burn_emit"
		{call "burn_emit"}
	}

	{on "_explosion"
		{area disable}
		{if not "crush"
			{spawn "car_die" "Basis"}
			{spawn "tank_die_particle" "Basis"}
			{impulse up 4 2 dir 2 1}
		}
	}

	{on "spawn_shellhole"
		{spawn "shellhole_road_moto" "Basis"}
		{spawn "shellhole_dead_moto" "Basis"}
	}

	{on "slice_load"
		{if name "wheel"
			{with_effector
				{add_view "smoke_dead_wheel" "smoke" "basis"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_moto" "deathfx" "body"}
		{view start "deathfx"}

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{burn first_volume fx "smoke_dead_wheel" time 20 5}
				{add_view "smoke_dead_wheel" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		(define "tear_wheel"
			{if rand 0.2
				{components "%0" disable work repair}
				{tear "piece_medium_steel" bone "%0" id "wheel"
					{volumes disable bullet contact blast}	;prevent destroing at spawn moment
					{impulse up 6 4 dir 7 3}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)

		{volumes disable contact}
		{delay 14 {view stop "deathfx"}}

		("tear_wheel" args wheel1)
		("tear_wheel" args wheel2)
		("tear_wheel" args wheel3)

		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
	}
}
