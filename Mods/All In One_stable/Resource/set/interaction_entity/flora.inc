{"tree"
	{inflammation_time 10}
	{on spawn
		{use_local_light 1}
		{view hide "shadow_fall"}
		{call "update_texmod"}
	}
	(define "stir"
		{if not "bare"
			{if not "started"
				{ani_play "stir" 0.2 %params}
				{set "started" 1}
			}
			{if not burned
				{start_sound "tree_stir"}
			}
		}
	)
	{on "stir"
		("stir" params(loop callback))
	}
	{on overlap begin
		{set "overlap" 1}
		{call "stir"}
	}
	{on overlap end
		{set "overlap" 0}
	}
	{on animation_end "stir"
		{if not "overlap"
			{if "started"
				{set "started" 0}
				{ani_stop "stir"}
			}
		}
	}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
		{if volume "crown"
			{spawn "tree_hit_small"}
		 else volume "bole"
			{if bullet "bullet"
				{spawn "wood_hit_bul"}
			 else bullet "shell"
				{spawn "tree_crush"}
				{call "stir"}
			}
		}
	}
	}
	{on blast
		{if volume "crown"
			{call "stir"}
		else min_energy 1
			{call "start_fall"}
		}
	}
	{on contact
		{call "stir"}
		{if effector "tank"
			{if min_speed 1
				{call "start_fall"}
			}
		else effector "airborne"
			{call "start_fall"}
		}
	}
	{on "start_fall"
	   	{start_sound "death_tree.0"}
   		{volumes "bole" disable contact blast}
   		{pillar_fall}
	}
	{on "fallen"
		{volumes "crown" enable overlap visible}
		{depend_on_wind 0}
		{start_sound "death_tree.0"}
	}
	{on "burn"
		{if not burned
			{fire radius 3 time 32}
			{burn volume "crown" fx "smoke_dead_tree" time 36 4}
			{tags add "burned"}
			{if "bare"
				{tex_morph "_burned1" 16 "_burned3" 16}
			else
				{tex_morph "_burned0" 11 "_burned1" 11 "_burned3" 10}
			}
		}
		{call "regenerate"}
	}
	(define "set_crown_visible"
		{volumes "crown" %0 visible}
		{update_visibility_patch}
	)
	{on "update_crown_visibility"
		{if "bare"
			("set_crown_visible" args disable)
		else
			("set_crown_visible" args enable)
		}
	}
	{on "update_wind"
		{if "bare"
			{depend_on_wind 0}
		else
			{depend_on_wind 1}
		}
	}
	{on "update_texmod"
		{if tex_mod "bare" "bare1" "broken" "_burned1" "_burned2" "_burned3"
			{set "bare" 1}
		else
			{set "bare" 0}
		}
		{call "update_crown_visibility"}
		{call "update_wind"}
	}
	{on "texmod_changed"
		{call "update_texmod"}
	}
	{on "animate"
		{ani_play "stir" 0.2 loop}
	}
	{on "regenerate"	
	}
	{on "plant"
		{scale from 0.1 to 1 time 10}
	}
}

{"bush"
	{inflammation_time 6}
	{on "burn" overload
		{if not burned
			{fire radius 2 time 21 heating 0.3}
			{burn volume "crown" fx "smoke_dead_small2" time 25 4}
			{tags add "burned"}
			{if "bare"
				{tex_morph "_burned1" 10 "_burned3" 10}
			else
				{tex_morph "_burned0" 4 "_burned1" 4 "_burned2" 4 "_burned3" 4}
			}
			{delay 22
				{call "burn_end"}
			}
		}
		{call "regenerate"}
	}
	{on "stir" overload
		{if fogged
			("stir" params(loop fake callback))
		else
			("stir" params(loop callback))
		}
	}
	{on blast
		{if min_energy 0.1
			{if not "crown_fall"
				{set "crown_fall" 1}
				{if "bare"
					{tex_morph "_burned1" 0.2 "_burned2" 0.2 "_burned3" 0.2}
				else
					{spawn "tree_hit_big"}
					{tex_morph "_burned0" 0.2 "_burned1" 0.2 "_burned2" 0.2 "_burned3" 0.2}
				}
			}
		}
		{call "regenerate"}
	}
}

{"wheat"
	{inflammation_time 3}
	{on "burn" overload
		{if not burned
			{fire radius 2 time 6 heating 0.3}
			{burn volume "crown" fx "smoke_dead_small2" time 6 1}
			{tags add "burned"}
			{if "bare"
				{tex_morph "_burned1" 3 "_burned3" 3}
			else
				{tex_morph "_burned0" 1.5 "_burned1" 1.5 "_burned2" 1.5 "_burned3" 1.5}
			}
			{delay 6
				{call "burn_end"}
			}
		}
		{call "regenerate"}
	}
}

{"delete_after_burn"
	(mod "mp"
		{on "burn_end"
			{hide 2}
		}
	)
}

{"delete_after_burn stamp"
	(mod "mp"
		{on "burn_end"
			{spawn "burn_grass"}
		}
	)
}

{"delete_after_blast"
	(mod "mp"
		{on blast
			{if min_energy 0.5
				{hide 0.6}
			}
		}
	)
}

{"no_wind"
	{on "update_wind" overload
		{depend_on_wind 0}
	}
}

{"invisible_crown"
	{on "update_crown_visibility" overload
		("set_crown_visible" args disable)
	}
}

{"cabbage"
	{inflammation_time 10000}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
		{if rand 0.2
			{call "crush"}
		else
			{if rand 0.3
				{spawn "tree_hit_small"}
				}
			}
		}
	}
	{on blast_hit
		{if min_energy 1
			{call "crush"}
		else
			{impulse up 2 1 dir 2 1}
		}
	}
	{on contact
		{if effector "human"
			{volumes "crown" disable contact}
			{if rand 0.3
				{call "crush"}
			}
			{delay 0.5
				{volumes "crown" enable contact}
			}
		else
			{call "crush"}
		}
	}
	{on "crush"
		{spawn "tree_hit_small"}
		{delay 0.2
			{spawn "cabbage_destroy1" no_position no_normal}
		}
		{hide 0.3}
	}
}

{"stack_bush"
	{on spawn
		{use_local_light 0}
	}
}
