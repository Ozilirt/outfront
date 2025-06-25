;SDL

{ammo "ammo katusha"
	{view "katusha_ammo"
		{tail "rocket_smoke" "tail"}
	}
	{destroyViewWhenArrive}
	{detonationThickness 6}
	{damage blastwave
		{energy 8.0}	; kg
		{area 4 10}		; m
	}
}

{weapon "weapon katusha"
	{type bullet}
	{fireSound "heavy_shot.bm13"}
	{foresight "foresight"}
	{aimRange 800}				; m
	{minRange 140}				; m
	{spreading
		{SpreadRadius 20.0}	; m
	}
	{burst {min 8}}
	{gravity 0.2}
	{rechargeTime 3.0}			; s
	{recoveryTime 1.0}			; s
	{piercing	100 120  200 100  300 0 }
	{speed 32}					; m/s
	{AimingTolerance 0.1}		; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}

{ammo "ammo nebel"
	{view "nebel_ammo"
		{tail "rocket_smoke" "tail"}
	}
	{destroyViewWhenArrive}
	{detonationThickness 6}
	{damage blastwave
		{energy 8.0}	; kg
		{area 4 10}		; m
	}
}

{weapon "weapon nebel"
	{type bullet}
	{fireSound "heavy_shot.bm13"}
	{foresight "foresight"}
	{aimRange 800}				; m
	{minRange 50}				; m
	{spreading
		{SpreadRadius 10.0}	; m
	}
	{burst {min 3}}
	{gravity 0.2}
	{rechargeTime 5.0}			; s
	{recoveryTime 0.5}			; s
	{piercing	100 120  200 100  300 0 }
	{speed 20}					; m/s
	{AimingTolerance 0.1}		; degree
	{parabolic}
	{cursor "/interface/cursor/cannon_on.ebm"}
}

