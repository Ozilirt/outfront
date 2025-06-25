;SDL
;SDL

{weapon pattern "mgun" from "bullet"
	{aimRange 37}				; m
	{Spreading
		{SpreadRadius 3.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.1}			; s
	{rechargeTime 5.0}			; s
	{speed 200}					; m/s
	{piercing   10 4     30 3    100 0}
	{healthDamage 35}
	{traceFreq 0.8}
	{Automatic}
	{burst
		{short 4.5 1.5}
		{long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)

}
{weapon "browning" from "mgun"
	{fireSound	"mgun_shot.browning"}
	{reloadSound "reload.mg1_r"}
	{maxRange 60}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mg34" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{reloadSound "reload.mg1_r"}
	{maxRange 60}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mg34_tower" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{reloadSound "reload.mg1_r"}
	{maxRange 75}					; m
	{aimRange 100}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mg42" from "mgun"
	{fireSound	"mgun_shot.mg42"}
	{reloadSound "reload.mg1_r"}
	{maxRange 60}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "dt" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 60}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "dp" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 60}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "ds" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 60}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "bren" from "mgun"
	{fireSound	"mgun_shot.bren"}
	{rechargeTime 2.5}			; s
	{maxRange 60}					; m
	{Spreading
		{SpreadRadius 2.0}
	}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "bar" from "mgun"
	{fireSound	"mgun_shot.bar"}
	{reloadSound "reload.bar_r"}
	{rechargeTime 2}			; s
	{recoverytime 0.3}			; s
	{maxRange 60}					; m
	{Spreading
		{SpreadRadius 2.0}
	}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "doublecolt" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{maxRange 60}					; m
	{Spreading
		{SpreadRadius 1.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{reloadSound "reload.mg1_r"}
	(mod "mp"
		{maxRange}					; m
	)
}
{ammo "ammo mgun" from "ammo bullet"}

