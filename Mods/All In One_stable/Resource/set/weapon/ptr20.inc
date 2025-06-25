;SDL

{weapon pattern "ptr20" from "bullet"
	{reloadSound "reload.rifle"}
	{spreading
		{SpreadRadius 2.0}		; m
	}
        {states
		{fire	"fire-heavy_mgun"}
		{aim 	"aim-heavy_mgun"}
	}
	{recoveryTime 1}			; s
	{rechargeTime 4}			; s
	{speed 400}					; m/s
	{maxRange 150}					; m
	{aimRange 100}
	{healthing 5 300 10 300 25 300 50 250 150 100}
	{cursor "/interface/cursor/carbine_on.ebm"}
	{traceFreq 0.4}	
	{AimingTolerance 8}			; degree	
	{burst
		{short 1}
		{Long 1}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}

{weapon "type97at" from "ptr20"
	{aimRange 45}
	{spreading
		{SpreadRadius 1.8}		
	}
	{speed 400}
	{piercing   20 48  60 33   100 14 500 6}
	{rechargeTime 3}
	{recoveryTime 0.6}								
	{fireSound	"heavy_shot.20mm"}
	{cursor "/interface/cursor/mgun_on_3.ebm"}
}
{ammo "ammo ptr20"
	{trace
		{view "/fx/_bmp/trace.ebm"
			{ScaleY 1.2}
		}
		{length 1}
	}
}

