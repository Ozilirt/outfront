{"construction"
	{on spawn
		{call "update_fx"}
	}
	{on "update_fx"
;		{con "update_fx"}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1"	}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1a"}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1b"}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1c"}
		{add_view "smoke_black"			"smoke"	"FX_smoke2"	}
		{add_view "smoke_black"			"smoke"	"FX_smoke2a"}
		{add_view "smoke_black"			"smoke"	"FX_smoke2b"}
		{add_view "smoke_black"			"smoke"	"FX_smoke2c"}

		{add_view "smoke_dead_small"	"fire"	"FX_fire1"  }
		{add_view "smoke_dead_small"	"fire"	"FX_fire1a" }
		{add_view "smoke_dead_small"	"fire"	"FX_fire1b" }
		{add_view "smoke_dead_small"	"fire"	"FX_fire1c" }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2"  }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2a" }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2b" }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2c" }

		{add_view "smoke_grey"			"flue"	"FX_flue"	}
	}
	{on "effects"
;		{con "effects"}
		{if "first_stage"
;			{con "start_smoke_fire"}
			{set "first_stage" 0}
			{call "destroyed_stamp"}
			{view start "smoke"}
			{view start "fire"}
			{ani_play "effector" loop}
			{delay 13 3 {view stop "fire"}}
			{delay 20 3 {view stop "smoke"}}
			{delay 30   {ani_stop "effector"}}
		}
		{if "last_stage"
			{spawn "circledust_norm"	"FX_dust1"	}
			{spawn "circledust_norm"	"FX_dust1a"	}
			{spawn "spheredust_big"		"FX_dust2"	}
			{spawn "spheredust_big"		"FX_dust2a"	}
		}
		{spawn "wood_hit_small"			"FX_wood1"	}
		{spawn "wood_hit_small"			"FX_wood1a"	}
		{spawn "wood_hit_big"			"FX_wood2"	}
		{spawn "wood_hit_big"			"FX_wood2a"	}

		{spawn "stone_hit_small"		"FX_stone1"	}	; @todo : what to do with this?
		{spawn "stone_hit_small"		"FX_stone1a"}
		{spawn "stone_hit_small"		"FX_stone1b"}
		{spawn "stone_hit_small"		"FX_stone1c"}
		{spawn "stone_hit_small"		"FX_stone1d"}
		{spawn "stone_hit_small"		"FX_stone1e"}
		{spawn "stone_hit_small"		"FX_stone1f"}
		{spawn "stone_hit_small"		"FX_stone1g"}
		{spawn "stone_hit_small"		"FX_stone1h"}
		{spawn "stone_hit_small"		"FX_stone1i"}
		{spawn "stone_hit_small"		"FX_stone1j"}
		{spawn "stone_hit_small"		"FX_stone1k"}
		{spawn "stone_hit_small"		"FX_stone1l"}
		{spawn "stone_hit_small"		"FX_stone1m"}

		{spawn "stone_hit_big"			"FX_stone2"	}
		{spawn "stone_hit_big"			"FX_stone2a"}
		{spawn "hay_hit_norm"			"FX_haulm1"	}
		{spawn "hay_hit_norm"			"FX_haulm1a"}
		{spawn "hay_hit_big"			"FX_haulm2"	}
		{spawn "hay_hit_big"			"FX_haulm2a"}

		{spawn "tank_die"				"FX_exp1"   }
		{spawn "barrel_die"				"FX_exp1a"	}
		{spawn "barrel_die_big"			"FX_exp2"	}
		{spawn "barrel_die_big"			"FX_exp2a"	}

		{spawn "sand_hit_small"			"FX_sand1"	}
		{spawn "sand_hit_small"			"FX_sand1a"	}
		{spawn "sand_hit_big"			"FX_sand2"	}
		{spawn "sand_hit_big"			"FX_sand2a"	}
	}
	{on "destroyed_stamp"
		{spawn "destroy_pit"		no_position	}
	}
	{on "disable_volumes"
;		{con "disable volumes"}
		{volumes disable visible bullet contact blast}
	}
}

{"flue"
	{on spawn
		{call "flue_process"}
	}
	{on "flue_process"
		{if rand 0.5
			{view start "flue"}
		else
			{view pause "flue"}
		}
		{delay 50
			{call "flue_process"}
		}
	}
}

{"windowed"
	(define "break_window"
		{spawn "glass_hit" "fx_glass%0" x}
		{spawn "glass_hit" "fx_glass0%0" x}
		{volumes "window%0" disable contact bullet blast}
		{delay 0.1
			{bone cut	"window%0"}
			{bone show	"window%0_x"}
		} ; prevent trace bullet into freed volumes after Bone Cut
	)
	(define "try_break_window"
		{if volume "window%0"
			{set "break_window" 1}
			("break_window" args %0)
		}
	)
	{on spawn
		{if not sunlight
			{add_view "light_house" "light" "fx_light1"}
			{add_view "light_house" "light" "fx_light2"}
			{add_view "light_house" "light" "fx_light3"}
			{add_view "light_house" "light" "fx_light4"}
			{add_view "light_house" "light" "fx_light5"}
			{add_view "light_house" "light" "fx_light6"}
			{add_view "light_house2" "light" "fx_light_high1"}
			{add_view "light_house2" "light" "fx_light_high2"}
			{add_view "light_house2" "light" "fx_light_high3"}
			{add_view "light_house2" "light" "fx_light_high4"}
			{add_view "light_house2" "light" "fx_light_high5"}
			{add_view "light_house2" "light" "fx_light_high6"}
			{view start "light"}
		else
			{bone cut "fx_light1"}
			{bone cut "fx_light2"}
			{bone cut "fx_light3"}
			{bone cut "fx_light4"}
			{bone cut "fx_light5"}
			{bone cut "fx_light6"}
			{bone cut "fx_light_high1"}
			{bone cut "fx_light_high2"}
			{bone cut "fx_light_high3"}
			{bone cut "fx_light_high4"}
			{bone cut "fx_light_high5"}
			{bone cut "fx_light_high6"}
		}
	}
	{on bullet_hit; overload
;		{set "break_window" 0}
		{call "break_window"}
;		{if not "break_window"
;			{inherited}
;		}
	}
	{on contact
		{call "break_window"}
	}
	{on blast 
		{if min_energy 0.2
			{call "break_window"}
		}
	}
	{on "break_window"
		("try_break_window" args 0)		("try_break_window" args 1)
		("try_break_window" args 2)		("try_break_window" args 3)
		("try_break_window" args 4)		("try_break_window" args 5)
		("try_break_window" args 6)		("try_break_window" args 7)
		("try_break_window" args 8)		("try_break_window" args 9)
		("try_break_window" args 10)	("try_break_window" args 11)
		("try_break_window" args 12)	("try_break_window" args 13)
		("try_break_window" args 14)	("try_break_window" args 15)
		("try_break_window" args 16)	("try_break_window" args 17)
	}
	{on "break_windows"
		("break_window" args 0)		("break_window" args 1)
		("break_window" args 2)		("break_window" args 3)
		("break_window" args 4)		("break_window" args 5)
		("break_window" args 6)		("break_window" args 7)
		("break_window" args 8)		("break_window" args 9)
		("break_window" args 10)	("break_window" args 11)
		("break_window" args 12)	("break_window" args 13)
		("break_window" args 14)	("break_window" args 15)
		("break_window" args 16)	("break_window" args 17)
	}
	{on "next_stage"
		{call "break_windows"}
	}
	{on "last_stage"
		{call "break_windows"}
	}
}
