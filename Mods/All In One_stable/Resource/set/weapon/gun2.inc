
;SDL

(include "gun_ammo2.inc")

{weapon pattern "gun2"
	{type bullet}
	{foresight "Foresight2"}
	{aimRange 200}				; m
	{maxRange 200}					; m
	{minRange 2}				; m
	{spreading {SpreadRadius 5.0}	}	; m
	{healthing 20 3000 50 1000 100 500 200 100 500 0}
	{rechargeTime 5.0}			; s
	{speed 280}					; m/s
	{AimingTolerance 2}			; degree
	{RelaxationTime 0.5}
	{cursor "/interface/cursor/cannon_on_2.ebm"}
	(mod "mp"
		{maxRange 200}					; m
	)
}

{weapon "75mm_m32" from "gun2"     ; m3 lee
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange "heavy tank" 15}		; m
	{aimRange "tank" 30}			; m
	{aimRange 240}					; m
	{maxRange 240}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 7.5}}	; m
	{rechargeTime 4.6}				; s
	{speed 220}						; m/s
	{piercing  20 72 100 66 200 60 300 55 500 45}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 81 100 72 200 61 300 34 500 18}
	)
}
{weapon "75mm_sa35" from "gun2"     ; CharB1bis
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange "tank" 30}			; m
	{aimRange 240}					; m
	{maxRange 240}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 7.5}}	; m
	{rechargeTime 5.5}				; s
	{speed 220}						; m/s
	{piercing  20 72 100 66 200 55 300 45 500 25}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 72 100 66 200 55 300 45 500 25}
	)
}
{weapon "20mm_Polsten" from "gun2"		;Star
	{fireSound "heavy_shot.20mm"}
	{aimRange 200}					; m
	{maxRange 200}					; m
	{aimRange "tank"50}				; m
	{minRange 2}					; m
	{spreading {spreadradius 6.2}}	; m
        {automatic}
        {burst
		{min 3}
		{short 2.5 1}
		{long 7 2}
	}
        {RecoveryTime 0.25}
	{rechargeTime   4}				; s
	{piercing    20 45 100 15 200 8 500 5}
        {shellEnergy 3}
	(mod "mp"
		{piercing    20 34 100 21 200 9 500 3}
		{maxRange 200}					; m
		{speed 200}
		{spreading {spreadradius 6.2}}	; m
	)
}
{weapon "37mm_type94_2" from "gun2"	; Ho-Ri, Chi-Ri
	{fireSound "heavy_shot.37mmj"}
	{reloadSound "reload.pak35_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 7.0}}	; m
	{rechargeTime 3}				; s
	{speed 185}						; m/s
	{piercing  20 38 100 29 200 25 300 16 500 10}
        {shellEnergy 10}
	(mod "mp"
		{maxRange 200}					; m
		{rechargeTime 2}				; s
		{piercing  20 38 100 29 200 25 300 16 500 10}
	)
}