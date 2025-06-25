{weapon pattern "weapon mortar"
	{type bullet}
	{states
		{reload	"reload-mortar"}
		{unload	"unload-mortar"}
		{fire	"fire-mortar"	}
		{aim 	"aim-mortar"	}
	}
	{fireSound "heavy_shot.mortar_80"}
	{minRange 5}				; m
	{aimRange 200}				; m
	{Spreading
		{SpreadRadius 10}
	}
	{foresight "Foresight2"}
	{recoveryTime 0.1}			; s
	{rechargeTime 1.0}			; s
	{speed 30}					; m/s
	{gravity 2.6}
	{parabolic}
	{AimingTolerance 5}			; degree
	{piercing   10 7     50 7    100 7    200 7}
	(mod "mp"
		{maxRange}					; m
		{piercing   10 7     50  7    100 7   200 7}

	)
}

{weapon "weapon mortar_50mm" from "weapon mortar"
	{aimRange 100}				; m
        {maxRange 100}
	{Spreading
		{SpreadRadius 10}
	}
	{foresight "Foresight2"}
	{rechargeTime 1.5}			; s
	{speed 29.5}					; m/s
	{gravity 2.6}
}