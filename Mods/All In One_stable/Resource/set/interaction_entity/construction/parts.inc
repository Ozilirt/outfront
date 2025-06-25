(define "cut_pieces"
	("cut_piece" args 0)	("cut_piece" args 1)
	("cut_piece" args 2)	("cut_piece" args 3)
	("cut_piece" args 4)	("cut_piece" args 5)
	("cut_piece" args 6)	("cut_piece" args 7)
	("cut_piece" args 8)	("cut_piece" args 9)
	("cut_piece" args 10)	("cut_piece" args 11)
	("cut_piece" args 12)	("cut_piece" args 13)
	("cut_piece" args 14)	("cut_piece" args 15)
)

(define "cut_subpieces"
	("cut_subpiece" args 0)	("cut_subpiece" args 1)
	("cut_subpiece" args 2)	("cut_subpiece" args 3)
	("cut_subpiece" args 4)	("cut_subpiece" args 5)
	("cut_subpiece" args 6)	("cut_subpiece" args 7)
	("cut_subpiece" args 8)	("cut_subpiece" args 9)
	("cut_subpiece" args 10)("cut_subpiece" args 11)
	("cut_subpiece" args 12)("cut_subpiece" args 13)
	("cut_subpiece" args 14)("cut_subpiece" args 15)
	("cut_subpiece" args 16)("cut_subpiece" args 17)
)

{"parts construction"
	{on blast
		{if volume "body"
			{set "blast" 0}
			{call "check_blast"}
			{if "blast"
				{call "change_model"}
			}
		}
	}
	{on "check_blast"
		{if min_energy 1.8
			{set "blast" 1}
		}
	}
	{on "criticalhit"
		{if volume "body"
			{set "blast" 0}
			{call "change_model"}
		}
	}
	{on bullet_hit
		{if volume "body"
			{if bullet "shell"
				{call "break_windows"}
				{delay_ex 0.1
					{weakness_tex_morph}
				}
			else bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			}
		}
	}
	{on contact
		{set "blast" 0}
		{if effector "airborne"
			{call "change_model"}
		else effector "air_part"
			{if min_speed 5
				{call "change_model"}
			}
		}
	}
	{on "change_model"
		{if not "sliced"
			{tags add "crushed"}
			{set "sliced" 1}
			{call "disable_volumes"}
			{delay_ex 0.1
				{set_skeleton "_x"}
				{volumes disable contact}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{use_blend_tex 1}
				{call "cut_pieces"}
				{ani_play "crush"}
				{delay 0.1
					{update_visibility_patch}
				}
			}
		}
	}
	{on "break"
		{call "change_model"}
	}
}

{"small parts construction"
	{on contact
		{set "blast" 0}
		{if effector "tank"
			{call "change_model"}
		else effector "car"
			{if min_speed 10
				{call "change_model"}
			}
		}
	}
	{on "check_blast" overload
		{if min_energy 0.4
			{set "blast" 1}
		}
	}
}

{"concrete small parts construction"
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_small_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"big steel parts construction"
	{on "criticalhit" overload}
	{on bullet_hit
		{if volume "body"
			{if bullet "shell"
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_large_steel" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_medium_steel" bone "sub_piece%0"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_subpieces")
	}
}

{"small steel parts construction"
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_medium_steel" bone "piece%0"
				{volumes enable contact}
				{if "blast"
					{impulse up 4 2 dir 2.5 1.3 no_position}
				else
					{impulse up 1 0.7 dir -4.5 0.3 no_position}
				}
			}
		)
		("cut_pieces")
	}
}

{"wood parts construction"
	{on bullet_hit
		{if volume "body"
			{if bullet "shell"
				{set "blast" 0}
				{call "change_model"}
			else bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_wood" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}


{"tower_metal"
	{on pierce
		{if volume "body"
			{if bullet "bullet"
				{burn fx "drops_water_small_long" fake}
			}
		}
	}
	{on "effects"
		{add_view "drops_water_big" "water" "fx_water1"}
		{add_view "drops_water_big" "water" "fx_water1a"}
		{view start "water"}
		{spawn "ex_water_extra_big_test" no_position}
	}
	{on "destroyed_stamp" overload
		{delay 0.5
			{spawn "pool2a_blu" no_position}
		}
	}
}


{"lighthouse parts construction"
	{on spawn
		{if not sunlight
			{add_view "light_lighthouse"	"light" "fx_light"}
			{add_view "light_lighthouse2"	"light" "fx_spot"}
			{view start "light"}
		}
	}
	{on "update_fx"
		{add_view	"spheredust_big_long2"	"dust1"	"FX_dust_long1"}
		{add_view	"smoke_camp_big2"		"fire1"	"FX_fire"}
		{add_view	"smoke_camp_big"		"fire1"	"FX_fire1"}
	}
	{on "change_model"
		{drop_orders}
	}
	{on bullet_hit
		{if bullet "flame"
			{fire radius 1.5 time 2 heating 20 effector followowner}
		else
			{bullet_detonate}
		}
	}
	{on "check_blast" overload
		{if min_energy 10
			{set "blast" 1}
		}
	}
	{on "criticalhit" overload
	}
	{on "effects"
		{add_view	"stone_crush_extra_big"	"dust"	"FX_dust_long"}
		{add_view	"stone_crush_extra_big"	"dust"	"FX_dust2"}
		{add_view	"wood_hit_circle_big"	"dust"	"FX_board"}
		{add_view	"debris"				"dust"	"FX_rock"}
		{view start "dust"}
		{delay 4.5
			{view stop "dust"}
		}
		{delay 1
			{view start "dust1"}
			{delay 3
				{view stop "dust1"}
			}
		}
		{view start "fire1"}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_concrete" bone "piece%0" id "lighthouse_part"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_camp_norm2" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 1 0.5 "stop"}
			}
		)
		("cut_pieces")
	}
	{on "slice_load" ;called after save/load to restore state
		{if name "lighthouse_part"
			{with_effector
				{add_view "smoke_camp_norm2" "smoke" "root"}
			}
		}
	}
}

{"piece_large_concrete"
	{on spawn
		{if rand 0.5
			{set "crush" 1}
		}
	}
	{on ground_hit
		{if "crush"
			{spawn "piece_crush"}
			{delete}
		}
	}
	{on contact
		{if effector "tank"
			{spawn "piece_crush"}
			{delete}
		}
	}
}

{"building_part"
	{friction 2}
	{restitution 0.3}
	{on spawn
		{if rand 0.5
			{set "crush" 1}
		}
		("hide_mp" args 100 10)
	}
	{on ground_hit
		{if not "sliced"
			{spawn "spheredust_big_short2"}
			{call "cut_subpieces"}
		}
	}
	{on contact
		{if not "sliced"
			{spawn "spheredust_big_short2"}
			{call "cut_subpieces"}
		}
	}
}


{"building_part concrete"
	{on ground_hit
		{if "crush"
			{spawn "piece_crush_big"}
			{delete}
		}
	}
	{on contact
		{if effector "tank"
			{spawn "piece_crush_big"}
			{delete}
		}
	}
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "building_part_concrete_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 1 0.5 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "building_part_concrete_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part wood"
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_big_wood" bone "sub_piece%0" id "building_part_wood_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 5 3 "stop"}
			}
		)
		("cut_subpieces")	
	}
	{on contact
		{if effector "tank"
			{spawn "wood_hit_small"}
			{delete}
		}
	}
	{on "slice_load"
		{if name "building_part_wood_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"stone_landslip"
	{on blast
		{if volume "support"
			{call "crush"}
		}
	}
	{on contact
		{if effector "vehicle"
			{if volume "support"
				{call "crush"}
			}
		}
	}
	{on "crush"
		{if not "sliced"
			{set "sliced" 1}
			{tags add "crushed"}
			{volumes "support" disable contact bullet blast}
			{ani_play "crush1"}
			(define "cut_stone"
				{tear "piece_big_stone" bone "part%0"
					{volumes enable contact}
					{impulse up 0.2 0.1 cx 3 6 cy 3 6 fx 10 no_position}
				}
			)
			("cut_stone" args 0)	("cut_stone" args 1)
			("cut_stone" args 2)	("cut_stone" args 3)
			("cut_stone" args 4)	("cut_stone" args 5)
			("cut_stone" args 6)	("cut_stone" args 7)
		}
	}
}

{"cornered parts construction"
	{blast_to_pierce 50}
	{blast_absorption 0.5}
	{on bullet_hit
		{if not under_water
			{if bullet "shell small"
			 	{spawn	"stone_hit_br_small" inv_normal}
			else bullet "shell"
			 	{spawn	"stone_hit_br" inv_normal}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
;				{add_view "smoke_black" "smoke" "root"}
;				{view start "smoke"}
;				{delay_effect 20 10 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "cornered_parts_construction_piece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
	{on "destroyed_stamp" overload
		{if rand 0.25
			{spawn "town_shambles1"		no_position}
		else rand 0.25
			{spawn "town_shambles2"		no_position}
		else rand 0.25
			{spawn "town_shambles3"		no_position}
		else
			{spawn "town_shambles4"		no_position}
		}
	}
	{on "effects"
		{if rand 0.5
			{start_sound "death.wall_br0"}
		else
			{start_sound "death.wall_br1"}
		}
	}
}

{"cornered wall parts construction"
	{on contact
		{if effector "tank"
			{set "blast" 0}
			{call "change_model"}
		}
	}
	{on "destroyed_stamp" overload
	}
}

{"mill staged construction" ; worked with staged animated construction
	{on "set_skeleton" overload
		{set_skeleton "_x" sync}
	}
	{on "effects"
		{if "last_stage"
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		(define "cut_piece"
			{tear "building_part_wood" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_piece" args 0)	("cut_piece" args 1)
		("cut_piece" args 2)	("cut_piece" args 3)
		{delay 0.1
			{bone cut "sweep"}
		}
	}
}

{"mill_water"
	{on spawn
		{burn volume "fx1" fx "drops_water_mill" time 1000000 fake even_law}
		{burn volume "fx2" fx "drops_water_mill" time 1000000 fake even_law}
		{burn volume "fx3" fx "drops_water_mill" time 1000000 fake even_law}
		{burn volume "fx4" fx "drops_water_mill" time 1000000 fake even_law}
	
		{add_view "wash_ship_stop" "water" "fx_wash1"}
		{add_view "wash_ship_stop" "water" "fx_wash2"}

		{view start "water"}
	}
}

{"commandants_office"
	{on contact
		{if effector "molotov_coctail"
			{if "break_window"
				{tags add "burned"}
				{burn fx "smoke_dead_big" fake}
			}
		}
	}
}

{"commandants_office_door"
	{on contact
		{if effector "molotov_coctail"
			{tags add "burned"}
			{burn fx "smoke_dead_big" fake}
			{hide 4}
		}
	}
}

{"e-house3x"
	{blast_to_pierce 6}
	{on "check_blast" overload
		{if min_energy 4
			{set "blast" 1}
		}
	}
}

{"concrete dot parts construction"
	{on "check_blast" overload
		{if min_energy 6
			{set "blast" 1}
		}
	}
	{on "criticalhit" overload}
}
