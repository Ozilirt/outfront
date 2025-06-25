;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;Заборы;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

{"fence" 
	{inflammation_time 4}
	{on bullet_hit
		{if bullet "shell fg"
			{bullet_detonate}
		else bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		}
	}
;	{on blast_hit
;		{if min_energy 0.4
;			{call "break"}
;		}
;	}
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
	{blast_absorption 3.5}
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
	{on blast_hit
		{if min_energy 4.0
			{call "break"}
		}
	}
}

{"wood fence"
	{blast_absorption 0.5} 
	{on "break"
		{spawn "wood_crush_small" "root"}
		{delay 0.2 {delete}}
	}
	{on blast_hit
		{if min_energy 1.0
			{call "break"}
		}
	}
}

{"wood fence big"
	{blast_absorption 0.7}
	{on "break" overload
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
	{on blast_hit
		{if min_energy 1.0
			{call "break"}
		}
	}
}

{"concrete fence"	;каменные, карпичные заборы
	{inflammation_time 10000}
	{blast_absorption 4.0}
	{on contact overload
		{if not effector "moto"
			{inherited}
		}
	}
	{on blast_hit
		{if min_energy 4.0
			{call "break"}
		}
	}
	{on "break"
		{spawn "stone_hit_small" "root"}
		{spawn "concrete_fence_destroy" "root" x}
		{delay 0.2 {delete}}
	}
}

{"steel fence"		;железные части (бочки и тд)
	{inflammation_time 10000}
	{blast_absorption 3.5}
	{on "break"
		{spawn "car_die_particle" "root"}
		{delay 0.2 {delete}}
	}
	{on blast_hit
		{if min_energy 1.0
			{call "break"}
		}
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
	{on blast_hit
		{if min_energy 1.0
			{call "break"}
		}
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
	{on blast_hit
		{if min_energy 1.0
			{call "break"}
		}
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
	{on blast_hit
		{if tagged "grenade"
			{if min_energy 1.0
				{call "break"}
			}
		}
	}
}
