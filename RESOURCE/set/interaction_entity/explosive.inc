{"mine"
	{on spawn
		{add_view "mined_view" "mined" "root"}
	}
	{on "explosion"
		{if mined
			{call "_explosion"}
		}
	}
}

{"mine_antipersonnel"
	{on "_explosion"
		{stuff_detonate}
	}
	{on contact
		{if mine_effector "human"
			{call "explosion"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "explosion"}
		}
	}
	{on bullet_hit
		{call "explosion"}
	}
}

{"mine_antitank"
	{on "_explosion"
		{stuff_detonate}
	}
	{on contact 
		{if mine_effector "vehicle"
			{call "explosion"}
		}
	}
	{on bullet_hit
		{if bullet "shell"
			{call "explosion"}
		else bullet "zenite"
			{call "explosion"}
		}
	}
}

{"mine training"
	{on "mined"
		{tags add "mined"}
	}
	{on "defused"
		{tags remove "mined"}
	}
}

{"mine training mine_antipersonnel"
	{on "_explosion" overload
		{spawn "mine_training_die"}
		{delete}
	}
}

{"dynamite"
	{on "undermine"
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
		{delay 8
			{call "explosion"}
		}
	}
	{on "explosion"
		{stuff_detonate}
	}
;	{on bullet_hit
;		{call "explosion"}
;	}
;	{on blast_hit
;		{volumes disable blast}
;		{if min_energy 0.3
;			{call "explosion"}
;		}
;	}
}

{"air_bomb"
	{on "explosion"
		{blastwave c4 15 r0 8 r1 15 offset 0 0 30}
		{spawn "shockwave"}
		{spawn "ex_bomb_big" offset 0 0 20}
;		{spawn "shellhole_big"}
		{if not terrain "bridge"
			{spawn "crater_big" no_normal}
		}
		{delete}
	}
	{on ground_hit
		{if min_speed 10
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"air_bomb small"
	{on "explosion" overload
		{blastwave c4 7 r0 4 r1 7 offset 0 0 30}
		{spawn "shockwave"}
		{spawn "ex_bomb_big" offset 0 0 20}
;		{spawn "shellhole_big"}
		{if not terrain "bridge"
			{spawn "crater_big" no_normal}
		}
		{delete}
	}
}

{"explosive_barrel"
	{inflammation_time 3}
	{on spawn
		{set "explosioned" 0}
	}
	{on pierce
		{if stuff "fuel" 20
			{call "explosion"}
		else bullet "bullet"
			{if stuff "water" 20
				{burn fx "drops_water_small_short" fake}
			}
		else bullet "shell"
			{call "break"}
		}
	}
	{on blast
		{if min_energy 0.1
			{call "break"}
		}
	}
	{on contact
		{if effector "vehicle"
			{if effector_velocity 5
				{call "break"}
			}
		}
	}
	{on "burn"
		{call "break"}
	}
	{on "break"
		{if stuff "fuel" 20
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "explosioned"
			{set "explosioned" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{blastwave c4 5 r0 4 r1 6}
			{spawn "barrel_die_big"}
			{spawn "fire_shellhole"}
			{add_view "smoke_barrel" "smoke" "root"}
			{view start "smoke"}
			{impulse up 15 3 dir 3 1 cx 0 1 cy 0 1 com}
			{delay 25
				{view stop "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if "explosioned"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}

{"mortar_shell"
	{on blast
		{if min_energy 0.5
			{call "explosion"}
		}
	}
	{on pierce
		{if bullet "shell"
			{call "explosion"}
		}
	}
	{on "explosion"
		{if not "explosioned"
			{set "explosioned" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}
