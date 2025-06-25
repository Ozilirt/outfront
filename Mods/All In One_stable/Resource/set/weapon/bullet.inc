;SDL

{weapon	pattern "bullet"
	{type bullet}
	{states
		{reload		"reload"}
		{unload		"unload"}
		{fire		"fire"	}
		{aim 		"aim"	}
	}
	{Spreading
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 0 0 0 0 0}
		{burstSpreadWidth 1}
		{burstSpreadDelta 1}
		{burstSpreadCount 5}
		{SpreadRadius 5}
	}
	{reloadSound "reload.smg"}
	{foresight "Foresight3"}
	{minRange 0.1}				; m
	{speed 200}					; m/s
    {AimingTolerance 5}			; degree
	{cursor "/interface/cursor/mgun_on.ebm"}
}

{ammo pattern "ammo bullet"
	{trace
		{view "/fx/_bmp/trace.ebm"
			{Light 0.6}
;			{ScaleY 1.4}
		}
		{length 1}
	}
}
