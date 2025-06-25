{"fence"
	{inflammation_time 4}
	{on bullet_hit
		{if bullet "shell fg"
			{bullet_detonate}
		}
	}
	{on blast_hit
		{if min_energy 0.2
			{call "break"}
		}
	}
	{on contact
		{if effector "car"
			{call "crush"}
		else effector "tank"
			{call "crush"}
		else effector "moto"
			{call "crush"}
		else effector "airborne"
			{delay 0.1 ; delay for airborne collision
				{call "crush"}
			}
		else effector "air_part"
			{call "crush"}
		else effector "big part"
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable contact}
		{call "break"}
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

{"fence big"
	{on contact overload
		{if effector "car"
			{if min_speed 10
				{call "crush"}
			}
		else effector "tank"
			{if min_speed 5
				{call "crush"}
			}
		}
	}
}

{"wood fence"
	{on "break"
		{spawn "wood_crush_small" "root"}
		{delay 0.2 {delete}}
	}
}

{"wood fence big"
	{on "break" overload
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
}

{"concrete fence"
	{inflammation_time 10000}
	{on "break"
		{spawn "stone_hit_small" "root"}
		{spawn "concrete_fence_destroy" "root" x}
		{delay 0.2 {delete}}
	}
}

{"steel fence"
	{inflammation_time 10000}
	{on "break"
		{spawn "car_die_particle" "root"}
		{delay 0.2 {delete}}
	}
}

{"animated_crush"
	{on "break" overload
		{kill_delay "break_delay"}
		{burn stop}
		{volumes disable contact bullet blast visible touch}
		{area disable}
		{ani_play "crush" callback}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
	}
}

{"animated_crush_gate"
	{on pierce
		{call "break"}
	}
	{on "break" overload
		{kill_delay "break_delay"}
		{burn stop}
		{volumes disable contact bullet blast visible touch}
		{area disable}
		{ani_play "crush" callback}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
	}
}

{"mockup"
	{on spawn
		{volumes disable contact bullet blast visible touch}
		{area disable}
		{ani_wind "crush" end}
		{set "broken" 1}
	}
	(define "pierce_check"
		{if tagged %0 {if bullet %1 {call "break"}}}
	) 
	{on bullet_hit
		("pierce_check" args "smg"   "pistol")
		("pierce_check" args "rifle" "rifle")
		("pierce_check" args "mgun"  "mgun")
	}
	{on "break"
		{tags add "crushed"}
		{set "broken" 1}
	}
	{on "up"
		{tags remove "crushed"}
		{set "broken" 0}
		{volumes enable contact bullet blast visible touch}
		{area enable}
		{ani_play "crush" -1}
	}
	{on "down"
		{if not "broken"
			{call "break"}
		}
		{tags remove "crushed"}
	}
	{on blast_hit overload
		{if tagged "grenade"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
}
