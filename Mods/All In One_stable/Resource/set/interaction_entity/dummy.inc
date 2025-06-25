{"dummy"
	{on "stop"	{view stop ""}}
	{on "pause"	{view pause ""}}
	{on "delete"{delete}}
}

{"physics_damping"
	{friction 1000}
	{restitution 0.001}
}

(define "throwing_weapon"
	{on contact
		{if effector "human"
			{delay 0
				{constrain_velocity 1}
			}
		}
	}
)

{"knife" ("throwing_weapon")}
{"axe" ("throwing_weapon")}

{"stone"
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
			{bullet_detonate}
		}
	}
}

{"flesh part"
	{on blast {spawn "bloodsparks_small"}}
	{on bullet_hit 
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
			{spawn "bloodsparks_small"}
		}
	}
	{on contact
		{spawn "bloodsparks_small"}
	}
	{on ground_hit
		{if min_speed 10
			{spawn "bloodsparks_small"}
		}
	}
}

{"small part"
	{on spawn
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
		{call "stop_view"}
		{delay 25 15 {hide 10}}
	}
	{on blast_hit
		{if min_energy 0.5
			{hide 1}
		else
			{impulse up 3 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else bullet "bullet"
			{impulse up 2 1 dir 1 0.5}
		else bullet "shell"
			{hide 1}
		}
	}
	{on contact
		{if effector "vehicle"
			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{hide 1}
		}
	}
}

{"small part fx"
	{on "stop_view"
		{delay 0.5 0.3 {view stop ""}}
	}
}

{"medium part"
	{friction 2}
	{restitution 0.2}
	{on spawn
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
		("hide_mp" args 60 10)
	}
	{on blast_hit
		{if min_energy 1.0
			{hide 1}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else bullet "bullet"
			{impulse up 0.5 0.5 dir 0.5 0.5}
		else bullet "shell"
			{hide 1}		
		}
	}
	{on contact
		{impulse up 0.1 0.1 dir 0.1 0.1}
	}
}

{"big part"
	{friction 2}
	{restitution 0.1}
	{on spawn
		{delay 0.1
			{volumes disable touch}
		}
		("hide_mp" args 60 10)
	}
	{on blast_hit
		{if min_energy 8 
			{impulse up 5 1 dir 5 1}
		  else min_energy 0.5
			{impulse up 1 0.3 dir 1 0.5}
		}
	}
	{on bullet_hit
		{if bullet "big shell extra"
			{impulse up 5 1 dir 5 1}
		 else bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		 else bullet "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else bullet "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
}

{"wood part"
	{on spawn
		{delay 2
			{volumes enable float}
		}
	}
}

{"inventory_box"
	{on pierce
		{if bullet "shell"
			{call "crush"}
		}
	}
	{on blast
		{if min_energy 0.1
			{call "crush"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable bullet blast contact}
		{delete}
	}
}

{"inventory_box wood"
	{on "crush"
		{spawn "wood_crush_small"}
	}
}

{"mg_stan"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel2"	"Foresight3"}
	}
	{on fire "mgun"
		{view start "flashbarrel2"}
	}
}
{"flag"
	{on spawn
		{ani_play "flattern" loop}
	}
}

{"starshell"
	{on spawn
		{add_view "starshell_light"	"light" "root"}
		{delay 0.4
			{view start "light"}
		}
		{impulse up 40 fx 10 20 fy 10 20}
		{delay 4 1
			{delete}
		}
	}
}
{"water"
	{on spawn
		{ani_play "wave" loop}
	}
}

{"cord_wood"
	{inflammation_time 3}
	(define "burn_start"
		{add_view "smoke_camp_norm" "fire" "fx_light"}
		{set "burning" 1}
		{view start "fire"}
		{burn time %0}
		{fire radius 0.7 time %0 heating 0.3 followowner safe}
		{delay %0
			{view stop "fire"}
			{set "burning" 0}
			{tags remove "burned"}
		}
	)
	{on spawn
		{tags add "wood"}
		{if "burning"
			{add_view "smoke_camp_norm" "fire" "fx_light"}
			{view start "fire"}
		}
	}
	{on "_burn"
		{if "poured"
			{tags add "burned"}
			("burn_start" args 300)
		}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
			{call "burn"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "break"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
	{on "break"
		{if "burning"
			{spawn "camp_die" no_position offset 0 0 5}
		else
			{spawn "wood_hit_small" no_position}
		}
		{delete}
	}
	{on "pour_over"
		{if name "fuel"
			{tags add "poured"}
			{set "poured" 1}
		}
	}
}

{"camp_fire"
	{on spawn
		{call "burn"}
	}
	{on "_burn" overload
		("burn_start" args 7200)
	}
}

{"camp_fire2"
	{on contact overload}
}

{"post_way"
	{on "hide"
		{bone hide "root"}
	}
	{on "show"
		{bone show "root"}
	}
}

{"stuff"
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{if min_energy 0.3
				{impulse up 5 1 dir 7 2}
			}
		}
	}
	{on bullet_hit
		{if not linked
			{impulse up 2 1 dir 1 0.5}
		}
	}
}

{"paratrooper"
	{on "start"
		{ani_play "flight" callback}
	}
	{on animation_end "flight"
		{spawn_human "paratrooper"
			{tags add "paratrooper"}
		}
		{ani_play "landing"}
	}
}


{"random_animation"
	{on spawn
		{call "random_animation"}
	}

	(define "random_animation"
		rand 0.1
		{ani_play "animation%0" callback}
	)
	{on "random_animation"
		{if  ("random_animation" args 0)
		else ("random_animation" args 1)
		else ("random_animation" args 2)
		else ("random_animation" args 3)
		else ("random_animation" args 4)
		else ("random_animation" args 5)
		else ("random_animation" args 6)
		else ("random_animation" args 7)
		else ("random_animation" args 8)
		else rand 0.1
			{call "delay"}
		else
			{call "random_animation"}
		}
	}

	(define "random_animation_end"
		{on animation_end "animation%0"
			{delay 0
				{call "random_animation"}
			}
		}
	)
	("random_animation_end" args 0)
	("random_animation_end" args 1)
	("random_animation_end" args 2)
	("random_animation_end" args 3)
	("random_animation_end" args 4)
	("random_animation_end" args 5)
	("random_animation_end" args 6)
	("random_animation_end" args 7)
	("random_animation_end" args 8)

	{on "delay"
		{call "random_animation"}
	}
}

{"random_animation with_delay"
	{on "delay" overload
		{delay 12 4
			{call "random_animation"}
		}
	}
}

{"pointer"
	{on spawn
		{tags add "pointer"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"user_guide"
	{on spawn
		{tags add "user_guide"}
		{inactive 0}
		{delay 10
			{hide 5}
		}
	}
}

{"katusha_ammo"
	{on spawn
		{tags add "katusha_ammo"}
		{link_sound "fly" "reactive.katusha_ammo"}
		{play_sound "fly" 1}
	}
}

(define "shellhole_show_with_delay"
	{on spawn
		{view hide "shellhole"}
		{delay %0
			{view show "shellhole"}
		}
	}
)

{"shellhole_dead_moto"
	("shellhole_show_with_delay" args 0.1)
}
{"shellhole_dead_car"
	("shellhole_show_with_delay" args 0.2)
}
{"shellhole_dead_tank"
	("shellhole_show_with_delay" args 0.35)
}
