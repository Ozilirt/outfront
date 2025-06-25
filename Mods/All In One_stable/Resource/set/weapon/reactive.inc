;SDL
{ammo "ammo torp"
	{view "torp_ammo"
		{tail "wash_torpedo_small"}
	}
	{destroyViewWhenArrive}
	{detonationThickness 6}
	{damage blastwave
		{energy 8.0}	; kg
		{area 4 10}		; m
	}
}

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
	(mod "mp"
		{rechargeTime 15.0}		; s
		{spreading
			{SpreadRadius 60.0}	; m
			{SpreadXYRatio 1.5}
		}
		{speed 25.5}				; m/s
	)
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

{weapon "weapon nebel10"
	{type bullet}
	{fireSound "heavy_shot.bm13"}
	{foresight "foresight"}
	{aimRange 800}				; m
	{minRange 50}				; m
	{spreading
		{SpreadRadius 50.0}	; m
		{SpreadXYRatio 1.5}
	}
	{burst {min 5}}
	{gravity 0.2}
	{rechargeTime 15.0}			; s
	{recoveryTime 0.5}			; s
	{piercing	100 120  200 100  300 0 }
	{speed 23}					; m/s
	{AimingTolerance 0.1}		; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}

{ammo "ammo calliope"
	{view "bazooka_ammo"
		{tail "rocket_smoke_norm" "tail"}
	}
	{destroyViewWhenArrive}
	{detonationThickness 6}
	{damage blastwave
		{energy 5.0}	; kg
		{area 3 5}		; m
	}
}

{weapon "weapon calliope"
	{type bullet}
	{fireSound "smg_shot.grenade"}
	{foresight "foresight"}
	{aimRange 300}				; m
	{minRange 50}				; m
	{spreading
		{SpreadRadius 30.0}	; m
	}
	{burst {min 30}}
	{gravity 0.2}
	{rechargeTime 15.0}			; s
	{recoveryTime 0.2}			; s
	{piercing	100 120  200 100  300 0 }
	{speed 21}					; m/s
	{AimingTolerance 0.1}		; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}

