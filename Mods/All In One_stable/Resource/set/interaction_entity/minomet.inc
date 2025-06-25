{"minomet"
	{blast_absorption 0.5}
	{on spawn
		{add_view	"human_linked_selection" "linked_selection" "visor"}
	}
	{on pierce
		{if bullet "shell"
;			{call "explosion"}
		}
	}
	{on blast_hit
		{if min_energy 4
			{impulse up 1.2 0.2 dir 1 0.1}
		else min_energy 1
			{impulse up 0.5 0.2 dir 0.3 0.1}
		else min_energy 0.4
			;{ani_play "hit"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy  3
				{call "explosion"}
			 else min_energy 2.4
				{if rand 0.90 {call "explosion"}}
			 else min_energy 1.9
				{if rand 0.60 {call "explosion"}}
				{if rand 0.50 {components "body" disable work}}
			 else min_energy 1.1
				{if rand 0.30 {call "explosion"}}
			 else min_energy 0.9
				{if rand 0.10 {call "explosion"}}
			}
		}
		{if volume "gun"
			{if min_energy 1.5
				{components "gun" disable work}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		{delay 14 {view stop "deathfx"}}
	}
	{on fire "gun"
       		{spawn "dust_shot_small" "basis"}
	}
	{on "shot_blastwave"
		{blastwave c4 0.2 r0 1 r1 1.5 bone "Foresight1"}
	}
	{on contact
		{if effector_velocity 5
			{if effector "tank"
				{component disable work repair}
				{if volume "body"
					{set "crush" 1}
					{call "explosion"}
				}
			}
		else effector_velocity 3
			{if effector "big part"
				{component disable work}
			}
		}
	}
	{on "update_obstacle"
		{if operatable
			{change_obstacle "operatable"}
		else
			{change_obstacle "empty"}
		}
	}
}
{"heavy minomet"
	{on fire "gun" overload
       		{spawn "dust_shot_small" "basis"}
        	{spawn "tank_canon_fire_small" "Foresight1" x}
	}
}
