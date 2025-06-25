;SDL

{weapon pattern "MGUN_12.7" from "bullet"
	{aimRange 160}				; m
	{Spreading
		{SpreadRadius 5.5}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.15}			; s
	{rechargeTime 9.0}			; s
	{speed 250}					; m/s
	{piercing    10 15  20 10  30 8  40 6  100 4}
	{healthing  5 300 25 285 50 240 100 183 150 100 250 80}
	{traceFreq 2.0}
        {AimingTolerance 8}
	{Automatic}
        {cursor "/interface/cursor/mgun_on_3.ebm"}
	{burst
		{short 5  2}
		{long  8  3}
	}	
	(mod "mp"
		{maxRange 160}					; m
	)

}
{weapon "50cal" from "MGUN_12.7"
	{fireSound	"mgun_shot.50cal"}
	{reloadSound "reload.mg1_r"}	
	{burst
		{min 5}
	}
	{rechargeTime 10.0}
        {recoverytime 0.135}			; s
	{piercing    10 16  20 11  30 8  40 5  100 3}
        {healthing  5 300 25 285 50 240 100 183 150 100 250 80}
        {aimRange 160}	
	{maxRange 160}					; m
        {speed 230}
	{Spreading
		{SpreadRadius 6.8}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 160}					; m
		{healthing  5 300 25 285 50 240 100 183 150 100 250 80}
	)
}
{weapon "50cal_dual" from "MGUN_12.7"
	{fireSound	"mgun_shot.50cal"}
	{reloadSound "reload.mg1_r"}	
	{burst
		{min 4}
	}
	{rechargeTime 12.0}
        {recoverytime 0.135}			; s
	{piercing    10 16  20 11  30 8  40 5  100 3}
        {healthing  5 300 25 285 50 240 100 183 150 100 250 80}
        {aimRange 160}	
	{maxRange 160}					; m
        {speed 230}
	{Spreading
		{SpreadRadius 6.6}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 160}					; m
		{healthing  5 300 25 285 50 240 100 183 150 100 250 80}
	)
}
{weapon "50cal_tower" from "MGUN_12.7"
	{fireSound	"mgun_shot.50cal"}
	{reloadSound "reload.mg1_r"}	
	{burst
		{min 3}
	}
	{rechargeTime 6.0}
        {recoverytime 0.135}			; s
	{piercing    10 16  20 11  30 8  40 5  100 3}
        {healthing  5 300 25 285 50 240 100 183 150 100 250 80}
        {aimRange 200}	
	{maxRange 200}					; m
        {speed 230}
	{Spreading
		{SpreadRadius 6.8}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 200}					; m
		{healthing  5 300 25 285 50 240 100 183 150 100 250 80}
	)
}
{weapon "DSHK" from "MGUN_12.7"
	{fireSound	"mgun_shot.DSHK"}
	{reloadSound "reload.mg1_r"}	
	{burst
		{min 3}
	}
	{rechargeTime 6.2}
        {recoverytime 0.15}			; s
	{piercing    10 19  20 14  30 10  40 6  100 4}
	{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
        {aimRange 160}	
	{maxRange 160}					; m
        {speed 250}
	{Spreading
		{SpreadRadius 7.0}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 160}					; m
		{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
	)
}
{weapon "DSHK_tower" from "MGUN_12.7"
	{fireSound	"mgun_shot.DSHK"}
	{reloadSound "reload.mg1_r"}	
	{burst
		{min 3}
	}
	{rechargeTime 6.2}
        {recoverytime 0.15}			; s
	{piercing    10 19  20 14  30 10  40 6  100 4}
	{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
        {aimRange 200}	
	{maxRange 200}					; m
        {speed 250}
	{Spreading
		{SpreadRadius 7.0}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 200}					; m
		{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
	)
}
{weapon "type93mg" from "MGUN_12.7"
	{fireSound	"mgun_shot.type93"}
	{reloadSound "reload.dt1_r"}	
	{burst
		{min 3}
	}
	{rechargeTime 7.0}
        {recoverytime 0.135}			; s
	{piercing    10 20  20 15  30 11  40 7  100 5}
	{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
        {aimRange 160}	
	{maxRange 160}					; m
        {speed 235}
	{Spreading
		{SpreadRadius 6.8}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 160}					; m
		{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
	)
}
{weapon "type93mg_tower" from "MGUN_12.7"
	{fireSound	"mgun_shot.type93"}
	{reloadSound "reload.dt1_r"}	
	{burst
		{min 3}
	}
	{rechargeTime 7.0}
        {recoverytime 0.135}			; s
	{piercing    10 20  20 15  30 11  40 7  100 5}
	{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
        {aimRange 200}	
	{maxRange 200}					; m
        {speed 235}
	{Spreading
		{SpreadRadius 6.8}
	}
        {traceFreq 1.5}
	(mod "mp"
		{maxRange 160}					; m
		{healthing  5 320 25 295 50 250 100 180 150 100 250 80}
	)
}
{ammo "ammo mgun_12.7"
        {trace
		{view "/fx/_bmp/trace.ebm"
			{ScaleY 1.2}
		}
		{length 1}
	}
}
{ammo "ammo mgun2"
        {trace
		{view "/fx/_bmp/trace.ebm"
			{ScaleY 1.2}
		}
		{length 1}
	}
}