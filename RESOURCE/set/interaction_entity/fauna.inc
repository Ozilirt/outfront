{"animal"
	{on blast
		{health_damage_blast "" "damage" "die" "explosion"
			{0.1	10}
			{2		100}
			{20		10000}
		}
	}
	{on blow
		{start_sound "man_blow"}
		{health_damage_blow "hit" "hit" "die" "die"}
	}
	{on bullet_hit
		{call "pierce_damage"}
	}
	{on "pierce_damage"
		{health_damage_pierce "" "damage" "die" "explosion"
;			{"shell"		5000}
;			{"zenite"		1000}
;			{"rifle"		500}
;			{"mgun"			150}
;			{"smg"			90}
;			{"pistol"		70}
		}
	}
	{on contact 
		{if effector "vehicle"
			{health_damage_crush "die" "explosion"}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count "hit" "damage" "die" "die" 110}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count "hit" "damage" "die" "die" 180}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count "hit" "damage" "die" "crush" 60}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count "hit" "damage" "die" "crush" 40}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count "hit" "damage" "die" "die" 20}
			}
		}
	}
	{on "die"
		{volumes disable contact}
		{die}
		{delay 3
			{volumes enable contact}
			{update_visibility_patch}
		}
	}
	{on "explosion"
		{delete}
	}
	{on "idle"
		{if name "enter"
			{call "idle_try"}
		else name "exit"
			{kill_delay "idle_try"}
			{kill_delay "idle_noanm"}
			{ani_stop "passive"}
			{ani_stop "eat"}
		}
	}
	{on "idle_try"
		{delay 0.2 0.1 "idle_try"
			{if rand 0.4
				{ani_play "eat" callback}
			else rand 0.4
				{ani_play "passive" callback}
			else
				{delay 5 3 "idle_noanm"
					{call "idle_try"}
				}
			}
		}
	}
	{on animation_end "passive"
		{call "idle_try"}
	}
	{on animation_end "eat"
		{call "idle_try"}
	}
}

{"chicken"
	{on "damage"
		{spawn "pero_hit_small"}
		{start_sound "chicken_clucking"}
	}
	{on "die"
		{call "explosion"}
	}
	{on "explosion"
		{start_sound "animal_die.chicken"}
		{spawn "pero_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "chicken_clucking"}
		}
	}
	{on ground_hit
		{spawn "pero_hit_small"}
		{start_sound "chicken_clucking"}
	}
}

(define "imp"
	{spawn %0 %1
		{impulse	up 1 0.5 dir 8 4
					cx 0 12 cy 0 12
					fx 0 60 fy 0 60 fz 80 40
		}
	}
)

{"dog"
	{on spawn
		{add_view	"drops_water_small3"	"on_water"	"leg1"}
		{add_view	"drops_water_small3"	"on_water"	"leg2"}
		{add_view	"drops_water_small3"	"on_water"	"leg3"}
		{add_view	"drops_water_small3"	"on_water"	"leg4"}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "dog_aw"}
		}
	}
	{on "die"
		{start_sound "animal_die.dog"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal_die.dog"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "dog_aw"}
		}
	}

	(define "terrain_fx_dog"
		{on terrain %0 enter
			{view start "on_%1"}
		}
		{on terrain %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_dog" args "water" 			water)
	("terrain_fx_dog" args "shallow water"	water)
	("terrain_fx_dog" args "deep water"		water)
	("terrain_fx_dog" args "puddle"			water)
	("terrain_fx_dog" args "shallow puddle"	water)
	("terrain_fx_dog" args "shallow swamp"	water)
}

{"rabbit"
	{on "damage"
		{spawn "bloodsparks_small"}
	}
	{on "die"
		{spawn "rabbit_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{spawn "rabbit_hit"}
		{spawn "blood"}
;		{spawn "blood_small"}
		{delete}
	}
}

{"cow"
	{on "pierce_damage" overload
		{health_damage_pierce "" "damage" "die" "explosion"
;			{"shell"		1000}
;			{"zenite"		90}
;			{"rifle"		50}
;			{"mgun"			40}
;			{"smg"			40}
;			{"pistol"		20}
		}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "cow_moo"}
		}
	}
	{on "die"
		{start_sound "cow_moo"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "cow_moo"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "cow_moo"}
		}
	}
}
