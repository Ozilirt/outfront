{"cannon"
	{blast_absorption 3.0}
	{on spawn
		{add_view	"human_linked_selection" "linked_selection" "visor"}
	}

	{on pierce
		{if volume "wheel"
			{if bullet "zenite"
				{if rand 0.30
					{components "wheel" disable work}
				}
			}
		}

	}

	{on bullet_hit
		{if bullet "big shell bomb"
				{call "explosion"}
			else bullet "big shell extra"
				{call "explosion"}

			else bullet "big shell ap"
				{if rand 0.30
					{components "gun" disable work repair}
				}
				{if rand 0.30
					{components "body" disable work repair}
				}
			else bullet "big shell fg"
				{call "explosion"}

			else bullet "small shell ap"
				{if rand 0.20
					{components "gun" disable work repair}
				}
			else bullet "small shell az"
				{if rand 0.25
					{components "gun" disable work repair}
				}
			else bullet "shell20 az"
				{if rand 0.15
					{components "gun" disable work repair}
				}
			else bullet "small shell fg"
				{if rand 0.60
					{components "gun" disable work repair}
					{components "body" disable work repair}
				}
				{if rand 0.15
						{kill_crew "gunner"}
				}
				{if rand 0.15
					{kill_crew "commander"}
				}
				{if rand 0.15
					{kill_crew "charger"}
				}
				{if rand 0.15
					{kill_crew "driver"}
				}
			else bullet "rpg"
				{call "explosion"}

			else bullet "shell fg"
				{call "explosion"}
			else bullet "shell ap"
				{if rand 0.20
					{components "gun" disable work repair}
				}
				{if rand 0.20
					{components "body" disable work repair}
				}
		}
	}

	{on blast
		{if min_energy  8
				{impulse up 1 0.3 dir 0.8 0.2}
				{call "explosion"}
			else min_energy 3.0
				{impulse up 0.5 0.3 dir 0.4 0.2}
				{call "explosion"}
			else min_energy 2.2
				{impulse up 0.4 0.4 dir 0.3 0.1}
					{components "gun" disable work repair}
					{components "body" disable work repair}
			else min_energy 0.6
			 	{ani_play "hit"}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		{delay 14 {view stop "deathfx"}}
	}
	{on fire "gun"
		{ani_play "recoil"}
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{delay 0.15
			{view pause "flashbarrel1"}
		}
		{delay 0.3
			{view pause "flashbarrel1s"}
		}
		{call "shot_blastwave"}
	}
	{on "shot_blastwave"
		{blastwave c4 0.2 r0 1 r1 1.5 bone "Foresight1"}
	}
	{on contact
		{if not impregnable
			{if effector_velocity 5
				{if effector "tank"
					{component disable work repair}
					{if volume "body"
						{set "crush" 1}
						{call "explosion"}
					}
				}
			else effector_velocity 3
				{if effector "big part"
					{component disable work}
				}
			}
		}
	}
	{on "update_obstacle"
		{if operatable
			{change_obstacle "operatable"}
		else
			{change_obstacle "empty"}
		}
	}
}

{"heavy cannon"
	{on spawn
		{add_view	"flash_cannon_medium"	"flashbarrel1"	"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
	}
}

{"medium cannon"
	{on spawn
		{add_view	"flash_cannon_small"	"flashbarrel1"	"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
}

{"mortar"
	{on spawn overload
		{link_sound "rotate_turret" "turret.mortar"}
		{link_sound "rotate_gun" "turret.flak"}

		{add_view	"flash_cannon_big"		"flashbarrel1"	"Foresight1"}
		{add_view	"spheredust_big_long"	"dust"			"turret"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
        {spawn "canon_gaub_fire" "Foresight1" x}
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
       	{view start "dust"}
		{delay 1
			{view pause "dust"}
		}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{blastwave c4 0.6 r0 3 r1 5 bone "Foresight1" offset 40 0 0}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		{delay 14 {view stop "deathfx"}}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on blast_hit overload
		{if min_energy 12
			{impulse up 0.5 0.2 dir 0.3 0.1}
			{call "explosion"}
		 else min_energy 0.6
		 	{ani_play "hit"}
		}
	}

}

{"flak"
	{on spawn overload
		{link_sound "rotate_turret" "turret.flak"}

		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
		{add_view "flash_zenit"			"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"			"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"			"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"			"flashbarrel03"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{add_view "circledust_norm3"	"dust"			"basis"}
		{call "update_gun"}

		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}

		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{if rand 0.3
			{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1" offset 30 0 0}
		}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}
	}
}
{"flak barrel1"
	{on fire "gun" overload
		{view start "flashbarrel00"}
		{delay 0.42
			{view pause "flashbarrel00"}
		}
		{ani_play "fire00"}
		{delay 0.12
			{view start "smoke00"}
			{delay 5
				{view pause "smoke00"}
			}
		}
		{call "fire_gun_common"}
	}
}
{"flak4_tank" ;gun mounted on car or tank
	{on spawn

		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
		{add_view "flash_zenit"			"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"			"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"			"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"			"flashbarrel03"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{add_view "circledust_norm3"	"dust"			"basis"}
		{call "update_gun"}

		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}

		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{if rand 0.3
			{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1" offset 30 0 0}
		}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}
	}
}
{"dualmgun" ;mgun mounted on t29
	{on spawn
		{add_view "light_flash_zenit"		"flashbarrel"		"foresight3"}
		{add_view "flash_gun_small"		"flashbarrel00"		"shooter00"}
		{add_view "flash_gun_small"		"flashbarrel01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "circledust_norm3"		"dust"			"basis"}
		{call "update_gun"}

		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "mgun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}

		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{if rand 0.3
			{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight3" offset 30 0 0}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}
	}
}
{"50cal_tank" ;gun mounted on car or tank
	{on spawn

		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
		{add_view "flash_gun_small"			"flashbarrel00"	"shooter00"}
		{add_view "flash_gun_small"			"flashbarrel01"	"shooter01"}
		{add_view "flash_gun_small"			"flashbarrel02"	"shooter02"}
		{add_view "flash_gun_small"			"flashbarrel03"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{add_view "circledust_norm3"	"dust"			"basis"}
		{call "update_gun"}

		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}

		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{if rand 0.3
			{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1" offset 30 0 0}
		}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}
	}
}
{"flak barrel1"
	{on fire "gun" overload
		{view start "flashbarrel00"}
		{delay 0.42
			{view pause "flashbarrel00"}
		}
		{ani_play "fire00"}
		{delay 0.12
			{view start "smoke00"}
			{delay 5
				{view pause "smoke00"}
			}
		}
		{call "fire_gun_common"}
	}
}

{"small cannon"
	{on spawn overload
		{link_sound "rotate_turret" "turret.flak"}

		{add_view "light_flash_zenit"	"flashbarrel"	"foresight1"}
		{add_view "flash_zenit"			"flashbarrel1"	"foresight1"}
		{add_view "smoke_zenit"			"smoke"			"foresight1"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{call "update_gun"}

		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "gun" overload
		{view start "flashbarrel"}
		{view start "flashbarrel1"}
		{ani_play "fire"}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view start "smoke"}
			{delay 0.3
				{view pause "flashbarrel1"}
			}
			{delay 5
				{view pause "smoke"}
			}
		}
	}
}

{"nebelwerfer"
	{on "shot_blastwave" overload}
	{on fire "gun"
		{spawn "startsmoke_big"}
		{spawn "startdust_big" "FXdust"}
	}
}

{"zenite" ;gun mounted on car or tank
	{on spawn
		{add_view "light_flash_zenit"	"zenite_flash"	"foresight1"}
		{add_view "flash_zenit"			"zenite_flash"	"foresight1"}
		{add_view "smoke_zenit"			"zenite_smoke"	"foresight1"}
		{add_view "zenit_gilz"			"zenite_shell"	"FXshell1"}
		{add_view "circledust_norm3"	"zenite_dust"	"turret"}
	}
	{on fire "gun" overload
        {view start "zenite_flash"}
		{ani_play "fire"}
		{kill_delay "shell_off"}
		{view start "zenite_shell"}
		{view start "zenite_dust"}
		{delay 0.12 "shell_off"
			{view pause "zenite_shell"}
			{view pause "zenite_dust"}
			{view pause "zenite_dust"}
			{view start "zenite_smoke"}
			{delay 0.3
				{view pause "zenite_flash"}
			}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}
}

{"searchlight"
	{on spawn overload
		{if not sunlight
			{add_view "light_search" "light" "fxlight"}
			{bone hide "fxlight"}
		else
			{bone cut "fxlight"}
		}
		{if tagged "broken"
			{bone cut "lamp"}
		}
	}
	{on operatable on
		{call "update_light"}
	}
	{on operatable off
		{call "update_light"}
	}
	{on "update_light"
		{if not sunlight
			{kill_delay "update_light"}
			{delay 0 "update_light"
				{if operatable
					{bone show "fxlight"}
					{view start "light"}
				else
					{bone hide "fxlight"}
					{view stop "light"}
					{drop_orders}
   		 		}
			}
		}
	}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
			{if volume "lamp"
				{call "break_light"}
			}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.4
				{call "break_light"}
			}
		}
	}
	{on "break_light"
		{tags add "broken"}
		{drop_orders}
		{spawn "glass_hit" "lamp" x}
		{delay 0.1
			{bone cut "lamp"}
		}
	}
	{on "cut_pieces"
		{drop_orders}
	}
}
{"maxim_2"
	{on spawn
		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{add_view	"flash_gun_big"		"flashbarrel2"	"Foresight3"}
		{add_view 	"zenitmg_gilz"		"shell"		"FXshell1"}
	}
	{on fire "mgun"
		{view start "flashbarrel2"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view start "smoke"}
			{delay 0.3
				{view pause "flashbarrel2"}
			}
			{delay 5
				{view pause "smoke"}
			}
		}
	}
}
{"type92_stan"
	{on spawn
		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{add_view	"flash_gun_big"		"flashbarrel2"	"Foresight3"}
		{add_view 	"zenitmg_gilz"		"shell"		"FXshell1"}
	}
	{on fire "mgun"
		{view start "flashbarrel2"}
		{ani_play "fire"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view start "smoke"}
			{delay 0.3
				{view pause "flashbarrel2"}
			}
			{delay 5
				{view pause "smoke"}
			}
		}
	}
}
{"460mm"
	{on spawn overload
		{link_sound 	"rotate_turret" 	"turret.mortar"}
		{add_view 	"canon_gaub_fire"	"flashbarrel00"		"shooter00"}
		{add_view 	"canon_gaub_fire"	"flashbarrel01"		"shooter01"}
		{add_view 	"canon_gaub_fire"	"flashbarrel02"		"shooter02"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{view start "flashbarrel00"}
		{view start "flashbarrel01"}
		{view start "flashbarrel02"}
		{spawn "canon_gaub_fire" "shooter00" x}
		{spawn "canon_gaub_fire" "shooter01" x}
		{spawn "canon_gaub_fire" "shooter02" x}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		{delay 14 
			{view stop "deathfx"}
		}
	}
	{on ik begin "turret"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_gun"}
	}
	{on bullet_hit overload
	}
	{on blast overload
		{if volume "turret"
			{if effector "dynamite"
				{impulse up 1 0.3 dir 0.8 0.2}
				{call "explosion"}

			else min_energy 24
				{impulse up 1 0.3 dir 0.8 0.2}
				{call "explosion"}
			}
		}
	}
	{on contact overload
	}
}
{"155mm"
	{on spawn overload
		{link_sound 	"rotate_turret" 	"turret.mortar"}
		{add_view 	"tank_canon_fire1"	"flashbarrel00"		"shooter00"}
		{add_view 	"tank_canon_fire1"	"flashbarrel01"		"shooter01"}
		{add_view 	"tank_canon_fire1"	"flashbarrel02"		"shooter02"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{view start "flashbarrel00"}
		{view start "flashbarrel01"}
		{view start "flashbarrel02"}
		{spawn "tank_canon_fire1" "shooter00" x}
		{spawn "tank_canon_fire1" "shooter01" x}
		{spawn "tank_canon_fire1" "shooter02" x}
	}
	{on "cut_parts" overload
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		{delay 14 
			{view stop "deathfx"}
		}
	}
	{on ik begin "turret"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "turret"
		{stop_sound "rotate_gun"}
	}
	{on bullet_hit overload
		{if bullet "big shell bomb"
				{call "explosion"}
			else bullet "big shell ap"
				{if rand 0.35
					{components "gun" disable work repair}
					{components "turret" disable work repair}
				}
				{if rand 0.15
					{call "explosion"}	
				}
				{if rand 0.10
					{kill_crew "gunner"}
				}
				{if rand 0.10
					{kill_crew "commander"}
				}
		}
	}
	{on blast overload
		{if volume "turret"
			{if effector "dynamite"
				{impulse up 1 0.3 dir 0.8 0.2}
				{call "explosion"}
			else min_energy 24
				{impulse up 1 0.3 dir 0.8 0.2}
				{call "explosion"}
			}
		}
	}
	{on contact overload
	}
}
{"127mm"
	{on spawn overload
		{add_view 	"tank_canon_fire1"	"flashbarrel00"		"shooter00"}
		{add_view 	"tank_canon_fire1"	"flashbarrel01"		"shooter01"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{view start "flashbarrel00"}
		{view start "flashbarrel01"}
		{spawn "tank_canon_fire1" "shooter00" x}
		{spawn "tank_canon_fire1" "shooter01" x}
	}
	{on bullet_hit
		{if bullet "big shell bomb"
				{call "explosion"}
			else bullet "big shell extra"
				{call "explosion"}
			else bullet "big shell ap"
				{if rand 0.40
					{components "gun" disable work repair}
					{components "turret" disable work repair}
					{components "body" disable work repair}
				}
				{if rand 0.30
					{call "explosion"}	
				}
				{if rand 0.15
					{kill_crew "gunner"}
				}
				{if rand 0.15
					{kill_crew "commander"}
				}
			else bullet "big shell fg"
				{if rand 0.30
					{call "explosion"}	
				}
				{if rand 0.25
					{kill_crew "gunner"}
				}
				{if rand 0.25
					{kill_crew "commander"}
				}
			else bullet "small shell ap"
				{if rand 0.05
					{components "gun" disable work repair}
				}
			else bullet "small shell fg"
				{if rand 0.05
					{components "gun" disable work repair}
				}
				{if rand 0.05
					{components "body" disable work repair}
				}
				{if rand 0.05
					{components "turret" disable work repair}
				}
				{if rand 0.10
					{kill_crew "gunner"}
				}
				{if rand 0.10
					{kill_crew "commander"}
				}
			else bullet "shell fg"
				{if rand 0.08
					{components "gun" disable work repair}
				}
				{if rand 0.08
					{components "body" disable work repair}
				}
				{if rand 0.08
					{components "turret" disable work repair}
				}
			else bullet "shell ap"
				{if rand 0.15
					{components "gun" disable work repair}
				}
				{if rand 0.15
					{components "body" disable work repair}
				}
				{if rand 0.15
					{components "turret" disable work repair}
				}
		}
	}
	{on blast overload
		{if min_energy  19
				{impulse up 0.4 0.4 dir 0.3 0.1}
				{call "explosion"}
		}
	}
	{on contact overload
	}
}