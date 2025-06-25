{"grenade"
	{restitution 0.3}
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
		{call "contact_detonate"}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate}
	}
}
{"grenade smoke"
	{on spawn
		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
		{view start "smoke1"}
		{delay 3
			{view start "smoke2"}
		}
	}
	{on "activate"
		{tags add "smoke"}
		{view stop "smoke1"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 2
			{view start "smoke3"}
			{view stop "smoke2"}
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 5
			{volumes "smoke2" disable visible}
			{volumes "smoke3" enable visible}
			{update_visibility_patch}
		}
		{delay 15
			{view stop "smoke3"}
		}
		{delay 17
			{hide 1}
		}
	}
	{on ground_hit
		{if under_water
			{hide 1}
		else
			{delay 3
				{call "activate"}
			}
		}
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
		{fire radius 3 time 5}
	}
	{on "contact_detonate" overload
		{if effector "construction"
			{volumes disable bullet contact blast}
			{fire radius 1.5 time 2 heating 6 effector}
			{delay 0.1
				{call "detonate"}
			}
		else
			{fire radius 1.5 time 2 heating 20 effector followowner}
			{call "detonate"}
		}
	}
}
