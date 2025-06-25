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

{ammo pattern "ap_light2"
	{damage blastwave
		{energy 0.3}	; kg
		{area 0 0.5}		; m
	}
	("trace_shell")
}


{ammo pattern "fg_medium2"
	{detonationThickness 2}
	{damage blastwave
		{energy 2}		; kg
		{area 2 6}		; m
	}
	("trace_shell")
}


{ammo "bullet75 fg2" 	from "fg_medium2"}
{ammo "bullet75 ap2" 	from "ap_light2"}
{ammo "bullet21 ap2"	from "ap_light2"}

		


