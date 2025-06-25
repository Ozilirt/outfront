;SDL

{weapon pattern "ptr" from "bullet"
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


{weapon "ptrd" from "ptr"
	{aimRange 50}	
	{rechargeTime 5}
        {recoveryTime 0.9}
	{speed 400}			; s
 	{piercing   20 42  60 30   100 12 500 6}
	{fireSound	"rifle_shot.ptrs"}
	{reloadSound "reload.ptrd_r"}
}

{weapon "ptrs" from "ptrd"
	{maxRange 100}
	{aimRange 60}				
	{recoveryTime 0.6}			
	{rechargeTime 4}			
	{speed 400}					
	{piercing   20 40  60 28   100 11 500 6}
	{fireSound	"rifle_shot.ptrs"}
	{reloadSound "reload.rifle"}
	{cursor "/interface/cursor/carbine_on.ebm"}
}

{weapon "pzb39" from "ptrd"
	{aimRange 40}
	{spreading
		{SpreadRadius 1.3}		
	}
	{speed 400}
	{piercing   20 30  60 22   100 8 500 4}
	{rechargeTime 2.5}
	{recoveryTime 0.6}								
	{fireSound	"rifle_shot.pzb39"}
}

{weapon "boys" from "ptrd"
	{aimRange 40}
	{spreading
		{SpreadRadius 1.8}		
	}
	{speed 400}
	{piercing   20 34  60 24   100 10 500 4}
	{rechargeTime 3}
	{recoveryTime 0.6}								
	{fireSound	"rifle_shot.ptrs"}
}
{ammo "ammo ptr"
	{trace
		{view "/fx/_bmp/trace.ebm"
;			{Light 0.2}
			{ScaleY 1.2}
		}
		{length 1}
	}
}

