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
{"oil_fire"
	{on spawn
		{add_view "smoke_camp_norm" "oilfire" "FXfire"}
		{view start "fire"}
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
