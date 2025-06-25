
{"tank"
	{on "tank_kill"
				{components "body" disable work}
					(mod "mp"
						{if rand 0.20
							{call "_burn"}
							{delay 4 1
								{start_sound "small_explosion.break"}
							}
							{delay 5 1
								{call "explosion"}
							}
						}
					)
	}
	{on "btr_kill"
		{components "body" disable work}
				(mod "mp"
						{if rand 0.45
							{call "_burn"}
							{delay 4 1
								{start_sound "small_explosion.break"}
							}
							{delay 5 1
								{call "explosion"}
							}
						}
				)
	}
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
		{add_view	"powdersmoke_big"		"flashbarrel1s"				"Foresight1"}
		{add_view	"smoke_dead_tank2"		"smoke1"				"FXfire1"}
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

	{on operatable on
		{ani_play "open" -1.0 resume}
	}
	{on operatable off
		{ani_play "open" +1.0 resume}
	}
	{on "rand_burn"
		{if rand 0.002
			{if not burned
				{burn time 180}
				{delay 1
					{call "_burn"}
				}
			}
		}
	}
	{on break
		{if component "body"
			{spawn "tank_die_particle" "Body"}
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
    		{delay 300
    			{view stop "smoke1"}
				{set "smoke1" 0}
				{call "check_burn_emit"}
    		}
		}
	}

	{on "_burn"
		{add_view		"smoke_dead_norm"	"burn_fire"		"FXfire1"}
		{add_view		"smoke_dead_norm"	"burn_fire"		"Basis"}
		{add_view		"smoke_dead_tank2"	"burn_fire"		"Basis"}
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
        {on fire "gun2"
        {spawn "tank_canon_fire" "Foresight2" x}
        {ani_play "fire"}
        }
        {on fire "mgun2"
	{spawn "flash_gun_big" "Foresight2" x}
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

{"m4calliope"; must be placed beforethe props "turret"
	{on blast
		{if volume "gun"
			{if min_energy 2
				{call "tear_gun"}
			}
		}
	}
	{on bullet_hit
		{if bullet "flame"
              		{fire radius 1.5 time 20 heating 20 effector followowner}
 		}
		{if volume "gun"
			{if bullet "big shell"
				{if rand 0.5
					{call "tear_gun"}
				}
			}
		}
	}
	{on "tear_turret"
		{if "roof_broken"
			{bone cut "gun"}
		else
			{call "tear_gun"}
		}
	}
	{on "tear_gun"
		{if not "roof_broken"
			{set "roof_broken" 1}
			{components "gun" disable work repair}
			{delay_ex 0
				(define "teargun"
					{tear "piece_large_steel" bone "%gun"
						{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						{add_view "smoke_black" "smoke" "basis"}
						{view start "smoke"}
						{delay_effect 20 5 "pause"}
					}
				)
				("teargun" gun(gun1))
				("teargun" gun(gun2))
				("teargun" gun(gun3))
				("teargun" gun(gun4))
				("teargun" gun(gun5))
			}
		}
	}
}

{"turret"
	{on spawn
		{call "update_turret"}
	}
	{on break
		{if component "turret"
			{call "update_turret"}
			{spawn "tank_die_particle" "Turret"}
			{spawn "circledust_norm" "Turret"}
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
{"kusty_na_tanke"
	{on break
		(define "effekt_listiev"
			{if component "crown%0"
				{spawn "tree_hit_big"}
			}
		)
		("effekt_listiev" args 1)
		("effekt_listiev" args 2)
		("effekt_listiev" args 3)
		("effekt_listiev" args 4)
		("effekt_listiev" args 5)
	}
	{on blast
		(define "kust_na_tanke"
			{if volume "crown%0"
				{if min_energy 2.5
					{component disable work repair}
					{tear "piece_big_wood" bone "ambush0%0" id "crown%0"
					{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						{delay 10
							{delete}
						}
					}
				else min_energy 0.1
					{component disable work}
				}
			}
		)
		("kust_na_tanke" args 1)
		("kust_na_tanke" args 2)
		("kust_na_tanke" args 3)
		("kust_na_tanke" args 4)
		("kust_na_tanke" args 5)
	}
	{on "cut_parts"
		(define "cut_kust"
			{component disable work repair}
			{tear "piece_big_wood" bone "ambush0%0" id "crown%0"
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{burn first_volume fx "smoke_dead_wheel" time 20 5}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
				{delay 10
					{delete}
				}
			}
		)
		("cut_kust" args 1)
		("cut_kust" args 2)
		("cut_kust" args 3)
		("cut_kust" args 4)
		("cut_kust" args 5)
	}
	{on "_burn"
		{burn first_volume fx "smoke_black" time 10 5}
		;{fire radius 1.2 time 10 heating 0.1 effector}
		{delay 9
			{component disable work}
		}
	}
}

{"shields_na_tanke"
	{on pierce
		(define "hit_shield"
			{if volume "shield_%0"
				{if bullet "rpg shell"
					{if work "shield_%0"
						{burn fx "smoke_grey" fake}
						{if rand 0.8
							{bullet_detonate}
						else
							{bullet_detonate}
							{component disable work}
						}
					}
                                else bullet "bomb big shell"
					{component disable work}
                                else bullet "extra big shell"
					{component disable work}
				else bullet "big shell"
					{component disable work}
				else bullet "big shell ap"
					{if rand 0.70
						{component disable work}
					}
				else bullet "small shell ap"
					{if rand 0.20
						{component disable work}
					}
				else bullet "shell ap"
					{if rand 0.50
						{component disable work}
					}
				else bullet "zenite"
					{if rand 0.10
						{component disable work}
					}
				else bullet "ap"
					{if rand 0.05
						{component disable work}
					}
				}
			}
		)
		("hit_shield" args 1)
		("hit_shield" args 2)
		("hit_shield" args 3)
		("hit_shield" args 4)
		("hit_shield" args 5)
		("hit_shield" args 6)
		("hit_shield" args 7)
		("hit_shield" args 8)
		("hit_shield" args 9)
		("hit_shield" args left)
		("hit_shield" args right)
	}
	{on blast
		(define "blast_shield"
			{if volume "shield_%0"
				{if min_energy 9
						{component disable work repair}
						{tear "piece_medium_steel" bone "shield_%0" ;id "shield_%0"
							{impulse up 4 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						}
				else min_energy 7.5
					{if rand 0.50
						{component disable work repair}
						{tear "piece_medium_steel" bone "shield_%0" ;id "shield_%0"
							{impulse up 4 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						}
					else rand 0.99
						{component disable work}
					}
				else min_energy 6.0
					{if rand 0.30
						{component disable work repair}
						{tear "piece_medium_steel" bone "shield_%0" ;id "shield_%0"
							{impulse up 4 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						}
					else rand 0.80
						{component disable work}
					}
				else min_energy 3.0
					{if rand 0.25
						{component disable work}
					}
				}
			}
		)
		("blast_shield" args 1)
		("blast_shield" args 2)
		("blast_shield" args 3)
		("blast_shield" args 4)
		("blast_shield" args 5)
		("blast_shield" args 6)
		("blast_shield" args 7)
		("blast_shield" args 8)
		("blast_shield" args 9)
		("blast_shield" args left)
		("blast_shield" args right)
	}
	{on "cut_parts"
		(define "cut_shield"
			{component disable work repair}
			{tear "piece_medium_steel" bone "shield_%0" ;id "shield_%0"
				{volumes disable bullet contact blast}
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
			}
		)
			("cut_shield" args 1)
		("cut_shield" args 2)
		("cut_shield" args 3)
		("cut_shield" args 4)
		("cut_shield" args 5)
		("cut_shield" args 6)
		("cut_shield" args 7)
		("cut_shield" args 8)
		("cut_shield" args 9)
		("cut_shield" args left)
		("cut_shield" args right)
	}
}

;---------------------------- Бронемашины ------------------------------------

{"armored_car"
        {inflammation_time 80}
	{blast_absorption 3.5}
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on blast_hit
		{if min_energy 6
			{impulse up 2 0.2 dir 1.5 0.1}
		 else min_energy 1
			{impulse up 0.5 0.2 dir 0.3 0.1}
		 else min_energy 0.4
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 9
				{call "explosion"}
			else min_energy 8
				{call "btr_kill"}
			}
		else  volume "track"
			{if min_energy 8
				{component disable work}
				{call "tank_kill"}
			else min_energy 7
				{component disable work}
			else min_energy 4
				{if rand 0.40
					{component disable work}
				}
			else min_energy 2
				{if rand 0.20
					{component disable work}
				}
			}
		}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" disable work repair}
			{call "stat_break"}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 3.5 2.1 dir 1.8 1.3 cx 2.8 1.65 cy 3.5 1.4 rnd_dir 10 no_position}
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
	{on bullet_hit																		{if bullet "flame"
	              	{fire radius 1.5 time 20 heating 20 effector followowner}
   		}
 		{if bullet "big shell extra"
			{impulse up 0.6 0.2 dir 0.3 0.05}
		 	{ani_play "hit"}
 		else bullet "big shell"
			{impulse up 0.4 0.1 dir 0.15 0.02}
 			{ani_play "hit"}
		else bullet "shell"
		 	{ani_play "hit"}
		}
		{if volume "turret"
			{if bullet "bomb big shell"
				{call "explosion"}
			else bullet "extra big shell"
				{call "tear_turret"}
				{if rand 0.20 {call "_burn"}}
				{if rand 0.60 {kill_crew "driver"}}
				{kill_crew "gunner"}
				{kill_crew "charger"}
				{kill_crew "commander"}
			else bullet "big shell fg"
				{if rand 0.80 {call "tear_turret"}}
				{if rand 0.30 {call "_burn"}}
				{if rand 0.30 {kill_crew "driver"}}
				{kill_crew "gunner"}
				{kill_crew "charger"}
				{kill_crew "commander"}
			else bullet "shell fg"
				{if rand 0.60 {call "tear_turret"}}
				{if rand 0.20 {components "turret" disable work}}
				{if rand 0.20 {components "gun" disable work}}
			else bullet "small shell fg"
				{if rand 0.10 {components "gun" disable work}}
			}
		}
		{if volume "body"
			{if bullet "bomb big shell"
				{call "explosion"}
		 	else bullet "extra big shell"
				{call "explosion"}
			else bullet "big shell fg"
				{if rand 0.40
					{call "btr_kill"}
				}
				{if rand 0.20 {call "_burn"}}
				{if rand 0.30 {call "explosion"}}
				{if rand 0.20 {kill_crew "driver"}}
			else bullet "shell fg"
				{if rand 0.20 {call "btr_kill"}}
			}
		}
	}
	{on pierce
		{burn fx "smoke_grey" fake}
		{if volume "turret"
			{burn fx "smoke_dead_tank1" fake}
			{if bullet "bomb big shell"
				{call "tear_turret"}
				{if rand 0.60 {call "_burn"}}
			else bullet "extra big shell"
				{call "tear_turret"}
				{if rand 0.60 {call "_burn"}}

			else bullet "big shell"
				{if rand 0.60 {call "tear_turret"}}
				{components "turret" disable work}
				{components "gun" disable work}
				{if rand 0.30 {call "_burn"}}
			else bullet "small shell"
				{components "turret" disable work}

			else bullet "small shell az"
                              {call "_burn"}
			else bullet "shell20 az"
				{if rand 0.40 {components "turret" disable work}}
				{if rand 0.80 {call "_burn"}}


			else bullet "zenite ap"
				{if rand 0.50 {components "turret" disable work}}

			else bullet "shell"
			 	{components "turret" disable work}
 				{if rand 0.20 {call "_burn"}}

		  }
		}
		{if volume "body"
			{burn fx "smoke_dead_tank1" fake}
			{if bullet "bomb big shell"
				{call "btr_kill"}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
				{if rand 1.00 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.60 {kill_crew "charger"}}
			else bullet "extra big shell"
				{call "btr_kill"}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
				{if rand 1.00 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.60 {kill_crew "charger"}}
				{if rand 0.60 {kill_crew "commander"}}

			else bullet "big shell"
				{call "btr_kill"}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
				{if rand 1.00 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.40 {kill_crew "charger"}}
				{if rand 0.40 {kill_crew "commander"}}
			else bullet "small shell"
				{if rand 0.40 {call "btr_kill"}}
				{if rand 0.10 {call "_burn"}}
 				{if rand 0.50 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.10 {kill_crew "charger"}}
				{if rand 0.10 {kill_crew "commander"}}

			else bullet "rpg shell"
				{if rand 0.90 {call "btr_kill"}}
				{if rand 0.50 {call "_burn"}}

			else bullet "zenite ap"
				{if rand 0.30 {call "btr_kill"}}
				{if rand 0.20 {call "_burn"}}
				{if rand 0.40 {kill_crew "driver"}}
				{if rand 0.05 {kill_crew "gunner"}}
				{if rand 0.05 {kill_crew "charger"}}
				{if rand 0.05 {kill_crew "commander"}}

			else bullet "shell"
			 	{if rand 0.55 {call "btr_kill"}}
			 	{if rand 0.25 {call "_burn"}}
			 	{if rand 0.05 {call "explosion"}}
			 	{if rand 0.80 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.20 {kill_crew "charger"}}
				{if rand 0.20 {kill_crew "commander"}}

                	else bullet "small shell az"
	                          {call "_burn"}
				{if rand 0.80 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.20 {kill_crew "charger"}}
				{if rand 0.20 {kill_crew "commander"}}

 			else bullet "shell20 az"
				{if rand 0.40 {components disable work}}
				{if rand 0.95 {call "_burn"}}
				{if rand 0.50 {kill_crew "driver"}}
				{if rand 0.00 {kill_crew "gunner"}}
				{if rand 0.20 {kill_crew "charger"}}
				{if rand 0.20 {kill_crew "commander"}}

			}
		}
		{if volume "track"
			{if bullet "bomb big shell"
				{component  disable work}
			else bullet "extra big shell"
				{component  disable work}
			else bullet "big shell"
				{if rand 0.80 {component disable work}}
			else bullet "small shell"
				{if rand 0.40 {component disable work}}
			else bullet "zenite ap"
				{if rand 0.50 {component disable work}}
			else bullet "shell"
			 	{if rand 0.60 {component disable work}}

	      		else bullet "small shell az"
				{if rand 0.45 {component disable work}}
        	                 {if rand 0.11  {call "_burn"}}

	        	else  bullet "shell20 az"
                        	{if rand 0.10  {call "_burn"}}
				{if rand 0.35 {component disable work}}

			}
		}

		{if volume "engine"
			{if bullet "extra big shell"
				{call "explosion"}
			else bullet "big shell"
				{components "engine" disable work}
				{if rand 0.60 {call "_burn"}}
				{if rand 0.30 {call "explosion"}}
			else bullet "small shell"
		  	        {if rand 0.60 {components "engine" disable work}}
				{if rand 0.30 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
                        else bullet "zenite ap"
				{if rand 0.50 {components "engine" disable work}}
				{if rand 0.25 {call "_burn"}}
				{if rand 0.10 {call "explosion"}}
			else bullet "shell"
			 	{if rand 0.80 {components "engine" disable work}}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}

              		else bullet "small shell az"
   				{if rand 0.40 {components disable work}}
                	        {call "_burn"}
				{if rand 0.21 {call "explosion"}}

                        else bullet "shell20 az"
				{if rand 0.40 {components disable work}}
				{call "_burn"}
				{if rand 0.15 {call "explosion"}}

			}
		}

		{if volume "crew"
			{if bullet "extra big shell"
				{if rand 0.50 {kill_crew "driver"}}
				{if rand 1.00 {kill_crew "gunner"}}
				{if rand 1.00 {kill_crew "charger"}}
				{if rand 1.00 {kill_crew "commander"}}
			else bullet "big shell"
				{if rand 0.35 {kill_crew "driver"}}
				{if rand 0.65 {kill_crew "gunner"}}
				{if rand 0.65 {kill_crew "charger"}}
				{if rand 0.65 {kill_crew "commander"}}
			else bullet "small shell"
				{if rand 0.10 {kill_crew "driver"}}
				{if rand 0.30 {kill_crew "gunner"}}
				{if rand 0.30 {kill_crew "charger"}}
				{if rand 0.30 {kill_crew "commander"}}
			else bullet "rpg shell"
				{if rand 0.60 {call "tank_kill"}}
				{if rand 0.50 {kill_crew "charger"}}
				{if rand 0.50 {kill_crew "commander"}}
			else bullet "zenite ap"
				{if rand 0.05 {kill_crew "driver"}}
				{if rand 0.20 {kill_crew "gunner"}}
				{if rand 0.20 {kill_crew "charger"}}
				{if rand 0.20 {kill_crew "commander"}}
			else bullet "shell20 az"
				{if rand 0.30 {kill_crew "driver"}}
				{if rand 0.30 {kill_crew "gunner"}}
				{if rand 0.30 {kill_crew "charger"}}
				{if rand 0.30 {kill_crew "commander"}}
			else bullet "small shell az"
				{if rand 0.50 {kill_crew "driver"}}
				{if rand 0.50 {kill_crew "gunner"}}
				{if rand 0.50 {kill_crew "charger"}}
				{if rand 0.40 {kill_crew "commander"}}
			else bullet "shell"
				{if rand 0.20 {kill_crew "driver"}}
				{if rand 0.50 {kill_crew "gunner"}}
				{if rand 0.50 {kill_crew "charger"}}
				{if rand 0.50 {kill_crew "commander"}}
 			}
		}

	}
	{on "explosion"
		{impulse up 1.5 0.5 dir 0.4 0.2 }
	}
}
{"bulldozer tank"
        {inflammation_time 90}
	{blast_absorption 1}
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" disable work repair}
			{call "stat_break"}
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
	{on blast_hit
		{if min_energy  6
			{impulse up 1.4 0.7 dir 1.0 0.8}
		 else min_energy 1.5
			{impulse up 0.8 0.4 dir 0.5 0.4}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 4.0
				{call "tank_kill"}
			}
		}
		{if volume "track"
			{if min_energy 12.5
                                {component disable work}
				{call "explosion"}
			else min_energy 10
				{component disable work}
				{call "tank_kill"}
				{if rand 0.60
					{call "_burn"}
				}
			else min_energy 8.0
				{component disable work}
				{call "tank_kill"}
				{if rand 0.40
					{call "_burn"}
				}
			else min_energy 5.5
				{if rand 0.30
					{component disable work}
				}
			else min_energy 3
				{if rand 0.18
					{component disable work}
				}
			else min_energy 1
				{if rand 0.12
					{component disable work}
				}
			}
		}

	}
	{on bullet_hit
 		{if bullet "extra big shell"
			{impulse up 1 0.2 dir 0.5 0.05}
		 	{ani_play "hit"}
		else bullet "big shell"
 			{impulse up 0.3 0.2 dir 0.1 0.05}
 			{ani_play "hit"}
		else bullet "shell"
		 	{ani_play "hit"}
		}
		{if volume "body"
			{if bullet "bomb2 big shell"
				{call "explosion"}
			else bullet "bomb big shell"
				{call "explosion"}
		 	else bullet "extra2 big shell"
				{call "explosion"}
		 	else bullet "extra big shell"
				{call "explosion"}
			else bullet "big shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.25
					{call "tank_kill"}
				}
				{if rand 0.20 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
				{if rand 0.20 {kill_crew "driver"}}
			else bullet "shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.08 {call "tank_kill"}}
				{if rand 0.10 {call "_burn"}}
			}
		}
	}
	{on pierce
		{burn fx "smoke_grey" fake}

		{if volume "body"
			{burn fx "smoke_dead_tank1" fake}
		 	{if bullet "bomb big shell"
		 		{call "tank_kill"}
		 		{call "_burn"}
		 		{if rand 0.60
		 			{call "explosion"}
		 		}
		 	else bullet "extra big shell"
				{call "tank_kill"}
				{if rand 1.00 {call "_burn"}}
				{if rand 0.50 {call "explosion"}}
			else bullet "big shell"
				{if rand 0.85 {call "tank_kill"}}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
			else bullet "small shell"
				{if rand 0.55 {call "tank_kill"}}
				{if rand 0.15 {call "_burn"}}
			else bullet "rpg shell"
				{if rand 0.9 {call "tank_kill"}}
				{if rand 0.55 {call "_burn"}}
			else bullet "zenite ap"
				{if rand 0.30 {call "tank_kill"}}
			else bullet "shell"
			 	{if rand 0.70 {call "tank_kill"}}
			 	{if rand 0.25 {call "_burn"}}
			 	{if rand 0.10 {call "explosion"}}
			else bullet "shell20 az"
				{if rand 0.30 {components disable work}}
         		  	{if rand 0.80 {call "_burn"}}
	       		else bullet "small shell az"
			    	{if rand 0.40 {call "tank_kill"}}
			     	{if rand 0.96 {call "_burn"}}
			}
		}
		{if volume "track"
			{if bullet "bomb big shell"
			else bullet "extra big shell"
				{component  disable work}
			else bullet "big shell"
				{if rand 0.80 {component disable work}}
			else bullet "rpg shell"
			  	{if rand 0.75 {component disable work}}
			else bullet "small shell"
			  	{if rand 0.40 {component disable work}}
			else bullet "zenite ap"
				{if rand 0.4 {component disable work}}
			else bullet "shell"
			 	{if rand 0.60 {component disable work}}
			else bullet "shell20 az"
        	                {if rand 0.01 {call "_burn"}}
				{if rand 0.33 {component disable work}}
			else bullet "small shell az"
        	                {if rand 0.02 {call "_burn"}}
				{if rand 0.45 {component disable work}}
			}
		}
		{if volume "engine"
			{if bullet "extra big shell"
				{call "explosion"}
			else bullet "big shell"
				{components "engine" disable work}
				{if rand 0.50 {call "_burn"}}
				{if rand 0.40 {call "explosion"}}
			else bullet "small shell"
		  		{if rand 0.60 {components "engine" disable work}}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
			else bullet "rpg shell"
		  		{if rand 0.85 {components "engine" disable work}}
		  		{if rand 0.50 {call "_burn"}}
		  		{if rand 0.30 {call "explosion"}}
			else bullet "zenite ap"
				{if rand 0.40 {components "engine" disable work}}
				{if rand 0.35 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
			else bullet "shell"
			 	{if rand 0.80 {components "engine" disable work}}
				{if rand 0.50 {call "_burn"}}
				{if rand 0.30 {call "explosion"}}
			else bullet "small shell az"
			  	{if rand 0.60 {components "engine" disable work}}
				{call "_burn"}
				{if rand 0.10 {call "explosion"}}
			else bullet "shell20 az"
				{if rand 0.30 {components disable work}}
         		  	{if rand 0.71 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}

			}
		}
		{if volume "inventory"
			{if bullet "bomb big dhell"
				{if rand 0.30 {call "explosion"}}
				{if rand 0.80 {call "_burn"}}
			else bullet "extra big shell"
				{if rand 0.20 {call "explosion"}}
				{if rand 0.60 {call "_burn"}}
			else bullet "big shell"
				{if rand 0.15 {call "explosion"}}
				{if rand 0.35{call "_burn"}}
			else bullet "small shell"
			  	{if rand 0.10 {call "explosion"}}
				{if rand 0.25 {call "_burn"}}
			else bullet "rpg shell"
		  		{if rand 0.30 {call "explosion"}}
		 	 	{if rand 0.70 {call "_burn"}}
			else bullet "zenite ap"
				{if rand 0.10 {call "_burn"}}
			else bullet "shell"
			 	{if rand 0.10 {call "explosion"}}
				{if rand 0.25 {call "_burn"}}
			}
		}
	}
	{on "explosion"
		{impulse up 0.5}
	}
}

{"light tank"
        {inflammation_time 120}
	{blast_absorption 3}
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" disable work repair}
			{call "stat_break"}
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
	{on blast_hit
		{if min_energy  8
{impulse up 1.4 0.7 dir 1.0 0.8}
		 else min_energy 1.5
{impulse up 0.8 0.4 dir 0.5 0.4}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 7.0
				{call "tank_kill"}
			}
		}

		{if volume "track"
			{if min_energy 12.5
                                     {component disable work}
				{call "explosion"}
			else min_energy 10
				{component disable work}
				{call "tank_kill"}
				{if rand 0.60
					{call "_burn"}
				}
			else min_energy 8.0
				{component disable work}
				{call "tank_kill"}
				{if rand 0.40
					{call "_burn"}
				}
			else min_energy 5.5
				{if rand 0.30
					{component disable work}
				}
			else min_energy 3
				{if rand 0.18
					{component disable work}
				}
			else min_energy 1
				{if rand 0.12
					{component disable work}
				}
			}
		}

	}
; -------------- Обработка попадания (есть или нет пробитие не важно.)
	{on bullet_hit
 		{if bullet "extra big shell"
			{impulse up 1 0.2 dir 0.5 0.05}
		 	{ani_play "hit"}
        else bullet "big shell"
            {impulse up 0.3 0.2 dir 0.1 0.05}
        {ani_play "hit"}
		 else bullet "shell"
		 	{ani_play "hit"}
		}
		{if volume "turret"
			{if bullet "bomb big shell"
				{if rand 0.90
					{call "tear_turret"}
					{kill_crew "gunner"}
					{kill_crew "commander"}
				}
			else bullet "extra2 big shell"
				{if rand 0.90
					{call "tear_turret"}
					{kill_crew "gunner"}
					{kill_crew "commander"}
				}
				{if rand 0.90 {call "tank_kill"}}
				{if rand 0.30 {call "_burn"}}
				{if rand 0.30 {kill_crew "driver"}}
			else bullet "extra big shell"
				{if rand 0.90
					{call "tear_turret"}
					{kill_crew "gunner"}
					{kill_crew "commander"}
				}
				{if rand 0.90 {call "tank_kill"}}
				{if rand 0.30 {call "_burn"}}
				{if rand 0.30 {kill_crew "driver"}}
			else bullet "big shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.75
					{call "tear_turret"}
					{kill_crew "gunner"}
					{kill_crew "commander"}
				}
			{if rand 0.60 {call "tank_kill"}}
				{if rand 0.25 {component disable work}}
				{if rand 0.30 {call "_burn"}}
				{if rand 0.20 {kill_crew "driver"}}
				{if rand 0.30 {components "gun" disable work}}
			else bullet "small shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.10 {components "turret" disable work}}
				{if rand 0.10 {components "gun" disable work}}
			else bullet "shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.10 {components "turret" disable work}}
				{if rand 0.20 {components "gun" disable work}}
			}
		}
		{if volume "body"
			{if bullet "bomb2 big shell"
				{call "explosion"}
			else bullet "bomb big shell"
				{call "explosion"}
		 	else bullet "extra2 big shell"
				{call "explosion"}
		 	else bullet "extra big shell"
				{call "explosion"}
			else bullet "big shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.25
					{call "tank_kill"}
				}
				{if rand 0.20 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
				{if rand 0.20 {kill_crew "driver"}}
			else bullet "shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.08 {call "tank_kill"}}
				{if rand 0.10 {call "_burn"}}
			}
		}
	}
; --------   Обработка пробития брони легкого танка -------------
	{on pierce
		{burn fx "smoke_grey" fake}
		{if volume "turret"
			{burn fx "smoke_dead_tank1" fake}
			{if bullet "bomb big shell"
				{call "tear_turret"}
				{call "tank_kill"}
				{call "_burn"}
				{kill_crew "gunner"}
				{kill_crew "commander"}
			else bullet "extra big shell"
				{call "tear_turret"}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.40
					{call "tank_kill"}
				}
			else bullet "big shell"
				{if rand 0.60 {call "tear_turret"}}
				{components "turret" disable work}
				{components "gun" disable work}
				{if rand 0.25 {call "_burn"}}
				{if rand 0.30
					{call "tank_kill"}
				}
			else bullet "small shell"
				{if rand 0.30 {components "gun" disable work}}
				{if rand 0.5
		  			{components "turret" disable work}
				}
				{if rand 0.15
					{call "_burn"}
			 	}
				{if rand 0.05
					{call "tank_kill"}
			 	}

			else bullet "small shell_az"
				{if rand 0.30 {components "gun" disable work}}
				{if rand 0.5
		  			{components "turret" disable work}
				}

				{call "_burn"}

		                {if rand 0.10
			 			{call "tank_kill"}
			 	}

			else bullet "shell20 az"
				{if rand 0.30 {components disable work}}
         		  	{if rand 0.60 {call "_burn"}}


			else bullet "rpg shell"
				{if rand 1.00
					{components "gun" disable work}
				}
		  	{component disable work}
		  	{if rand 0.60 {call "_burn"}}
			else bullet "zenite ap"
				{if rand 0.30 {components "turret" disable work}}
			else bullet "shell"
			 	{if rand 0.80 {components "turret" disable work}}
				{if rand 0.20
			 			{call "tank_kill"}
			 	}
			 	{if rand 0.50 {components "gun" disable work}}
			 	{if rand 0.20 {call "_burn"}}


		  }
		}
		{if volume "body"
			{burn fx "smoke_dead_tank1" fake}
		 	{if bullet "bomb big shell"
		 		{call "tank_kill"}
		 		{call "_burn"}
		 		{if rand 0.60
		 			{call "explosion"}
		 		}
		 	else bullet "extra big shell"
				{call "tank_kill"}
				{if rand 1.00 {call "_burn"}}
				{if rand 0.50 {call "explosion"}}

			else bullet "big shell"
				{if rand 0.85 {call "tank_kill"}}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
			else bullet "small shell"
				{if rand 0.55 {call "tank_kill"}}
				{if rand 0.15 {call "_burn"}}
			else bullet "rpg shell"
				{if rand 0.9 {call "tank_kill"}}
				{if rand 0.55 {call "_burn"}}
			else bullet "zenite ap"
				{if rand 0.30 {call "tank_kill"}}
			else bullet "shell"
			 	{if rand 0.70 {call "tank_kill"}}
			 	{if rand 0.25 {call "_burn"}}
			 	{if rand 0.10 {call "explosion"}}

			else bullet "shell20 az"
				{if rand 0.30 {components disable work}}
         		  	{if rand 0.80 {call "_burn"}}
	       		else bullet "small shell az"
			    {if rand 0.40
			      {call "tank_kill"}
			    }
			     { if rand 0.96 {call "_burn"}}


		  }
		}
		{if volume "track"
			{if bullet "bomb big shell"
			else bullet "extra big shell"
				{component  disable work}
			else bullet "big shell"
				{if rand 0.80 {component disable work}}
			else bullet "rpg shell"
			  	{if rand 0.75 {component disable work}}
			else bullet "small shell"
			  	{if rand 0.40 {component disable work}}
			else bullet "zenite ap"
				{if rand 0.4 {component disable work}}
			else bullet "shell"
			 	{if rand 0.60 {component disable work}}
			else bullet "shell20 az"
        	                {if rand 0.01 {call "_burn"}}
				{if rand 0.33 {component disable work}}
			else bullet "small shell az"
        	                {if rand 0.02 {call "_burn"}}
				{if rand 0.45 {component disable work}}


		  }
		}
		{if volume "engine"
			{if bullet "extra big shell"
				{call "explosion"}
			else bullet "big shell"
				{components "engine" disable work}
				{if rand 0.50 {call "_burn"}}
				{if rand 0.40 {call "explosion"}}
			else bullet "small shell"
		  	{if rand 0.60 {components "engine" disable work}}
				{if rand 0.40 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
			else bullet "rpg shell"
		  	{if rand 0.85 {components "engine" disable work}}
		  	{if rand 0.50 {call "_burn"}}
		  	{if rand 0.30 {call "explosion"}}
			else bullet "zenite ap"
				{if rand 0.40 {components "engine" disable work}}
				{if rand 0.35 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
			else bullet "shell"
			 	{if rand 0.80 {components "engine" disable work}}
				{if rand 0.50 {call "_burn"}}
				{if rand 0.30 {call "explosion"}}
			else bullet "small shell az"
			  	{if rand 0.60 {components "engine" disable work}}
				{call "_burn"}
				{if rand 0.10 {call "explosion"}}
			else bullet "shell20 az"
				{if rand 0.30 {components disable work}}
         		  	{if rand 0.71 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}

		  }
		}
;		{if volume "inventory"
;			{if bullet "bomb big dhell"
;				{if rand 0.30 {call "explosion"}}
;				{if rand 0.80 {call "_burn"}}
;			else bullet "extra big shell"
;				{if rand 0.20 {call "explosion"}}
;				{if rand 0.60 {call "_burn"}}
;			else bullet "big shell"
;				{if rand 0.15 {call "explosion"}}
;				{if rand 0.35{call "_burn"}}
;			else bullet "small shell"
;		  	{if rand 0.10 {call "explosion"}}
;				{if rand 0.25 {call "_burn"}}
;
;			else bullet "rpg shell"
;		  	{if rand 0.30 {call "explosion"}}
;		  	{if rand 0.70 {call "_burn"}}
;			else bullet "zenite ap"
;					{if rand 0.10 {call "_burn"}}
;			else bullet "shell"
;			 	{if rand 0.10 {call "explosion"}}
;				{if rand 0.25 {call "_burn"}}
;		  }
;		}
			{if volume "shield_left"
				{if work "shield_left"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
								{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
			{if volume "shield_right"
				{if work "shield_right"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
							{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
			{if volume "Turret_shield"
				{if work "shield_shield"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
           		{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}

{if volume "crew"
{if bullet "extra big shell"
{if rand 0.50 {kill_crew "driver"}}
{if rand 0.90 {kill_crew "gunner"}}
{if rand 0.90 {kill_crew "charger"}}
{if rand 0.90 {kill_crew "commander"}}
else bullet "big shell"
{if rand 0.30 {kill_crew "driver"}}
{if rand 0.60 {kill_crew "gunner"}}
{if rand 0.60 {kill_crew "charger"}}
{if rand 0.60 {kill_crew "commander"}}
else bullet "small shell"
{if rand 0.05 {kill_crew "driver"}}
{if rand 0.25 {kill_crew "gunner"}}
{if rand 0.25 {kill_crew "charger"}}
{if rand 0.25 {kill_crew "commander"}}
else bullet "rpg shell"
{if rand 0.60 {call "tank_kill"}}
{if rand 0.05 {kill_crew "gunner"}}
{if rand 0.50 {kill_crew "charger"}}
{if rand 0.40 {kill_crew "commander"}}
else bullet "zenite ap"
{if rand 0.10 {kill_crew "driver"}}
{if rand 0.15 {kill_crew "gunner"}}
{if rand 0.15 {kill_crew "charger"}}
{if rand 0.15 {kill_crew "commander"}}
else bullet "shell"
{if rand 0.25 {kill_crew "driver"}}
{if rand 0.45 {kill_crew "gunner"}}
{if rand 0.45 {kill_crew "charger"}}
{if rand 0.45 {kill_crew "commander"}}

else bullet "shell20 az"
{if rand 0.25 {kill_crew "driver"}}
{if rand 0.25 {kill_crew "gunner"}}
{if rand 0.25 {kill_crew "charger"}}
{if rand 0.25 {kill_crew "commander"}}
else bullet "small shell az"
{if rand 0.35 {kill_crew "driver"}}
{if rand 0.35 {kill_crew "gunner"}}
{if rand 0.35 {kill_crew "charger"}}
{if rand 0.25 {kill_crew "commander"}}

  }
}
	}
	{on "explosion"
		{impulse up 0.5}
	}
}

; ------------------------------------  Средние танки ------------------------------------------

{"medium tank"
	{inflammation_time 180}
	{blast_absorption 6}
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	{on blast_hit
		{if min_energy 8
{impulse up 0.6 0.2 dir 0.3 0.05}
		 else min_energy 4
{impulse up 0.3 0.1 dir 0.3 0.05}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" disable work repair}
			{call "stat_break"}
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
	{on blast
		{if volume "body"
			{if min_energy 16
				{call "tank_kill"}
				{kill_crew}
				{if rand 0.70 {call "explosion"}}
				{if rand 0.50 {call "_burn"}}
				{able select 0}
			else min_energy 12.5
				{if rand 0.30
					{call "explosion"}
				else
					{call "tank_kill"}
					{if rand 0.30 {call "_burn"}}
				}
			else min_energy 11
					{if rand 0.65
						{call "tank_kill"}
					}
				{if rand 0.30
						{call "_burn"}
					}
;			else min_energy 10
;					{if rand 0.60
;						{component disable work}
;					}
			}
		}

		{if volume "engine"
			{if min_energy 5
					{components "engine" disable work}
					{if rand 0.45
						{call "_burn"}
					}
			else min_energy 3.1
				{if effector "grenade"
					{components "engine" disable work}
					{if rand 0.45
						{call "_burn"}
					}
				}

			else min_energy 1.3
				{if effector "grenade"
					{components "engine" disable work}
					{if rand 0.20
						{call "_burn"}
					}
				}
			}
		}
		{if volume "track"
;			{if min_energy 19
;				{call "tank_kill"}
;				{kill_crew}
;				{if rand 0.70 {call "explosion"}}
;				{if rand 0.50 {call "_burn"}}
;				{able select 0}
;			}
			{if min_energy 12.5
				{if rand 0.30
					{call "explosion"}
				else
					{call "tank_kill"}
					{if rand 0.30 {call "_burn"}}
				}
			else min_energy 10
				{if rand 0.60
					{component disable work}
				}
			else min_energy 9
				{if rand 0.40
					{component disable work}
				}
			else min_energy 8
				{if rand 0.30
					{component disable work}
				}
			else min_energy 5
				{if rand 0.15
					{component disable work}
				}
			else min_energy 3
				{if rand 0.10
					{component disable work}
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
{on bullet_hit; ---- Обработка попадания (есть или нет пробитие не важно.)
 		{if bullet "bomb big shell"
			{impulse up 0.6 0.2 dir 0.3 0.05}
		 	{ani_play "hit"}
 		else bullet "extra big shell"
			{impulse up 0.6 0.2 dir 0.3 0.05}
		 	{ani_play "hit"}
 		else bullet "big shell"
			{impulse up 0.3 0.1 dir 0.3 0.05}
 			{ani_play "hit"}
		else bullet "shell"
		 	{ani_play "hit"}
		}
		{if volume "turret"
			{if bullet "bomb2 big shell fg"
				{call "tear_turret"}
				{call "tank_kill"}
				{if rand 0.5
					{call "_burn"}
				}
			else bullet "bomb big shell ap"
;				{start_sound "small_explosion.break"}
				{components "turret" disable work}
				{if rand 0.40 {components "gun" disable work}}
				{if rand 0.30
					{call "tear_turret"}
					{call "tank_kill"}
					{kill_crew "gunner"}
					{kill_crew "commander"}
				}
				{if rand 0.80 {component disable work}}
				{if rand 0.20 {call "_burn"}}
				{if rand 0.15 {kill_crew "gunner"}}
				{if rand 0.15 {kill_crew "charger"}}
				{if rand 0.15 {kill_crew "commander"}}
			else bullet "extra2 big shell fg"
;				{start_sound "small_explosion.break"}
				{if rand 0.60
					{call "tear_turret"}
					{call "tank_kill"}
					{kill_crew "gunner"}
					{kill_crew "commander"}
				else
					{components "turret" disable work}
					{if rand 0.30 {call "tank_kill"}}
					{if rand 0.70 {components "gun" disable work}}
					{if rand 0.40 {call "_burn"}}
					{if rand 0.40 {kill_crew "gunner"}}
					{if rand 0.40 {kill_crew "charger"}}
					{if rand 0.60{kill_crew "commander"}}
				}
			else bullet "extra big shell ap"
;				{start_sound "small_explosion.break"}
				{if rand 0.30
					{components "turret" disable work}
					{if rand 0.30
						{call "tank_kill"}
					}
				}
				{if rand 0.20 {components "gun" disable work}}
				{if rand 0.20 {call "_burn"}}
			}
		else volume "body"
		 	{if bullet "bomb2 big shell fg"
;				{start_sound "small_explosion.break"}
		 		{call "tank_kill"}
		 		{if rand 0.30
		 			{call "explosion"}
		 		else rand 0.50
		 			{call "_burn"}
		 		}
		 	else bullet "bomb big shell ap"
				{start_sound "small_explosion.break"}
		 		{if rand 0.15
		 			{call "tank_kill"}
		 		}
		 		{if rand 0.10 {call "_burn"}}
		 	else bullet "extra2 big shell fg"
				{start_sound "small_explosion.break"}
				{if rand 0.40 {call "tank_kill"}}
				{if rand 0.25 {call "_burn"}}
;				{if rand 0.15 {call "explosion"}}
				{if rand 0.60 {kill_crew "driver"}}
;			else bullet "extra big shell ap"
;				{start_sound "small_explosion.break"}
;				{if rand 0.10 {call "tank_kill"}}
;				{if rand 0.05 {call "_burn"}}
			}
		}
}

; ------- Обработка пробития брони среднего танка ---------

{on pierce
		{burn fx "smoke_grey" fake}
		{if volume "turret"
                {burn fx "smoke_dead_tank1" fake}
			{if bullet "bomb big shell"
				{if rand 0.80
					{call "tear_turret"}
					{call "tank_kill"}
					{call "_burn"}
				else
					{components "turret" disable work}
					{if rand 0.60
						{call "tank_kill"}
					}
					{if rand 0.60
						{call "_burn"}
					}
				}
			else bullet "extra big shell"
				{if rand 0.40
					{call "tear_turret"}
					{call "tank_kill"}
				else
					{components "turret" disable work}
					{if rand 0.40
						{call "tank_kill"}
					}
					{if rand 0.20
						{call "_burn"}
                                               }
			          	{if rand 0.7
				          	{call "tear_turret"}
					}
					{if rand 0.75
						{components "gun" disable work}
					}
				}
			else bullet "big shell"
					{if rand 0.60
						{components "turret" disable work}
						{if rand 0.30
							{call "tank_kill"}
						}
					}
					{if rand 0.10
						{call "_burn"}
					}
                                            {if rand 0.4
					{call "tear_turret"}
				}
					{if rand 0.30
						{components "gun" disable work}
					}
			else bullet "small shell"
					{if rand 0.35
			  		{components "turret" disable work}
					}
					{if rand 0.10
						{components "gun" disable work}
					}
			else bullet "rpg shell"
					{if rand 0.70
						{components "turret" disable work}
						{if rand 0.50
				  			{call "tank_kill"}
						}
					}
					{if rand 0.30
						{call "_burn"}
					}
					{if rand 0.30
						{components "gun" disable work}
					}
			else bullet "zenite ap"
					{if rand 0.25 {components "turret" disable work}}
                        else bullet "small shell az"
			    {if rand 0.38
		  		{components "turret" disable work}
                            }
				{if rand 0.10
					{components "gun" disable work}
				}
				{if rand 0.55 {call "_burn"}}
			else bullet "shell20 az"
				{if rand 0.10 {components disable work}}
         		  	{if rand 0.60 {call "_burn"}}

			else bullet "shell"
				 	{if rand 0.45
				 		{components "turret" disable work}
						{if rand 0.25
								{call "tank_kill"}
						}
				 	}
					{if rand 0.20
						{components "gun" disable work}
					}
			}
		else volume "body"
			{burn fx "smoke_dead_tank1" fake}
			{if bullet "bomb big shell"
				{if rand 0.25
					{call "exposion"}
				}
				{if rand 1.00 {call "tank_kill"}}
				{if rand 0.60 {call "_burn"}}

		 	else bullet "extra big shell"
				{if rand 0.9 {call "tank_kill"}}
				{if rand 0.2 {call "_burn"}}

			else bullet "big shell"
				{if rand 0.7 {call "tank_kill"}}
				{if rand 0.2 {call "_burn"}}

			else bullet "small shell"
				{if rand 0.40 {call "tank_kill"}}
                                {if rand 0.10 {call "_burn"}}

			else bullet "rpg shell"
				{if rand 0.60 {call "tank_kill"}}
				{if rand 0.60 {call "_burn"}}

			else bullet "zenite ap"
				{if rand 0.20 {call "tank_kill"}}

			else bullet "small shell az"
				{components "body" disable work}
				{if rand 0.85 {call "_burn"}}
		  		{if rand 0.30 {call "tank_kill"}}
			else bullet "shell20 az"
         		  	{if rand 0.70 {call "_burn"}}

			else bullet "shell"
			 	{if rand 0.5 {call "tank_kill"}}
				{if rand 0.15 {call "_burn"}}
			}
		}
		{if volume "track"
			{if bullet "bomb big shell"
				{component disable work}
			else bullet "extra big shell"
				{if rand 0.80 {component  disable work}}
			else bullet "big shell"
				{if rand 0.40 {component disable work}}
			else bullet "small shell"
			  	{if rand 0.25 {component disable work}}
			else bullet "rpg shell"
			  	{if rand 0.50 {component disable work}}
			else bullet "zenite ap"
				{if rand 0.20 {component disable work}}
			else bullet "shell"
			 	{if rand 0.35 {component disable work}}

      			else bullet "small shell az"
			  	{if rand 0.27 {component disable work}}
         		  	{if rand 0.02 {call "_burn"}}
			else bullet "shell20 az"
				{if rand 0.10 {components disable work}}
         		  	{if rand 0.01 {call "_burn"}}

		  }
		}
		{if volume "engine"
			{if bullet "extra big shell"
				{if rand 1.00 {components "engine" disable work}}
				{if rand 1.00 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
			else bullet "big shell"
				{if rand 0.99 {components "engine" disable work}}
				{if rand 0.80 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
			else bullet "small shell"
		  	{if rand 0.65 {components "engine" disable work}}
				{if rand 0.45 {call "_burn"}}
				{if rand 0.05 {call "explosion"}}
			else bullet "rpg shell"
		  	{if rand 0.80 {component disable work}}
		  	{if rand 0.99 {call "_burn"}}
		  	{if rand 0.20 {call "explosion"}}
			else bullet "zenite ap"
				{if rand 0.35 {components "engine" disable work}}
				{if rand 0.20 {call "_burn"}}
;				{if rand 0.10 {call "explosion"}}
			else bullet "shell"
			 	{if rand 0.85 {components "engine" disable work}}
				{if rand 0.60 {call "_burn"}}
				{if rand 0.10 {call "explosion"}}
			else bullet "small shell az"
			  	{if rand 0.40 {components "engine" disable work}}
				{if rand 0.95 {call "_burn"}}
				{if rand 0.10 {call "explosion"}}
			else bullet "shell20 az"
				{if rand 0.20 {components disable work}}
         		  	{if rand 0.88 {call "_burn"}}

		  }
		}
		{if volume "inventory"
			{if bullet "bomb big shell"
				{if rand 0.35 {call "explosion"}}
				{if rand 0.30 {call "_burn"}}
			else bullet "extra big shell"
				{if rand 0.30 {call "explosion"}}
				{if rand 0.20 {call "_burn"}}
			else bullet "big shell"
				{if rand 0.25 {call "explosion"}}
				{if rand 0.15 {call "_burn"}}
			else bullet "small shell"
				{if rand 0.15 {call "explosion"}}
				{if rand 0.05 {call "_burn"}}
			else bullet "rpg shell"
				{if rand 0.60 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
			else bullet "zenite ap"
					{if rand 0.05 {call "_burn"}}
			else bullet "shell"
			 	{if rand 0.20 {call "explosion"}}
				{if rand 0.10 {call "_burn"}}

			else bullet "small shell az"
			  	{if rand 0.15 {call "explosion"}}
				{if rand 0.91 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
			else bullet "shell20 az"
         		  	{if rand 0.60 {call "_burn"}}
				{if rand 0.05 {call "explosion"}}

		  }
		}

			{if volume "shield_left"
				{if work "shield_left"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
								{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
			{if volume "shield_right"
				{if work "shield_right"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
							{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
			{if volume "Turret_shield"
				{if work "shield_shield"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
           		{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}

{if volume "crew"
	{if bullet "bomb big shell"
	{if rand 0.50 {kill_crew "driver"}}
	{if rand 0.60 {kill_crew "gunner"}}
	{if rand 0.60 {kill_crew "charger"}}
	{if rand 0.60 {kill_crew "commander"}}
else bullet "extra big shell"
	{if rand 0.40 {kill_crew "driver"}}
	{if rand 0.50 {kill_crew "gunner"}}
	{if rand 0.50 {kill_crew "charger"}}
	{if rand 0.50 {kill_crew "commander"}}
else bullet "big shell"
	{if rand 0.30 {kill_crew "driver"}}
	{if rand 0.40 {kill_crew "gunner"}}
	{if rand 0.40 {kill_crew "charger"}}
	{if rand 0.40 {kill_crew "commander"}}
else bullet "small shell"
	{if rand 0.07 {kill_crew "driver"}}
	{if rand 0.17 {kill_crew "gunner"}}
	{if rand 0.17 {kill_crew "charger"}}
	{if rand 0.17 {kill_crew "commander"}}
else bullet "rpg shell"
	{if rand 0.40 {call "tank_kill"}}
	{if rand 0.07 {kill_crew "driver"}}
	{if rand 0.17 {kill_crew "gunner"}}
	{if rand 0.50 {kill_crew "charger"}}
	{if rand 0.30 {kill_crew "commander"}}
else bullet "zenite ap"
	{if rand 0.05 {kill_crew "driver"}}
	{if rand 0.05 {kill_crew "gunner"}}
	{if rand 0.05 {kill_crew "charger"}}
	{if rand 0.05 {kill_crew "commander"}}

else bullet "shell20 az"
	{if rand 0.10 {kill_crew "driver"}}
	{if rand 0.10 {kill_crew "gunner"}}
	{if rand 0.10 {kill_crew "charger"}}
	{if rand 0.09 {kill_crew "commander"}}
else bullet "shell shell az"
	{if rand 0.16 {kill_crew "driver"}}
	{if rand 0.15 {kill_crew "gunner"}}
	{if rand 0.16 {kill_crew "charger"}}
	{if rand 0.12 {kill_crew "commander"}}

else bullet "shell"
	{if rand 0.20 {kill_crew "driver"}}
	{if rand 0.30 {kill_crew "gunner"}}
	{if rand 0.30 {kill_crew "charger"}}
	{if rand 0.30 {kill_crew "commander"}}
 	}
}

}
}
; ------------------------------------  Тяжелые танки ------------------------------------------
{"heavy tank"
	{inflammation_time 220}
	{blast_absorption 8}
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_big" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	{on "explosion"
{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on blast_hit
		{if min_energy 12
			{impulse up 1 0.5 dir 1}
		 else min_energy 10
			{impulse up 0.6 0.2 dir 0.4 0.2}
		 else min_energy 3
		 	{ani_play "hit"}
		}
	}
	{on "check_water_level" overload
		{if water_level 1.8 {set "sinking" 1}}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" disable work repair}
			{call "stat_break"}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 0.5 0.6 dir 0.6 0.3 cx 0.2 0.1 cy 2 1 rnd_dir 3 no_position}
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

; ------------ Модель повреждений -----------------

    {on bullet_hit                  ; ---- Обработка попадания (есть или нет пробитие не важно.)
 		{if bullet "flame"
	              	{fire radius 1.5 time 20 heating 20 effector followowner}
   		}
		{if bullet "big shell extra"
    {impulse up 0.3 0.1 dir 0.3 0.05}
		 	{ani_play "hit"}
		 else bullet "big shell"
    {impulse up 0.15 0.05 dir 0.15 0.05}
		 	{ani_play "hit"}
		 else bullet "shell"
		 	{ani_play "hit"}
		}
		{if volume "turret"
			{if bullet "bomb2 big shell fg"
				{if rand 0.50
					{call "tear_turret"}
					{call "tank_kill"}
					{if rand 0.50
						{call "_burn"}
					}
				else
					{components "turret" disable work}
					{if rand 0.20 {call "tank_kill"}}
					{components "gun" disable work}
					{if rand 0.15 {call "_burn"}}
				}
			else bullet "bomb big shell ap"
				{if rand 0.05
					{components "turret" disable work}
					{if rand 0.30
						{call "tank_kill"}
					}
				}
				{if rand 0.10 {components "gun" disable work}}
				{if rand 0.10 {call "_burn"}}
				{if rand 0.05 {call "tank_kill"}}
				{if rand 0.05 {kill_crew "gunner"}}
				{if rand 0.05 {kill_crew "charger"}}
				{if rand 0.05 {kill_crew "commander"}}
			else bullet "extra2 big shell fg"
				{if rand 0.40
					{components "turret" disable work}
					{if rand 0.25
						{call "tank_kill"}
					}
				}
				{if rand 0.25 {components "gun" disable work}}
				{if rand 0.10 {call "_burn"}}
				{if rand 0.05 {call "tank_kill"}}
				{if rand 0.20 {kill_crew "gunner"}}
				{if rand 0.20 {kill_crew "charger"}}
				{if rand 0.20 {kill_crew "commander"}}
			}
		else volume "body"
		 	{if bullet "bomb2 big shell"
;				{start_sound "small_explosion.break"}
		 		{if rand 0.60
		 			{call "tank_kill"}
		 		}
		 		{if rand 0.20
		 			{call "_burn"}
		 		}
				{if rand 0.60 {kill_crew "driver"}}
				{if rand 0.30 {kill_crew "gunner"}}
				{if rand 0.30 {kill_crew "charger"}}
				{if rand 0.30 {kill_crew "commander"}}
		 	else bullet "bomb big shell"
;				{start_sound "small_explosion.break"}
				{if rand 0.05 {call "_burn"}}
				{if rand 0.05 {call "tank_kill"}}
				{if rand 0.10 {kill_crew "driver"}}
				{if rand 0.05 {kill_crew "gunner"}}
				{if rand 0.05 {kill_crew "charger"}}
				{if rand 0.05 {kill_crew "commander"}}
		 	else bullet "extra2 big shell fg"
;				{start_sound "small_explosion.break"}
				{if rand 0.12 {call "_burn"}}
				{if rand 0.12 {call "tank_kill"}}
				{if rand 0.20 {kill_crew "driver"}}
				{if rand 0.05 {kill_crew "gunner"}}
				{if rand 0.05 {kill_crew "charger"}}
				{if rand 0.05 {kill_crew "commander"}}
			}
		}
	}
    {on pierce  ; ---- Обработка пробития брони тяжелых танков
			{burn fx "smoke_grey" fake}
      		{if bullet "small shell az"
                         {if rand 0.30  {call "_burn"}}
		}

			{if volume "turret"
				{burn fx "smoke_dead_tank1" fake}
				{if bullet "bomb big shell"
					{component disable work}
					{if rand 0.50 {call "tank_kill"}}
					{if rand 0.40 {call "_burn"}}
				else bullet "extra big shell"
					{if rand 0.80
						{components "turret" disable work}
						{if rand 0.40
							{call "tank_kill"}
						}
					}
					{if rand 0.60
						{components "gun" disable work}
					}
				else bullet "big shell"
					{if rand 0.40
						{components "gun" disable work}
					}
					{if rand 0.55
						{components "turret" disable work}
						{if rand 0.25
								{call "tank_kill"}
						}
					}
					{if rand 0.10
						{call "_burn"}
					}
				else bullet "small shell"
					{if rand 0.15
						{components "turret" disable work}
					}
				else bullet "rpg shell"
					{if rand 0.50
						{component disable work}
						{if rand 0.35
							{call "tank_kill"}
						}
					}
					{if rand 0.40
						{components "gun" disable work}
					}
					{if rand 0.30
						{call "_burn"}
					}
                	else bullet "small shell az"
		  	        {if rand 0.20
                                        {components "turret" disable work}
                                }
				{if rand 0.85
					{call "_burn"}
				}
                	else bullet "shell20 az"
		  	        {if rand 0.20
                                        {components "turret" disable work}
                                }
				{if rand 0.55
					{call "_burn"}
				}


				else bullet "shell"
					{if rand 0.30
						{components "turret" disable work}
					}
					{if rand 0.20
						{components "gun" disable work}
					}
				}
		else volume "body"
			{burn fx "smoke_dead_tank1" fake}
			{if bullet "bomb big shell"
				{call "tank_kill"}
				{if rand 0.40 {call "_burn"}}
		 	else bullet "extra big shell"
				{if rand 0.7 {call "tank_kill"}}
				{if rand 0.30 {call "_burn"}}
			else bullet "big shell"
				{if rand 0.45 {call "tank_kill"}}
				{if rand 0.10 {call "_burn"}}
			else bullet "small shell"
				{if rand 0.35 {call "tank_kill"}}
			else bullet "rpg shell"
	  		{if rand 0.40
	  			{call "tank_kill"}
	  		}
	  		{if rand 0.40
	  			{call "_burn"}
	  		}

			else bullet "small shell az"
		  		{if rand 0.20 {call "tank_kill"}}
				{if rand 0.50 {call "_burn"}}
			else bullet "shell20 az"
		  		{if rand 0.05 {call "tank_kill"}}
				{if rand 0.30 {call "_burn"}}

			else bullet "shell"
			 	{if rand 0.35 {call "tank_kill"}}
;			 	{if rand 0.05 {call "_burn"}}
		  }
		}
		{if volume "track"
			{if bullet "bomb big shell"
				{if rand 0.80 {component disable work}}
			else bullet "extra big shell"
				{if rand 0.60 {component  disable work}}
			else bullet "big shell"
				{if rand 0.30 {component disable work}}
			else bullet "zenite ap"
				{if rand 0.10 {component disable work}}
			else bullet "small shell"
			  	{if rand 0.10 {component disable work}}
			else bullet "rpg shell"
		  		{if rand 0.30 {component disable work}}

			else bullet "small shell az"
			 	{if rand 0.22 {component disable work}}
			else bullet "shell20 az"
			 	{if rand 0.15 {component disable work}}


			else bullet "shell"
			 	{if rand 0.20 {component disable work}}
		  }
		}
		{if volume "engine"
			{if bullet "extra big shell"
				{if rand 1.00 {components "engine" disable work}}
				{if rand 0.60 {call "_burn"}}
				{if rand 0.40 {call "explosion"}}
			else bullet "big shell"
				{if rand 0.90 {components "engine" disable work}}
				{if rand 0.60 {call "_burn"}}
				{if rand 0.25 {call "explosion"}}
			else bullet "small shell"
		  	{if rand 0.60 {components "engine" disable work}}
				{if rand 0.30 {call "_burn"}}
				{if rand 0.15 {call "explosion"}}
			else bullet "rpg shell"
	  		{if rand 0.60
	  			{component disable work}
	  		}
	  		{if rand 0.60
	  			{call "_burn"}
	  		}
	  		{if rand 0.20 {call "explosion"}}

			else bullet "small shell az"
			  	{if rand 0.25 {components "engine" disable work}}
				{if rand 0.95 {call "_burn"}}
				{if rand 0.05 {call "explosion"}}
			else bullet "shell20 az"
			  	{if rand 0.15 {components "engine" disable work}}
				{if rand 0.75 {call "_burn"}}
				{if rand 0.05 {call "explosion"}}

			else bullet "shell"
			 	{if rand 0.75 {components "engine" disable work}}
				{if rand 0.50 {call "_burn"}}
				{if rand 0.20 {call "explosion"}}
		  }
		}
			{if volume "shield_left"
				{if work "shield_left"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
								{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
			{if volume "shield_right"
				{if work "shield_right"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
							{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
			{if volume "Turret_shield"
				{if work "shield_shield"        ;если щит целый
					{if bullet "rpg shell"            ;для базуки
						{if rand 0.60
							{bullet_detonate}
						else                       ;50% шанс убить щит
							{bullet_detonate}
							{component disable work}
						}
						else bullet "zenite ap"
           		{bullet_detonate}
								{if rand 0.20
									{component disable work}
								}
					}
				}
			}
		{if volume "inventory"
			{if bullet "bomb big shell"
				{if rand 0.30 {call "explosion"}}
				{if rand 0.20 {call "_burn"}}
			else bullet "extra big shell"
				{if rand 0.25 {call "explosion"}}
				{if rand 0.15 {call "_burn"}}
			else bullet "big shell"
				{if rand 0.20 {call "explosion"}}
				{if rand 0.10 {call "_burn"}}
			else bullet "small shell az"
		  		{if rand 0.05 {call "explosion"}}
				{if rand 0.54 {call "_burn"}}
			else bullet "shell20 az"
		  		{if rand 0.01 {call "explosion"}}
				{if rand 0.34 {call "_burn"}}
			else bullet "small shell"
				{if rand 0.20 {call "explosion"}}
;				{if rand 0.05 {call "_burn"}}
			else bullet "rpg shell"
	  		{if rand 0.20
	  			{call "explosion"}
	  		}
	  		{if rand 0.30
	  			{call "_burn"}
	  		}
			else bullet "shell"
			 	{if rand 0.15 {call "explosion"}}
;				{if rand 0.10 {call "_burn"}}
			}
		}

{if volume "crew"
{if bullet "bomb big shell"
{if rand 0.30 {kill_crew "driver"}}
{if rand 0.60 {kill_crew "gunner"}}
{if rand 0.60 {kill_crew "charger"}}

else bullet "extra big shell"
{if rand 0.20 {kill_crew "driver"}}
{if rand 0.50 {kill_crew "gunner"}}
{if rand 0.50 {kill_crew "charger"}}
{if rand 0.50 {kill_crew "commander"}}

else bullet "big shell"
{if rand 0.10 {kill_crew "driver"}}
{if rand 0.30 {kill_crew "gunner"}}
{if rand 0.30 {kill_crew "charger"}}
{if rand 0.30 {kill_crew "commander"}}

else bullet "small shell"
{if rand 0.02 {kill_crew "driver"}}
{if rand 0.12 {kill_crew "gunner"}}
{if rand 0.12 {kill_crew "charger"}}
{if rand 0.12 {kill_crew "commander"}}

else bullet "rpg shell"
{if rand 0.60 {kill_crew "driver"}}
{if rand 0.60 {kill_crew "gunner"}}
{if rand 0.60 {kill_crew "charger"}}
{if rand 0.60 {kill_crew "commander"}}
{if rand 0.30 {call "tank_kill"}}

else bullet "zenite ap"
{if rand 0.01 {kill_crew "driver"}}
{if rand 0.01 {kill_crew "gunner"}}
{if rand 0.01 {kill_crew "charger"}}
{if rand 0.01 {kill_crew "commander"}}

else bullet "shell20 az"
{if rand 0.03 {kill_crew "driver"}}
{if rand 0.03 {kill_crew "gunner"}}
{if rand 0.03 {kill_crew "charger"}}
{if rand 0.03 {kill_crew "commander"}}
else bullet "small shell az"
{if rand 0.15 {kill_crew "driver"}}
{if rand 0.14 {kill_crew "gunner"}}
{if rand 0.14 {kill_crew "charger"}}
{if rand 0.11 {kill_crew "commander"}}

else bullet "shell"
{if rand 0.20 {kill_crew "driver"}}
{if rand 0.20 {kill_crew "gunner"}}
{if rand 0.20 {kill_crew "charger"}}
{if rand 0.20 {kill_crew "commander"}}

  }
}

}
; ----- Обработка воздействия ударной волны
	{on blast
	{if volume "body"
			{if min_energy 16
				{call "tank_kill"}
					{kill_crew}
					{if rand 0.15 {call "explosion"}}
					{if rand 0.30 {call "_burn"}}
					{able select 0}
			else min_energy 13
				{if rand 0.15
				{call "tank_kill"}
					{if rand 0.30 {kill_crew "driver"}}
					{if rand 0.30 {kill_crew "gunner"}}
					{if rand 0.30 {kill_crew "charger"}}
					{if rand 0.30 {kill_crew "commander"}}
					{if rand 0.30
						{call "_burn"}
					}
				}
				{if rand 0.20
						{call "_burn"}
				}
				{components "track" disable work}
			}
	}

		{if volume "engine"
			{if min_energy 3.3
				{if effector "grenade"
					{components "engine" disable work}
					{if rand 0.40
							{call "_burn"}
					}
					{if rand 0.10
						{call "tank_kill"}
					}
				}
			else min_energy 1.2
				{if effector "grenade"
					{if rand 0.60
						{components "engine" disable work}
					}
				}
			}
		}

		{if volume "track"
;			{if min_energy 19
;				{call "tank_kill"}
;					{kill_crew}
;					{if rand 0.15 {call "explosion"}}
;					{if rand 0.30 {call "_burn"}}
;					{able select 0}
;			}

			{if min_energy 10
				{if rand 0.50
					{component disable work}
				}
			else min_energy 9
				{if rand 0.35
					{component disable work}
				}
			else min_energy 8
				{if rand 0.25
					{component disable work}
				}
			else min_energy 5
				{if rand 0.10
					{component disable work}
				}
			}
		}
	}
}
{"self_propelled tank"
	{on "blast_track" overload
		{if min_energy 4
			{component disable work}
		}
	}
{on spawn
  {call "update_gunvert"}
 }
 {on break
  {if component "body"
   {call "update_gunvert"}
  }
 }
 {on repair
  {if component "body"
   ;{view stop "smoke4"}
   {call "update_gunvert"}
  }
 }
 {on "update_gunvert"
  {if work "body"
   {ik_enable "gun_vert" 1} ;
   {ik_enable "rot_vert" 1} ; jugdpanther
   {ik_enable "gun_rot" 1}
   {ik_enable "gun_rot1" 1}
   {ik_enable "gun_rot2" 1}
   else
   {ik_enable "gun_vert" 0}
   {ik_enable "rot_vert" 0}
   {ik_enable "gun_rot" 0}
   {ik_enable "gun_rot1" 0}
   {ik_enable "gun_rot2" 0}

  }
 }
}

; -----   Описание конкретных танков  -----------------------------

{"mine_exploder"
	{blast_absorption 6}
	{on spawn
		{bone hide "wheel_work"}
		{add_view "dustrun_sand_big"	"wheel_work_dust"	"FXWheel_Work1"}
		{add_view "dustrun_sand_big"	"wheel_work_dust"	"FXWheel_Work2"}
		{volumes "wheel_work" disable all}
	}
	{on move on
		{bone hide "wheel"}
		{bone show "wheel_work"}
		{view start "wheel_work_dust"}
		{volumes "wheel_work" enable all}
		{volumes "wheel" disable all}
	}
	{on move off
		{bone hide "wheel_work"}
		{bone show "wheel"}
		{ani_play "wheel_stop"}
		{view pause "wheel_work_dust"}
		{volumes "wheel_work" disable all}
		{volumes "wheel" enable all}
	}
	{on "explosion"
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{set "sinking" 1}
		}
	}
	{on blast overload
		{if not volume "wheel_work"
			{inherited}
		else
			{ani_play "explosion"}
		}
	}
}

{"PZ-1B tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{link_sound "rotate_turret" "turret.lturret00"	}
                {link_sound "move"				"tracks.pz2_move"	}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
}
{"pzjager"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz2_move"	}
		{link_sound "engine"			"engine.sd232"		}
		{link_sound "engine_end"		"engine.sd232_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd232_up"	}
	}
}

{"bison"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz2_move"	}
		{link_sound "engine"			"engine.sd232"		}
		{link_sound "engine_end"		"engine.sd232_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd232_up"	}
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

{"t-60 tank"
	{on "add_movement_sound" overload
		{link_sound "engine"			"engine.t26"		}
		{link_sound "engine_end"		"engine.t26_end"	}
		{link_sound "exhaust"			"engine.t26_up"		}
		{link_sound "rotate_turret" 	"turret.lturret00"	}
	}
}
{"t-70 tank"
	{on "add_movement_sound" overload
		{link_sound "engine"			"engine.t26"		}
		{link_sound "engine_end"		"engine.t26_end"	}
		{link_sound "exhaust"			"engine.t26_up"		}
		{link_sound "rotate_turret" 	"turret.t34"	}
	}
}
{"su76m tank"
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
{"KV-8 tank"
	("kv_sound")
}
{"KV-1E tank"
	("kv_sound")
}
{"KV-2 tank"
	("kv_sound")
}
{"KV-2_42 tank"
	("kv_sound")
}
{"KV-85 tank"
	("kv_sound")
}
{"IS-2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.is_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.isu"		}
		{link_sound "engine_end"		"engine.isu_end"	}
		{link_sound "exhaust"			"engine.isu_up"		}
	}
}
{"isu-122 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.is_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.isu"		}
		{link_sound "engine_end"		"engine.isu_end"	}
		{link_sound "exhaust"			"engine.isu_up"		}
	}
}
{"isu-152 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.is_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.isu"		}
		{link_sound "engine_end"		"engine.isu_end"	}
		{link_sound "exhaust"			"engine.isu_up"		}
	}
}
(define "t34_sound"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t34_move"	}
		{link_sound "rotate_turret" 		"turret.t34"		}
		{link_sound "engine"			"engine.t34"		}
		{link_sound "engine_end"		"engine.t34_end"	}
		{link_sound "exhaust"			"engine.t34_up"		}
	}
)

{"IS-1 tank"
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
{"T-34-76-40 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t34_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t34"		}
		{link_sound "engine_end"		"engine.t34_end"	}
		{link_sound "exhaust"			"engine.t34_up"		}
	}
}
{"T-34-76-43 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t34_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t34"		}
		{link_sound "engine_end"		"engine.t34_end"	}
		{link_sound "exhaust"			"engine.t34_up"		}
	}
}
{"T-34-57 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t34_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t34"		}
		{link_sound "engine_end"		"engine.t34_end"	}
		{link_sound "exhaust"			"engine.t34_up"		}
	}
}
{"T-34-f38 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t34_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t34"		}
		{link_sound "engine_end"		"engine.t34_end"	}
		{link_sound "exhaust"			"engine.t34_up"		}
	}
}
{"su-85 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.tank_move"	}
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
{"t-34-85-ot tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.t3485_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t3485"		}
		{link_sound "engine_end"		"engine.t3485_end"	}
		{link_sound "exhaust"			"engine.t3485_up"	}
	}
}
{"SU-100 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.tank_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t3485"		}
		{link_sound "engine_end"		"engine.t3485_end"	}
		{link_sound "exhaust"			"engine.t3485_up"	}
	}
}
{"SU-122 tank"
	{on "add_movement_sound" overload
		{link_sound "move01"			"tracks.tank_move"	}
		{link_sound "rotate_turret" 	"turret.t34"		}
		{link_sound "engine"			"engine.t3485"		}
		{link_sound "engine_end"		"engine.t3485_end"	}
		{link_sound "exhaust"			"engine.t3485_up"	}
	}
}
{"PZ-5 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.tank_move"	}
		{link_sound "engine"			"engine.panther"		}
		{link_sound "engine_end"		"engine.panther_end"	}
		{link_sound "exhaust"			"engine.panther_up"	}
	}
}
{"pz-5a tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.tank_move"	}
		{link_sound "rotate_turret" 		"turret.hturret2"		}
		{link_sound "engine"			"engine.panther"	}
		{link_sound "engine_end"		"engine.panther_end"	}
		{link_sound "exhaust"			"engine.panther_up"	}
	}
}
{"Ferdinand tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.heavy_move"	}
		{link_sound "engine"			"engine.ferdi"		}
		{link_sound "engine_end"		"engine.ferdi_end"	}
		{link_sound "rotate_turret" 	"turret.hturret1"	}
		{link_sound "exhaust"			"engine.ferdi_up"	}
	}
}
{"m26Pershing"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.heavy_move"	}
		{link_sound "engine"			"engine.persch"		}
		{link_sound "engine_end"		"engine.persch_end"	}
		{link_sound "rotate_turret" 	"turret.hturret5"	}
		{link_sound "exhaust"			"engine.persch_up"	}
	}
}
{"M45"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.heavy_move"	}
		{link_sound "engine"			"engine.persch"		}
		{link_sound "engine_end"		"engine.persch_end"	}
		{link_sound "rotate_turret" 	"turret.hturret6"	}
		{link_sound "exhaust"			"engine.persch_up"	}
	}
}
{"super_pershing"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.heavy_move"	}
		{link_sound "engine"			"engine.persch"		}
		{link_sound "engine_end"		"engine.persch_end"	}
		{link_sound "rotate_turret" 	"turret.hturret6"	}
		{link_sound "exhaust"			"engine.persch_up"	}
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
{"comet tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"tracks.crmwll_move"}
		{link_sound "engine"			"engine.m4"		}
		{link_sound "engine_end"		"engine.crmwll_end"	}
		{link_sound "exhaust"			"engine.crmwll_up"	}
		{link_sound "rotate_turret" 	"turret.hturret2"	}
	}
}
{"Star tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"tracks.crmwll_move"}
		{link_sound "engine"			"engine.crmwll"		}
		{link_sound "engine_end"		"engine.crmwll_end"	}
		{link_sound "exhaust"			"engine.crmwll_up"	}
		{link_sound "rotate_turret" 	"turret.hturret2"	}
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
{"M4A3e2 tank"
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
{"priest_kangaroo"
	{on "add_movement_sound" overload
		{link_sound "move"					"tracks.m7_move"}
		{link_sound "engine"				"engine.m7"		}
		{link_sound "engine_end"			"engine.m7_end"	}
		{link_sound "exhaust"				"engine.m7_up"	}
		{link_sound "rotate_turret" 	   "turret.hturret1"}
	}
}
{"m3"
	{on "add_movement_sound" overload
		{link_sound "move"					"tracks.m7_move"}
		{link_sound "engine"				"engine.m7"		}
		{link_sound "engine_end"			"engine.m7_end"	}
		{link_sound "exhaust"				"engine.m7_up"	}
		{link_sound "rotate_turret" 	   "turret.hturret1"}
	}
}
{"m3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.m7_move"	}
		{link_sound "engine"			"engine.m7"		}
		{link_sound "engine_end"		"engine.m7_end"		}
		{link_sound "exhaust"			"engine.m7_up"		}
		{link_sound "rotate_turret" 		"turret.hturret1"	}
	}
	{on fire "gun2"
		{spawn "tank_canon_fire" "Foresight4" x}
		{ani_play "fire2"}
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
	       ;{link_sound "move"				"tracks.heavy_move"	}
		{link_sound "engine"			"engine.pz6"		}
		{link_sound "engine_end"		"engine.pz6_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz6_up"	}
	}
)
{"PZ-6 tank"
	("PZ6_sound")
}
{"pz-6_42 tank"
	("PZ6_sound")
}
{"PZ-6b tank"
	("PZ6_sound")
}
{"PZ-6e tank"
	("PZ6_sound")
}
{"jagdtiger"
	("PZ6_sound")
}
{"maus tank"
	{on "add_movement_sound" overload
		{link_sound "move"				 "tracks.jdp_move"  }
		{link_sound "engine"				"engine.jdp"	}
		{link_sound "engine_end"		"engine.jdp_end"	}
		{link_sound "exhaust"			"engine.jdp_up" 	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
	}
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
{"ba-64 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.move"			}
		{link_sound "move_end"		"wheels.move_end"		}
		{link_sound "engine"		"engine.car"			}
		{link_sound "engine_end"	"engine.car_end"		}
		{link_sound "exhaust"		"engine.car_up"			}
	}
}
{"ba-64m tank"
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
{"type93 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.wheels_rot"	}
		{link_sound "engine"			"engine.ba20"		}
		{link_sound "engine_end"		"engine.ba20_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.ba20_up"	}
	}
}
{"wz-34 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot"	}
		{link_sound "engine"			"engine.ba20"		}
		{link_sound "engine_end"		"engine.ba20_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.ba20_up"	}
	}
}
{"BA-6 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot"	}
		{link_sound "engine"			"engine.ba20"		}
		{link_sound "engine_end"		"engine.ba20_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.ba20_up"	}
	}
}
{"BA-11 tank"
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
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.pz2_up" 	}
	}
}
(define "pz3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 		"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
)
{"pz-3g tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"pz-3j tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"pz-3h tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"pz-3f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"pz-3l tank"
	("pz3_sound")
}
{"pz-3N tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"hetzer tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.pz38"		}
		{link_sound "engine_end"		"engine.pz38_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz38_up" 	}
	}
}
{"pz38tC tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.hetzer"		}
		{link_sound "engine_end"		"engine.pz38_end"	}
		{link_sound "rotate_turret" 	"turret.hturret2"	}
		{link_sound "exhaust"			"engine.pz38_up" 	}
	}
}
{"marder tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.pz3_move"	}
		{link_sound "engine"			"engine.hetzer"		}
		{link_sound "engine_end"		"engine.pz38_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz38_up" 	}
	}
}
{"stug-3b tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.tank_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"stug-3f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.tank_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"stug-4g tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.tank_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 	"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
}
{"STUH42 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.tank_move"	}
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
{"pz-4f2 tank"
	("pz4_sound")
}
{"pz-4H tank"
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
{"sdkfz-222 tank"
	("sdkfz_sound")
}
{"sdkfz-222e tank"
	("sdkfz_sound")
}
{"sdkfz7_88 tank"
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
{"sdkfz263 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd234_move"	}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"sdkfz231 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd234_move"	}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"sdkfz232 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd234_move"	}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"m8grayhound tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.sd234_move"	}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"mk2daimler tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot1"}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"panhard tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot1"}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"Humber tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot1"}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"Rolls_Royce"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot1"}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
	{on break
		{bone cut "lamp_glass1"}
		{bone cut "lamp_light_spot1"}
		{bone cut "lamp_glass2"}
		{bone cut "lamp_light_spot2"}
	}
}
{"Stag_Hound tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"wheels.wheels_rot1"}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "rotate_turret" 	"turret.flak"	}
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
{"SdKfz250_1 tank"
	("hanomag_sound")
}
{"SdKfz251_22 tank"
	("hanomag_sound")
}
{"panzerwerfer42 tank"
	("hanomag_sound")
}
{"SdKfz251_2 tank"
    {on fire "gun" overload
       {spawn "dust_shot_small" "basis"}
    }
("hanomag_sound")
}
{"sdkfz10-5 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd10_move"	}
		{link_sound "engine"			"engine.sd10"		}
		{link_sound "engine_end"		"engine.sd10_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.sd10_up"	}
	}
}
{"m3a1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"m3a1-LL tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"m21"
        {on fire "gun" overload
                {spawn "dust_shot_small" "basis"}
        }
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"m21-LL"
        {on fire "gun" overload
                {spawn "dust_shot_small" "basis"}
        }
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"T73 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "rotate_turret" 	"turret.lturret01"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"T48 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"T19 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.m3a1"		}
		{link_sound "engine_end"		"engine.m3a1_end"	}
		{link_sound "rotate_turret" 		"turret.lturret01"	}
		{link_sound "exhaust"			"engine.m3a1_up"	}
	}
}
{"te-ke tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.pz2_move"	}
		{link_sound "engine"			"engine.lightjap"	}
		{link_sound "engine_end"		"engine.lightjap_end"	}
		{link_sound "exhaust"			"engine.lightjap_up"	}
	}
}
{"ha-go tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.lightjap"	}
		{link_sound "engine_end"		"engine.lightjap_end"	}
		{link_sound "exhaust"			"engine.lightjap_up"	}
	}
}
{"ke-nu tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.lightjap"	}
		{link_sound "engine_end"		"engine.lightjap_end"	}
		{link_sound "exhaust"			"engine.lightjap_up"	}
	}
}
(define "chi-ha_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.m3a1_move"	}
		{link_sound "engine"			"engine.pz38"		}
		{link_sound "engine_end"		"engine.pz38_end"	}
		{link_sound "rotate_turret" 		"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz38_up" 	}
	}
)
{"chi-ha47 tank"
	("chi-ha_sound")
}
{"chi-ha57 tank"
	("chi-ha_sound")
}
{"chi-ha120 tank"
	("chi-ha_sound")
}
{"ho-ni1 tank"
	("chi-ha_sound")
}
{"ho-ni2 tank"
	("chi-ha_sound")
}
{"ho-ro tank"
	("chi-ha_sound")
}
{"t-20 tank"
	("chi-ha_sound")
}
(define "ho-i_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.tank_move"	}
		{link_sound "engine"			"engine.pz3"		}
		{link_sound "engine_end"		"engine.pz3_end"	}
		{link_sound "rotate_turret" 		"turret.hturret3"	}
		{link_sound "exhaust"			"engine.pz3_up" 	}
	}
)
{"ho-i tank"
	("ho-i_sound")
}
{"chi-he tank"
	("ho-i_sound")
}
{"chi-nu tank"
	("ho-i_sound")
}
{"ho-ri tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.jdp_move"	}
		{link_sound "engine"			"engine.jdp"		}
		{link_sound "engine_end"		"engine.jdp_end"	}
		{link_sound "exhaust"			"engine.jdp_up" 	}
	}
	{on fire "gun2"
		{spawn "tank_canon_fire" "Foresight2" x}
        }
}
{"chi-ri tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.jdp_move"	}
		{link_sound "engine"			"engine.jdp"		}
		{link_sound "engine_end"		"engine.jdp_end"	}
		{link_sound "exhaust"			"engine.jdp_up" 	}
		{link_sound "rotate_turret" 		"turret.hturret6"	}
	}
	{on fire "gun2"
		{spawn "tank_canon_fire" "Foresight2" x}
        }
	{on fire "mgun3"
		{spawn "flash_gun_big" "Foresight4" x}
	}
}
{"CharB1bis tank"
	{on fire "gun2"
		{spawn "tank_canon_fire" "Foresight2" x}
		{ani_play "fire"}
        }
}
{"m18_hellcat tank"
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
	{on operatable on
		{ani_play "open" -1.0 resume}
		{call "update_lights"}
	}
	{on operatable off
		{ani_play "open" +1.0 resume}
		{call "update_lights"}
	}
}
{"t29 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.t29_move"	}
		{link_sound "engine"			"engine.t29"		}
		{link_sound "engine_end"		"engine.t29_end"	}
		{link_sound "exhaust"			"engine.t29_up" 	}
		{link_sound "rotate_turret" 		"turret.turret_t29"	}
	}
	{on fire "mgun3"
		{spawn "flash_gun_small" "Foresight4" x}
	}
}
{"a39 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on "add_movement_sound" overload
		{link_sound "move"			"tracks.a39_move"	}
		{link_sound "engine"			"engine.a39"		}
		{link_sound "engine_end"		"engine.a39_end"	}
		{link_sound "exhaust"			"engine.a39_up" 	}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
}
{"steyr tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd250_move"	}
		{link_sound "engine"			"engine.sd250"		}
		{link_sound "engine_end"		"engine.sd250_end"	}
		{link_sound "exhaust"			"engine.sd250_up"	}
	}
}
{"m3a1scout tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd234_move"	}
		{link_sound "engine"			"engine.sd234"		}
		{link_sound "engine_end"		"engine.sd234_end"	}
		{link_sound "exhaust"			"engine.sd234_up"	}
	}
}
{"ho-ki tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.sd250_move"	}
		{link_sound "engine"			"engine.sd250"		}
		{link_sound "engine_end"		"engine.sd250_end"	}
		{link_sound "exhaust"			"engine.sd250_up"	}
	}
}
{"t-70 tank"
	{on "add_movement_sound" overload
                {link_sound "move"			"tracks.t34_move"	}
		{link_sound "engine"			"engine.t26"		}
		{link_sound "engine_end"		"engine.t26_end"	}
		{link_sound "exhaust"			"engine.t26_up"		}
		{link_sound "rotate_turret" 		"turret.t34"		}
	}
}
{"su76m tank"
	{on "add_movement_sound" overload
                {link_sound "move"			"tracks.t34_move"	}
		{link_sound "engine"			"engine.t26"		}
		{link_sound "engine_end"		"engine.t26_end"	}
		{link_sound "exhaust"			"engine.t26_up"		}
		{link_sound "rotate_turret" 		"turret.t34"		}
	}
}
{"guncarrier tank"
        {on fire "gun" overload
                {spawn "dust_shot_small" "basis"}
        }
}
