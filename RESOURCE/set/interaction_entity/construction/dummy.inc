{"antitank_hedgehog"
	{on bullet_hit
		{bullet_detonate}
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
		{if bullet "shell fg"
			{bullet_detonate}
		}
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
;			{call "_burn"}
		}
	}
	{on "crush"
		{volumes disable visible bullet contact blast}
		{spawn "hay_hit_big" no_position}
		{spawn "hay_hit_big" "FX_haulm1"}
		{spawn "hay_hit_big" "FX_haulm2"}
		{set "fall" 1}
		{tex_morph "crushed" 0.1}
		{ani_play "crush" 1000 callback}
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
	{on "open"
;		{start_sound "engine.gate_open"}
	}
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

{"tent construction"
	{on bullet_hit
		{if not under_water
			{if bullet "bullet"
				{spawn "wood_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "zenite"
				{spawn "wood_hit_br"}
			else bullet "shell"
				{spawn "wood_hit_br"}
			else bullet "mortar"
				{spawn "wood_hit_br"}
			}
		}
	}
}

{"sand_bag"
	{on bullet_hit
		{if bullet "bullet"
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
	{on blast_hit
		{if min_energy 0.5
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

{"showcase"
	{on "break_window"
		{area disable}
	}
}
