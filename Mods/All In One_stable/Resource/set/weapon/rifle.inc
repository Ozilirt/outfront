;SDL

{weapon pattern "rifle" from "bullet"
	{reloadSound "reload.rifle"}
	{spreading
		{SpreadRadius 1.3}		; m
	}
	{recoveryTime 1.5}			; s
	{rechargeTime 4.5}			; s
	{speed 200}					; m/s
	{aimrange 100}
	{maxRange 100}					; m
	{piercing   10 4  50 3  100 2}
	{healthing  10 100 25 90 50 75 100 50 150 0}
	{maxRange 100}					; m
	{cursor "/interface/cursor/snip_on.ebm"}
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
	{maxRange 100}					; m
	{reloadSound "reload.mauzer_r"}
	(mod "mp"
		{recoveryTime 2.1}			; s
		{maxRange}					; m
	)
}
{weapon "mauzer_kn" from "rifle"
	{fireSound "rifle_shot.mauzer"}
	{maxRange 100}					; m
	{reloadSound "reload.mauzer_r"}
	(mod "mp"
		{recoveryTime 2.1}			; s
		{maxRange}					; m
	)
}
{weapon "wz.98a" from "rifle"
	{fireSound "rifle_shot.wz98"}
	{maxRange 100}					; m
	{reloadSound "reload.mauzer_r"}
	(mod "mp"
		{recoveryTime 2.1}			; s
		{maxRange}					; m
	)
}
{weapon "mosin" from "rifle"
	{fireSound "rifle_shot.mosin"}
	{maxRange 100}	
	{reloadSound "reload.mosin_r"}
        {piercing   10 4.5   50 3.5  100 2}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 2.2}			; s
	)
}
{weapon "mosin_kn" from "rifle"
	{fireSound "rifle_shot.mosin"}
	{maxRange 100}	
	{reloadSound "reload.mosin_r"}
        {piercing   10 4.5   50 3.5  100 2}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 2.2}			; s
	)
}
{weapon "mas36_51" from "rifle"
	{fireSound "rifle_shot.mas36_51"}
	{maxRange 100}	
	{reloadSound "reload.mosin_r"}
        {piercing   10 4.5   50 3.5  100 2}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 2.2}			; s
	)
}
{weapon "enfieldmk3" from "rifle"
	{fireSound "rifle_shot.enfield"}
        {spreading
		{SpreadRadius 1.6}		; m
	}
	{maxRange 100}					; m
	{reloadSound "reload.enfield_r"}
        {healthing  10 100 25 80 50 65 100 40 150 0}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 1.2}			; s
	)
}
{weapon "enfield_kn" from "rifle"
	{fireSound "rifle_shot.enfield"}
        {spreading
		{SpreadRadius 1.6}		; m
	}
	{maxRange 100}					; m
	{reloadSound "reload.enfield_r"}
        {healthing  10 100 25 80 50 65 100 40 150 0}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 1.2}			; s
	)
}
{weapon "Springfield" from "rifle"
	{fireSound "rifle_shot.Springfield"}
	{maxRange 100}	
	{reloadSound "reload.mosin_r"}
        {piercing   10 4.5   50 3.5  100 2}
        {healthing  10 100 25 90 50 80 100 55 150 0}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 2.1}			; s
	)
}
{weapon "arisaka" from "rifle"
	{fireSound "rifle_shot.arisaka"}
	{maxRange 100}	
	{reloadSound "reload.mauzer_r"}
        {piercing   10 4.5   50 3.5  100 2}
        {healthing  10 100 25 90 50 80 100 55 150 0}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 2.0}			; s
	)
}
{weapon "arisaka_kn" from "rifle"
	{fireSound "rifle_shot.arisaka"}
	{maxRange 100}	
	{reloadSound "reload.mauzer_r"}
        {piercing   10 4.5   50 3.5  100 2}
        {healthing  10 100 25 90 50 80 100 55 150 0}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 2.0}			; s
	)
}
{weapon "type38" from "rifle"
	{fireSound "rifle_shot.type38"}
	{maxRange 95}	
	{reloadSound "reload.mosin_r"}
        {piercing   10 4.5   50 3.5  100 2}
        {healthing  10 100 25 90 50 80 100 55 150 0}
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 1.9}			; s
	)
}
;=================AutomaticRifle=============
{weapon "m1" from "rifle"
	{fireSound "rifle_shot.m1"}
	{reloadSound "reload.m1_r"}			; s
        {spreading
		{SpreadRadius 2.0}		; m
	}
	{healthing  10 90 25 70 50 60 100 40 150 0}
        {recoveryTime 0.9}	
	{rechargeTime 3.5}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m1_kn" from "rifle"
	{fireSound "rifle_shot.m1"}
	{reloadSound "reload.m1_r"}			; s
        {spreading
		{SpreadRadius 2.0}		; m
	}
	{healthing  10 90 25 70 50 60 100 40 150 0}
        {recoveryTime 0.9}	
	{rechargeTime 3.5}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m1c" from "rifle"
	{fireSound "rifle_shot.m1"}
        {recoveryTime 2.8}	
	{rechargeTime 3.5}
	{maxRange 120}					; m
	{reloadSound "reload.m1_r"}
	{spreading
		{SpreadRadius 1.5}		; m
	}
	{piercing   100 4   200 3.5  400 3}
	{healthing   10 110  25 90  50 75  100 65  150 40  200 30}
	{speed 250}					; m/s
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m1_carbine" from "rifle"
	{fireSound "rifle_shot.m1carbine"}
	{maxRange 100}	
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.35}			; s
	{rechargeTime 3.5}
	{spreading
		{SpreadRadius 2.5}		; m
	}
        {healthing  10 80  25 65  50 50  100 35  150 0}
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "m2_carbine" from "rifle"
	{fireSound "rifle_shot.m1carbine"}
	{maxRange 100}	
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.35}			; s
	{rechargeTime 3.5}
	{spreading
		{SpreadRadius 2.5}		; m
	}
        {healthing  10 80  25 65  50 50  100 35  150 0}
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "type5" from "rifle"
	{fireSound "rifle_shot.type5"}
	{reloadSound "reload.m1carbine_r"}			; s
        {spreading
		{SpreadRadius 2.1}		; m
	}
	{healthing  10 90 25 70 50 60 100 40 150 0}
        {recoveryTime 0.75}	
	{rechargeTime 4.5}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "g43" from "rifle"
	{fireSound "rifle_shot.k43"}
	{maxRange 100}	
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.5}			; s
	{rechargeTime 3.1}
        {spreading
		{SpreadRadius 2.3}		; m
	}
	{healthing  10 90 25 80 50 70 100 50 150 0}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "g41automatic" from "rifle"
	{fireSound "rifle_shot.g41"}
	{maxRange 100}	
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.7}			; s
	{rechargeTime 3.0}
        {spreading
		{SpreadRadius 2.3}		; m
	}
	{healthing  10 90 25 80 50 70 100 50 150 0}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "svtautomatic" from "rifle"
	{fireSound "rifle_shot.svt"}
	{maxRange 100}
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.55}			; s
	{rechargeTime 3.5}
        {spreading
		{SpreadRadius 2.3}		; m
	}
	{healthing  10 95 25 85 50 75 100 60 150 0}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "avs" from "rifle"
	{fireSound "rifle_shot.avs"}
        {spreading
		{SpreadRadius 2.4}              ;m
		{SpreadXYRatio	2.0}
		{SpreadPower	2.4}

	}
	{maxRange 100}
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.5}			; s
	{rechargeTime 3.0}
        {healthing  10 90 25 80 50 70 100 60 150 0}
        {burst
		{short 2 1}
		{long 1 7}
	}	
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "johnson1941" from "rifle"
	{fireSound "mgun_shot.johnsonlightgun"}
	{maxRange 100}
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.5}			; s
	{rechargeTime 3.0}
        {spreading
		{SpreadRadius 2.1}		; m
	}
        {healthing  10 100 25 90 50 80 100 65 150 0}
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "fg42" from "rifle"
	{fireSound "rifle_shot.fg42"}
        {spreading
		{SpreadRadius 2.25}              ;m
		{SpreadXYRatio	1.6}
		{SpreadPower	2.2}

	}
	{maxRange 100}
	{reloadSound "reload.m1carbine_r"}
	{recoveryTime 0.18}			; s
	{rechargeTime 2.4}
        {healthing  10 90 25 80 50 70 100 60 150 0}
        {burst
		{short 2.5 1.5}
		{long 1.5 7.5}
	}	
	{Automatic}
	(mod "mp"
		{maxRange}					; m
	)
}
;===========================Sniper Rifle====================
{weapon pattern "sniper_rifle" from "rifle"
	{aimRange 150}				; m
	{maxRange 150}					; m
	{piercing   100 5   200 5  400 1}
	{healthing   10 200  25 185  50 160  100 150  150 100  200 50}
	{recoveryTime 8}			; s
	{rechargeTime 4}			; s
	{speed 300}					; m/s
	{spreading
		{SpreadRadius 0.3}		; m
	}
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "kar98zf4.1" from "sniper_rifle"
	{fireSound "rifle_shot.mauzer"}
        {reloadSound "reload.mauzer_r"}
	{aimRange 150}				; m
	{maxRange 150}					; m
	{piercing   100 5   200 5  400 1}
	{healthing   10 200  25 185  50 160  100 150  150 100  200 50}
	{recoveryTime 8}			; s
	{rechargeTime 4.5}			; s
	{speed 300}					; m/s
	{spreading
		{SpreadRadius 0.25}		; m
	}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "mosin_m91-30" from "sniper_rifle"
	{fireSound "rifle_shot.mosin"}	
        {reloadSound "reload.mosin_r"}
	{aimRange 150}				; m
	{maxRange 150}					; m
	{piercing   100 5   200 5  400 1}
	{healthing   10 200  25 190  50 170  100 150  150 100  200 50}
	{recoveryTime 8}			; s
	{rechargeTime 4.5}			; s
	{speed 300}					; m/s
	{spreading
		{SpreadRadius 0.25}		; m
	}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "g41" from "sniper_rifle"
	{fireSound "rifle_shot.g41"}
	{aimRange 100}				; m
	{maxRange 100}					; m
	{piercing   100 4   200 4  400 0}
	{healthing   10 130  25 120  50 110  100 100  150 50  200 0}
	{recoveryTime 1.1}			; s
	{rechargeTime 3.1}			; s
	{speed 250}					; m/s
	{spreading
		{SpreadRadius 1}		; m
	}
	{maxRange 100}					; m
	(mod "mp"
		{maxRange 100}					; m
	)
}
{weapon "svt" from "sniper_rifle"
	{fireSound "rifle_shot.svt2"}
	{aimRange 100}				; m
	{maxRange 100}					; m
	{piercing   100 5   200 4  400 0}
	{healthing   10 130  25 120  50 110  100 100  150 50  200 0}
	{recoveryTime 1.2}			; s
	{rechargeTime 3.5}			; s
	{speed 250}					; m/s
	{spreading
		{SpreadRadius 1}		; m
	}	
	{maxRange 100}					; m
	(mod "mp"
		{maxRange 100}					; m
	)
}
{weapon "enfield" from "sniper_rifle"
	{fireSound "rifle_shot.enfield2"}
        {reloadSound "reload.enfield_r"}
	{aimRange 100}				; m
	{maxRange 100}					; m
	{piercing   100 5   200 4  400 0}
	{healthing   10 130  25 120  50 110  100 100  150 50  200 0}
	{recoveryTime 1.2}			; s
	{rechargeTime 3.5}			; s
	{speed 250}					; m/s
	{spreading
		{SpreadRadius 1}		; m
	}					; m
	(mod "mp"
		{maxRange 100}					; m
	)
}
{weapon "m1903a4" from "sniper_rifle"
	{fireSound "rifle_shot.m1903a4"}
	{reloadSound "reload.mosin_r"}
	{aimRange 150}				; m
	{maxRange 150}					; m
	{piercing   100 5   200 4  400 1}
	{healthing   10 200  25 190  50 170  100 150  150 100  200 50}
	{recoveryTime 8}			; s
	{rechargeTime 4}			; s
	{speed 300}					; m/s
	{spreading
		{SpreadRadius 0.25}		; m
	}							; m
	(mod "mp"
		{maxRange}					; m
		{recoveryTime 8}			; s
	)
}
{weapon "arisaka_scoped" from "sniper_rifle"
	{fireSound "rifle_shot.arisakasc"}	
        {reloadSound "reload.mosin_r"}
	{aimRange 150}				; m
	{maxRange 150}					; m
	{piercing   100 5   200 5  400 1}
	{healthing   10 200  25 190  50 170  100 150  150 100  200 50}
	{recoveryTime 8}			; s
	{rechargeTime 4.5}			; s
	{speed 280}					; m/s
	{spreading
		{SpreadRadius 0.25}		; m
	}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "super_gun" from "sniper_rifle"
	{fireSound "rifle_shot.mosin"}
	{recoveryTime 8}			; s
	(mod "mp"
		{maxRange}					; m
	)
}

{ammo "ammo rifle" from "ammo bullet"}



