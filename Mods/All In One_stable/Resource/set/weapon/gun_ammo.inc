;SDL

(define "trace_shell"
	{trace
		{view "/fx/_bmp/trace.ebm"
			{Light 0.5}
			{ScaleY 3}
		}
		{length 6}
	}
)

(define "trace_big_shell"
	{trace
		{view "/fx/_bmp/trace.ebm"
			{Light 0.5}
			{ScaleY 4}
		}
		{length 7}
	}
)

(define "trace_extra_big_shell"
	{trace
		{view "/fx/_bmp/trace.ebm"
			{Light 0.5}
			{ScaleY 6}
		}
		{length 10}
	}
)

{ammo pattern "ap_light"
	{damage blastwave
		{energy 0.3}	; kg
		{area 0 0.5}		; m
	}
	("trace_shell")
}
{ammo pattern "az_light"
	{damage blastwave
		{energy 0.4}	; kg
		{area 0 1}		; m
	}
	("trace_shell")
}
{ammo pattern "sm_light"
	{damage blastwave
		{energy 0.4}	; kg
		{area 0 0.7}		; m
	}
	("trace_shell")
}

{ammo pattern "ap_heavy"
	{damage blastwave
		{energy 0.5}	; kg
		{area 0 1}		; m
	}
	("trace_big_shell")
}
{ammo pattern "fg_light"
	{detonationThickness 2}
	{damage blastwave
		{energy 1}	; kg
		{area 2 4}		; m
	}
	("trace_shell")
}
{ammo pattern "fg_medium"
	{detonationThickness 3}
	{damage blastwave
		{energy 3}		; kg
		{area 3 5}		; m
	}
	("trace_shell")
}
{ammo pattern "fg_heavy"
	{detonationThickness 5}
	{damage blastwave
		{energy 6}		; kg
		{area 5 7}		; m
	}
	("trace_big_shell")
}
{ammo "bullet12.7 zenite" from "ap_light"}
{ammo "bullet20 zenite" from "ap_light"}
{ammo "bullet25 zenite" from "ap_light"}
{ammo "bullet37 zenite" from "ap_light"}
{ammo "bullet40 zenite" from "ap_light"}
{ammo "bullet20 fg" 	from "fg_light"
	{detonationThickness 2}
	{damage blastwave
		{energy 0.5}		; kg
		{area 0.3 0.3}		; m
	}
}
{ammo "bullet20 ap" 	from "ap_light"}
{ammo "bullet20 az" 	from "az_light"}
{ammo "bullet25 ap" 	from "ap_light"}
{ammo "bullet37 ap" 	from "ap_light"}
{ammo "bullet37 az" 	from "az_light"}
{ammo "bullet37 fg" 	from "fg_light"
	{damage blastwave
		{energy 1}		; kg
		{area 1 2}		; m
	}
}
{ammo "bullet40 fg" 	from "fg_light"}
{ammo "bullet40 ap" 	from "ap_light"}
{ammo "bullet40 az" 	from "az_light"}
{ammo "bullet45 fg" 	from "fg_light"
	{damage blastwave
		{energy 1.2}		; kg
		{area 2 3}		; m
	}
}
{ammo "bullet45 ap" 	from "ap_light"}
{ammo "bullet45 az" 	from "az_light"}
{ammo "bullet47 fg" 	from "fg_medium"
	{damage blastwave
		{energy 1.3}		; kg
		{area 2 5}		; m
	}
}
{ammo "bullet50 fg" 	from "fg_medium"
	{damage blastwave
		{energy 1.4}		; kg
		{area 2 5}		; m
	}
}
{ammo "bullet47 ap" 	from "ap_light"}
{ammo "bullet50 ap" 	from "ap_light"}
{ammo "bullet50 az" 	from "az_light"}
{ammo "bullet57 fg" 	from "fg_medium"
	{damage blastwave
		{energy 1.5}		; kg
		{area 2 4}		; m
	}
}
{ammo "bullet57 ap" 	from "ap_light"}
{ammo "bullet75 fg" 	from "fg_medium"
	{damage blastwave
		{energy 2}		; kg
		{area 2 6}		; m
	}
}
{ammo "bullet75 ap" 	from "ap_light"}
{ammo "bullet76 fg" 	from "fg_medium"
	{damage blastwave
		{energy 2}		; kg
		{area 2 6}		; m
	}
}
{ammo "bullet76 ap" 	from "ap_light"}
{ammo "bullet76 sm" 	from "sm_light"}
{ammo "bullet77 ap" 	from "ap_light"}
{ammo "bullet77 fg" 	from "fg_medium"
	{damage blastwave
		{energy 2.1}		; kg
		{area 2 6}		; m
	}
}
{ammo "bullet85 fg" 	from "fg_heavy"}
{ammo "bullet85 ap" 	from "ap_heavy"}
{ammo "bullet88 fg" 	from "fg_heavy"}
{ammo "bullet88 ap" 	from "ap_heavy"}
{ammo "bullet90 ap" 	from "ap_heavy"}
{ammo "bullet90 fg" 	from "fg_heavy"}
{ammo "bullet93 ap" 	from "ap_heavy"}
{ammo "bullet93 fg" 	from "fg_heavy"}
{ammo "bullet95 ap" 	from "ap_heavy"}
{ammo "bullet95 fg"	from "fg_heavy"
	{damage blastwave
		{energy 8}
		{area 5 7}
	}
}
{ammo "bullet87 ap" 	from "ap_heavy"}
{ammo "bullet87 fg"	from "fg_heavy"
	{damage blastwave
		{energy 8}
		{area 5 7}
	}
}


{ammo "bullet100 ap" 	from "ap_heavy"}

{ammo "bullet100 fg" 	from "fg_heavy"
	{damage blastwave
		{energy 8}
		{area 5 7}
	}
}

{ammo "bullet105 fg"	from "fg_heavy"
	{damage blastwave
		{energy 8}
		{area 6 10}
	}
	("trace_big_shell")
}
{ammo "bullet120 ap" 	from "ap_heavy"}
{ammo "bullet120 fg"	from "fg_heavy"
	{damage blastwave
		{energy 8.5}
		{area 7 10}
	}
}
{ammo "bullet105 ap" 	from "ap_heavy"}
{ammo "bullet122 fg"	from "fg_heavy"
	{damage blastwave
		{energy 9}
		{area 7 10}
	}
}
{ammo "bullet122 ap" 	from "ap_heavy"
	("trace_big_shell")
}
{ammo "bullet127 fg"	from "fg_heavy"
	{damage blastwave
		{energy 9}
		{area 7 11}
	}
	("trace_big_shell")
}
{ammo "bullet127 ap"	from "ap_heavy"
	("trace_big_shell")
}
{ammo "bullet128 fg"	from "fg_heavy"
	{damage blastwave
		{energy 9}
		{area 7 11}
	}
	("trace_big_shell")
}
{ammo "bullet128 ap"	from "ap_heavy"
	("trace_big_shell")
}
{ammo "bullet140 fg"	from "fg_heavy"
	{damage blastwave
		{energy 9.5}
		{area 8 12}
	}
	("trace_extra_big_shell")
}
{ammo "bullet140 ap"	from "ap_heavy"}
{ammo "bullet150 fg"	from "fg_heavy"
	{damage blastwave
		{energy 10}
		{area 8 13}
	}
	("trace_extra_big_shell")
}
{ammo "bullet150 ap"	from "ap_heavy"}
{ammo "bullet152 fg"	from "fg_heavy"
	{damage blastwave
		{energy 10}		; kg
		{area 8 14}		; m
	}
	("trace_extra_big_shell")
}
{ammo "bullet155 ap"	from "ap_heavy"}
{ammo "bullet155 fg"	from "fg_heavy"
	{damage blastwave
		{energy 10}		; kg
		{area 8 14}		; m
	}
	("trace_extra_big_shell")
}
{ammo "bullet152 ap"	from "ap_heavy"}
{ammo "bullet152m10 fg" from "fg_heavy"
	{damage blastwave
		{energy 10}		; kg
		{area 8 14}		; m
	}
	("trace_extra_big_shell")
}
{ammo "bullet152m10 ap" from "ap_heavy"}
{ammo "bullet150m"		
	{detonationThickness 5}
	{damage blastwave
		{energy 11}		; kg
		{area 8 14}		; m
	}
	("trace_extra_big_shell")		
}

{ammo "bullet203"		
	{detonationThickness 6}
	{damage blastwave
		{energy 15}		; kg
		{area 8 15}		; m
	}
	("trace_extra_big_shell")		
}
{ammo "bullet220"		
	{detonationThickness 6}
	{damage blastwave
		{energy 16}		; kg
		{area 8 15}		; m
	}
	("trace_extra_big_shell")		
}
{ammo "bullet300"	from "fg_heavy"
	{view "300mm_ammo"
		{tail "rocket_smoke" "tail"}
	}
	{destroyViewWhenArrive}
	{detonationThickness 6}
	{damage blastwave
		{energy 25}
		{area 8 20}
	}
	("trace_extra_big_shell")
}
{ammo "bullet460"		
	{detonationThickness 6}
	{damage blastwave
		{energy 28}		; kg
		{area 8 25}		; m
	}
	("trace_extra_big_shell")		
}