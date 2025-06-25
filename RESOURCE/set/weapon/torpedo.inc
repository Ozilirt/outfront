;SDL

{ammo "ammo torpedo"}

{weapon "weapon torpedo"
	{type bullet}
	{foresight "foresight1"}
	{aimRange 200}				; m
	{minRange 20}				; m
	{rechargeTime 1.0}			; s
	{spreading
		{SpreadRadius 10.0}	; m
	}
	{speed 40}					; m/s
	{AimingTolerance 5}			; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}
