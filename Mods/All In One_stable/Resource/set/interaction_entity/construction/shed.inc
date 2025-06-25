;;;;;;;;;;;;;;;;;;;;;;;;;;;Навес;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

{"shed"
	{inflammation_time 4}
	{on bullet_hit
		{if bullet "shell fg"
			{bullet_detonate}
		else bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		}
	}
	{on blast_hit
		{if min_energy 0.2
			{call "break"}
		}
	}
	{on contact
		{if effector "tank"
			{if min_speed 2
				{volumes disable contact}
				{call "break"}
			}
		}
	}
	{on "break"
		{call "crush_fx"}
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

{"wood shed"
	{on "crush_fx"
		{spawn "wood_crush_big" "root"}
	}
}

{"wood shed small"
	{on "crush_fx" overload
		{spawn "wood_crush_small" "root"}
	}
}

{"concrete shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "stone_crush_big" "root"}
	}
}

{"steel shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "tank_die_particle" "root"}
	}
}

{"shed cellar1"
	{on "crush_fx"
		{spawn "trash_1" "root"}
	}
}
