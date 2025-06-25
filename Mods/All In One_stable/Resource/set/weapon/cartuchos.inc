
;========================cartuchos======================================

{weapon  "cartuchos" from "bullet"
	{aimRange 60}				; m
	{spreading
		{SpreadRadius 1.2}; m
	}
	{recoveryTime 0.1}			; s
	{rechargeTime 3.0}			; s
	{speed 150}
	{maxRange 30}					; m					; m/s
	{piercing    10 15  20 10  30 8  40 6  100 4}
	{healthing  5 200 10 185 15 140 20 100 25 80 30 30}
	{traceFreq 1.0}
        {cursor "/interface/cursor/mgun_on_3.ebm"}
	{burst
		{short 1}
		{Long 1}
	}	
	(mod "mp"
		{maxRange}					; m
	)

}

{weapon "shotgun" from "cartuchos"
	{fireSound	"smg_shot.shotgun"}
	{reloadSound "reload.shotgun_r"}	
        {aimRange 20}	
	{maxRange 30}					; m
        {speed 150}
        {traceFreq 0.4}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "winchester1912" from "cartuchos"
	{fireSound	"smg_shot.winchester"}
	{reloadSound "reload.winchester_r"}
	{recoveryTime 0.9}			; s
	{rechargeTime 5.0}			; s	
        {aimRange 20}	
	{maxRange 22}					; m
        {speed 150}
        {traceFreq 0.4}
	(mod "mp"
		{maxRange}					; m
	)
}
{ammo "ammo cartuchos"
	{trace
		{view "/fx/_bmp/trace.ebm"
			{Light 0.6}
		}
		{length 1}
	}
}