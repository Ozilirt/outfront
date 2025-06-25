{"post"
	{inflammation_time 4}
	{on blast_hit
		{if min_energy 0.5
			{call "break"}
		}
	}
	{on contact 
		{if effector "vehicle"
			{if min_speed 2
				{call "break"}
			}
		}
	}
	{on bullet_hit
		{if bullet "shell fg"
			{bullet_detonate}
		}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8
					{call "break"}
				}
			}
		}
	}
	{on "break"
		{pillar_fall}
		{call "light_break"}
	}
	{on "light_break"} ; handled in extender
}

{"post concrete"
	{inflammation_time 10000}
}

{"disable_area post"
	{on "break"
		{area disable}
		{volumes disable obstacle}
	}
}

{"ring_post"
	{on "ring"
		{delay 0.5
			{ani_play "gong"}
			{start_sound "world.ring_post"}
		}
	}
}
