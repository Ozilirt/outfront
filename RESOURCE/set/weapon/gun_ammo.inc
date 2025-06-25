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
		{area 0 1}		; m
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
		{energy 1}		; kg
		{area 2 5}		; m
	}
	("trace_shell")
}
{ammo pattern "fg_medium"
	{detonationThickness 2}
	{damage blastwave
		{energy 2}		; kg
		{area 2 4}		; m
	}
	("trace_shell")
}
{ammo pattern "fg_heavy"
	{detonationThickness 2}
	{damage blastwave
		{energy 5}		; kg
		{area 4 6}		; m
	}
	("trace_big_shell")
}

{ammo "bullet20 zenite" from "ammo ptr"}
{ammo "bullet20 fg" 	from "fg_light"}
{ammo "bullet20 ap" 	from "ap_light"}
{ammo "bullet37 ap" 	from "ap_light"}
{ammo "bullet45 fg" 	from "fg_light"}
{ammo "bullet45 ap" 	from "ap_light"}
{ammo "bullet50 fg" 	from "fg_medium"}
{ammo "bullet50 ap" 	from "ap_light"}
{ammo "bullet57 fg" 	from "fg_medium"}
{ammo "bullet57 ap" 	from "ap_light"}
{ammo "bullet75 fg" 	from "fg_medium"}
{ammo "bullet75 ap" 	from "ap_light"}
{ammo "bullet76 fg" 	from "fg_medium"}
{ammo "bullet76 ap" 	from "ap_light"}

{ammo "bullet85 fg" 	from "fg_medium"}
{ammo "bullet85 ap" 	from "ap_heavy"}
{ammo "bullet88 fg" 	from "fg_medium"}
{ammo "bullet88 ap" 	from "ap_heavy"}
{ammo "bullet90 ap" 	from "ap_heavy"}
{ammo "bullet90 fg" 	from "fg_medium"}
{ammo "bullet122 fg"	from "fg_medium"}
{ammo "bullet122 ap" 	from "ap_heavy"}

{ammo "bullet128 fg"	from "fg_heavy"}
{ammo "bullet128 ap"	from "ap_heavy"}
{ammo "bullet150 fg"	from "fg_heavy"}
{ammo "bullet150 ap"	from "ap_heavy"}
{ammo "bullet152 fg"	from "fg_heavy"
	{damage blastwave
		{energy 6}		; kg
		{area 4 7}		; m
	}
}
{ammo "bullet152 ap"	from "ap_heavy"}
{ammo "bullet152m10 fg" from "fg_heavy"}
{ammo "bullet152m10 ap" from "ap_heavy"}
{ammo "bullet203"		
	{detonationThickness 6}
	{damage blastwave
		{energy 18}		; kg
		{area 4 6}		; m
	}
	("trace_extra_big_shell")		
}

