

;SDL

{weapon pattern "smg" from "bullet"
	{aimRange 30}				; m
	{spreading
		{SpreadRadius 2.5}; m
		{SpreadXYRatio	2.5}
		{SpreadPower	3}

	}
	{recoveryTime 0.1}			; s
	{rechargeTime 2}			; s
	{speed 220}					; m/s
	{Automatic}
	{maxRange 40}					; m
	{traceFreq 0.4}
	{piercing   10 3  30 2   60 0}
	{healthDamage 25}
	{burst
		{short 2.5 1.5}
		{long 7.5 1.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}

{weapon "ppsh" from "smg"
	{fireSound	"smg_shot.ppsh"}
	{reloadSound "reload.ppsh_r"}
	{aimRange 35}				; m
	{maxRange 40}					; m
	{spreading
		{SpreadRadius 2.0}; m
		{SpreadPower	3}

	}
	{recoveryTime 0.1}			; s
	{rechargeTime 3}			; s
	{speed 230}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 4  30 3   70 0}
	{healthDamage 25}
	{burst
		{short 2.5 1.5}
		{long 7.5 1.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "sg44" from "smg"
	{fireSound	"smg_shot.mp44"}
	{reloadSound "reload.mp44_r"}
	{aimRange 35}				; m
	{maxRange 40}					; m
	{spreading
		{SpreadRadius 2.0}; m
		{SpreadXYRatio	2.5}
		{SpreadPower	3}

	}
	{recoveryTime 0.1}			; s
	{rechargeTime 2}			; s
	{speed 230}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 4  30 3   60 0}
	{healthDamage 30}
	{burst
		{short 2.5 1.5}
		{long 7.5 1.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m3a" from "smg"
	{fireSound	"smg_shot.mp44"}
	{maxRange 40}					; m
	{reloadSound "reload.mp44_r"}
}
{weapon "sten" from "smg"
	{fireSound	"smg_shot.sten"}
	{reloadSound "reload.sten_r"}
	{maxRange 40}					; m
	{aimRange 30}				; m
	{spreading
		{SpreadRadius 3.0}; m
		{SpreadPower	3}

	}
	{recoveryTime 0.1}			; s
	{rechargeTime 3}			; s
	{speed 220}					; m/s
	{Automatic}
	{traceFreq 0.5}
	{piercing   10 3  30 3   70 0}
	{healthDamage 22}
	{burst
		{short 2.5 1.5}
		{long 7.5 1.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mp40" from "smg"
	{maxRange 40}					; m
	{fireSound	"smg_shot.mp40"}
}
{weapon "mp41" from "smg"
	{maxRange 40}					; m
	{fireSound	"smg_shot.mp41"}
}
{weapon "thompson" from "smg"
	{maxRange 40}					; m
	{fireSound	"smg_shot.thompson"}
}