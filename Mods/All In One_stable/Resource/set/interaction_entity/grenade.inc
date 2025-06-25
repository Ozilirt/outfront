{"grenade"
	{restitution 0.8}
}
{"grenade training"
	{on spawn
		{tags add "grenade"}
	}
}
{"grenade contact"
	{on ground_hit
		{if not name "water"
			{call "ground_detonate"}
		}
	}
	{on contact
                {if rand 1.00 {call "contact_detonate"}}
	}
	{on "ground_detonate"
       	        {if rand 0.65 {call "detonate"}}
	}
	{on "contact_detonate"
		{if rand 1.00 {call "detonate"}}
	}
	{on "detonate"
	        {if rand 1.00 {stuff_detonate}}
	}
}
{"grenade smoke"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "fire.smoke_grenade"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
;	{volumes disable touch select}
	}
	{on "activate"
		{play_sound "smoke" 1}
		{tags add "smoke"}
		{view stop "smoke1"}
		{view start "smoke2"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 1
			{view stop "smoke2"}
			{view start "smoke3"}
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 2
			{volumes "smoke2" disable visible}
			{volumes "smoke3" enable visible}
			{update_visibility_patch}
		}
		{delay 32
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 50
			{hide 1}
		}
	}
	{on ground_hit
		{if not "activated"
			{set "activated" 1}
			{if under_water
				{hide 1}
			else
				{delay 3
					{call "activate"}
				}
			}
		}
	}
	{on contact
		{if not "activated"
			{set "activated" 1}
			{delay 3
				{call "activate"}
			}
		}
	}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}
{"molotov_coctail"
	{on bullet_hit
		{fire radius 1.5 time 2 heating 6 effector}
		{call "detonate"}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 1.5 time 2 heating 6 effector}
			{call "detonate"}
		}
	}
	{on "ground_detonate"
		{fire radius 2 time 8}
	}
	{on "contact_detonate" overload
		{if effector "construction"

			{volumes disable bullet contact blast}
			{fire radius 1.5 time 2 heating 6 effector}
			{delay 0.1
				{call "detonate"}
		}
		else
			{if rand 0.75 
				{fire radius 1.5 time 3 heating 99 effector followowner}
			}
			{call "detonate"}
		}
	}
}
{"an_m14"
	{on bullet_hit
		{fire radius 3 time 1 heating 99 effector}
		{call "detonate"}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 3 time 1 heating 99 effector}
			{call "detonate"}
		}
	}
	{on "ground_detonate"
		{fire radius 4 time 1}
	}
	{on "contact_detonate" overload
		{if effector "construction"
			{volumes disable bullet contact blast}
			{fire radius 3 time 1 heating 99 effector}
			{delay 0.1
				{call "detonate"}
		}
		else
			{if rand 0.85 
				{fire radius 4 time 1 heating 1005 effector followowner}
			}
			{call "detonate"}
		}
	}
}