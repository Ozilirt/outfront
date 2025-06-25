;SDL

{ammo "ammo bazooka"
	{view "bazooka_ammo"
		{tail "bazooka_tail" "tail"}
	}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 0.5}	; kg
		{area 1 4}		; m
	}
}

{ammo "ammo panzerfaust"
	{view "faust_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 0.5}	; kg
		{area 1 4}		; m
	}
}

{weapon "weapon bazooka"
	{type bullet}
	{states
		{reload	"reload"}
		{unload	"unload"}
		{fire	"fire"	}
		{aim 	"aim"	}
	}
	{fireSound "smg_shot.grenade"}
	{foresight "Foresight3"}
	{aimRange 35}				; m
	{minRange 1}				; m
	{maxRange 30}				; m
	{spreading
		{SpreadRadius 1.5}		; m
	}
	{gravity 0.6}
	{rechargeTime 0.3}			; s
    {piercing	10 100 25 100   40 1}
	{speed 40}					; m/s
	{AimingTolerance 5}			; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}

{weapon "weapon panzershreck" from "weapon bazooka"
}

{weapon "weapon panzerfaust" from "weapon bazooka"
	{ammoLocked}
	{gravity 1.0}
	{speed 20}					; m/s
	{cursor "/interface/cursor/cannon_on.ebm"}
}
