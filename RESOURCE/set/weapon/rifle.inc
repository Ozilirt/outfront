;SDL

{weapon pattern "rifle" from "bullet"
	{reloadSound "reload.rifle"}
	{aimRange 45}				; m
	{spreading
		{SpreadRadius 0.5}		; m
	}
	{recoveryTime 2}			; s
	{rechargeTime 4}			; s
	{speed 250}					; m/s
	{maxRange 45}					; m
	{piercing   10 5   50 3  100 0}
	{healthDamage 100}
	{maxRange 75}					; m
	{cursor "/interface/cursor/carbine_on.ebm"}
	{burst
		{short 1}
		{Long 1}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mauzer" from "rifle"
	{fireSound "rifle_shot.mauzer"}
	{maxRange 75}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m1" from "rifle"
	{fireSound "rifle_shot.m1"}
	{reloadSound "reload.m1_r"}
	{recoveryTime 0.4}			; s
	{healthDamage 45}
	{rechargeTime 4}
	{maxRange 75}					; m
	{Automatic}
	{speed 250}					; m/s
	{piercing   10 1.3   35 0.9  100 0}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mosin" from "rifle"
	{fireSound "rifle_shot.mosin"}
	{maxRange 75}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon pattern "sniper_rifle" from "mauzer"
	{aimRange 50}				; m
	{maxRange 100}					; m
	{spreading
		{SpreadRadius 0.3}		; m
	}
	{piercing   10 6   50 4  100 0}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "g41" from "sniper_rifle"
	{fireSound "rifle_shot.g41"}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "svt" from "sniper_rifle"
	{fireSound "rifle_shot.svt"}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "enfield" from "sniper_rifle"
	{fireSound "rifle_shot.enfield"}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m1_carbine" from "rifle"
	{fireSound "rifle_shot.m1carbine"}
	{maxRange 65}					; m
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.4}			; s
	{rechargeTime 2}
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "super_gun" from "sniper_rifle"
	{fireSound "rifle_shot.mosin"}
	{recoveryTime 0}			; s
	{healthDamage 100}
	(mod "mp"
		{maxRange}					; m
	)
}

{ammo "ammo rifle" from "ammo bullet"}


{weapon "ptrd" from "rifle"
	{maxRange 55}					; m
	{aimRange 40}				; m
	{spreading
		{SpreadRadius 1}		; m
	}
	{rechargeTime 3.5}			; s
	{piercing   10 50     50 40    150 0}
	{fireSound	"rifle_shot.ptrs"}
	{reloadSound "reload.ptrd_r"}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "ptrs" from "ptrd"
	{rechargeTime 5.0}			; s
	{maxRange 55}					; m
	{reloadSound "reload.ptrs_r"}
	(mod "mp"
		{maxRange}					; m
	)
}

{ammo "ammo ptr"
	{trace
		{view "/fx/_bmp/trace.ebm"
;			{Light 0.2}
			{ScaleY 1.8}
		}
		{length 1}
	}
}
