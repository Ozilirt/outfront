{"antitank_hedgehog"
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
			{bullet_detonate}
		}

	}
	{on blast_hit
		{if min_energy 14
			{delay 0.2 {delete}}
		}
	}
	{on contact
		{if effector "tank"
			{if min_speed 2
				{spawn "metal_crush" "root"}
			}
		}
	}
}

{"firewood"
	{inflammation_time 10}
	{blast_absorption 10}
	{on bullet_hit
	}
	{on blast_hit
		{if min_energy 5
			{call "break"}
		}
	}
	{on contact
		{if effector "tank"
			{if min_speed 10
				{volumes disable contact}
				{call "break"}
			}
		}
	}
	{on "break"
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
			}
		}
	}
}

{"stack"
	{inflammation_time 0.3}
	{on bullet_hit
		{if bullet "shell"
			{spawn "hay_hit_norm"}
		else bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else bullet "bullet"
			{if rand 0.2
				{spawn "hay_hit_small2"}
			}
		}
	}
	{on blast_hit
		{if min_energy 0.3
			{call "crush"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable visible bullet contact blast}
		{call "crush_fx"}
		{set "fall" 1}
		{tex_morph "crushed" 0.1}
		{ani_play "crush" 10 callback}
	}
	{on "burn_volume"
		{if not burned
			{if volume "fire"
				{call "_burn"}
			}
		}
	}
	{on "_burn"
		{volumes disable visible bullet contact blast}
		{burn volume "fire0" fx "smoke_dead_norm" time 15 even_law}
		{burn volume "fire1" fx "smoke_dead_tree1" time 10 even_law}
		{tex_morph "burned" 8}
		{delay 6.0
			{spawn "destroy_shellhole1"}
			{if not "fall"
				{set "fall" 1}
				{ani_play "crush" callback}
			}
		}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
		{area disable}
	}
	{on "crush_fx"
		{spawn "hay_hit_big" no_position}
		{spawn "hay_hit_big" "FX_haulm1"}
		{spawn "hay_hit_big" "FX_haulm2"}
	}
}

{"stack tent"
	{on "crush_fx" overload}
	{on bullet_hit overload
		{if not under_water
			{if bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			else bullet "bullet"
				{spawn "spheredust_small_short"}
			else bullet "zenite"
				{spawn "spheredust_small_short"}
			else bullet "shell"
				{spawn "spheredust_small_short"}
			else bullet "mortar"
				{spawn "spheredust_small_short"}
			}
		}
	}
}

{"gate"
	{on spawn
		{call "update_area"}
	}
	{on "open"
		{if not "user_opened"
			{set "opened" 1}
			{ani_play "open" resume callback}
			{call "update_area"}
		}
	}
	{on "close"
		{if not "user_opened"
			{set "opened" 0}
			{ani_play "open" -1 resume}
			{call "update_area"}
			{tags remove "opened"}
		}
	}
	{on animation_end "open"
		{tags add "opened"}
	}
	{on "update_area"
		{if "opened"
			{area disable	"close"}
			{area enable	"left"}
			{area enable	"right"}
		else
			{area enable	"close"}
			{area disable	"left"}
			{area disable	"right"}
		}
	}
}

{"gate door_big"
	{on "open"
		{start_sound "engine.gate_open"}
	}
}

{"gate lock"
	{on bullet_hit
		{if volume "lock"
			{if not "opened"
				{call "open"}
				{set "user_opened" 1}
				{delay_ex 0
					{tear "piece_small_steel" bone "lock"
						{impulse up -1 0.7 dir 2.5 0.3 no_position}
					}
				}
			}
		}
	}
}

{"sand_bag"
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else bullet "bullet"
			{spawn "ex_air_sm"}
			{bullet_detonate}
		else bullet "shell"
			{spawn "sand_hit_small"}
			{bullet_detonate}
		}
	}
	{on contact
		{if volume "body"
			{if effector "tank"
				{if min_speed 1
					{volumes disable contact}
					{delay 0
						{call "crush"}
					}
				}
			}
		}
	}
	{on "crush"
		{if not "crushed"
			{set "crushed" 1}
			{set_skeleton "_x"}
			{ani_play "crush1" callback}
			{call "update_fx"}
			{call "effects"}
		}
	}
	{on animation_end "crush1"
		{ani_play "crush2"}
	}
}

{"sand_bag_small"
	{blast_absorption 1.0}
	{on blast_hit
		{if min_energy 1.5
			{spawn "sand_hit_small"}
			{delete}
		}
	}
	{on contact
		{if effector "vehicle"
			{volumes disable contact}
			{spawn "sand_hit_small"}
			{delete}
		}
	}
}

{"sand_bag_big"
	{blast_absorption 3.8}
	{on blast_hit
		{if min_energy 4.0
			{spawn "wood_crush_big"}
			{delete}
		}
	}
	{on contact
		{if effector "vehicle"
			{volumes disable contact}
			{spawn "wood_crush_big"}
			{delete}
		}
	}
}

{"showcase"
	{on "break_window"
		{area disable}
	}
}

{"fountain_small"
	{on spawn
		{add_view "drops_water_small_long" "water" "FX_water"}
		{view start "water"}
	}
}

{"steam_small"
	{on spawn
		{add_view "steam" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}
{"metall"
	{on bullet_hit
		{if bullet "shell"
			{spawn "metal_hit_br_small"}
		else bullet "rifle"
			{spawn "metal_hit_bul"}
		else bullet "mgun"
			{spawn "metal_hit_bul"}
		else bullet "smg"
			{spawn "metal_hit_bul"}
		else bullet "pistol"
			{spawn "metal_hit_bul"}
		}
	}
}
{"oil_rig"
	(define "play_pump"
		{delay %0
			{if rand 0.5
				{ani_play "pump" 0.8 loop}
			else
				{ani_play "pump" 1.0 loop}
			}
		}
	)
	{on spawn
		{if rand 0.05
			{ani_play "pump" 0.7 loop}
		else rand 0.05
			("play_pump" args 9)
		else rand 0.05
			("play_pump" args 3)
		else rand 0.05
			("play_pump" args 4)
		else rand 0.05
			("play_pump" args 6)
		else rand 0.05
			("play_pump" args 1)
		else rand 0.05
			("play_pump" args 7)
		else rand 0.05
			("play_pump" args 2)
		else rand 0.05
			("play_pump" args 4)
		else rand 0.05
			("play_pump" args 5)
		else rand 0.05
			("play_pump" args 1)
		else rand 0.05
			("play_pump" args 10)
		else rand 0.05
			("play_pump" args 3)
		else rand 0.05
			("play_pump" args 5)
		else
			("play_pump" args 4)
		}
	}
}

