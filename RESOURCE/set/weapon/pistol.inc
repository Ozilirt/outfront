;SDL

{weapon pattern "pistol" from "bullet"
	{aimRange 18}				; m
	{recoveryTime 0.3}			; s
	{rechargeTime 3}			; s
	{maxRange 30}				; m
	{spreading
		{SpreadRadius 1} ; m
	}
	{speed 150}					; m/s
	{healthDamage 35}
	{piercing   10 3  20 2 40 0}
	{burst
		{short 1.5 0.5}
		{long 3.5 0.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}

{weapon "valter" from "pistol"
	{fireSound	"pistol_shot.valter"}
	{maxRange 30}				; m
	{reloadSound "reload.pistol_r"}
}

{weapon "tt" from "pistol"
	{fireSound	"pistol_shot.tt"}
	{maxRange 30}				; m
	{reloadSound "reload.pistol_r"}
}
{weapon "colt" from "pistol"
	{fireSound	"pistol_shot.colt"}
	{reloadSound "reload.colt_r"}
	{maxRange 30}				; m
	{rechargeTime 2}			; s
}
{weapon "webley" from "pistol"
	{fireSound	"pistol_shot.tt"}
	{maxRange 30}				; m
	{reloadSound "reload.webley_r"}
}
{weapon "nagan" from "pistol"
	{fireSound	"pistol_shot.nagan"}
	{maxRange 30}				; m
	{reloadSound "reload.nagan_r"}
}

{weapon "welrod" from "pistol"
	{fireSound	"pistol_shot_silent.welrod"}
	{maxRange 30}				; m
	{spreading
		{SpreadRadius 0.5} ; m
	}
	{reloadSound "reload.welrod_r"}
	{piercing   10 3   15 0.2  100 0}
	(mod "mp"
		{maxRange}					; m
	)
}

{ammo "ammo pistol" from "ammo bullet"}
