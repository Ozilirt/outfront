;SDL

{ammo "ammo bazooka" 
	{view "bazooka_ammo"
		{tail "bazooka_tail" "tail"}
	}
	{destroyViewWhenArrive}
	{hollowCharge 3} ; m
	{damage blastwave
		{energy 0.8}	; kg
		{area 2.0 2.0}		; m
	}
}

{ammo "ammo PIAT"
	{view "faust_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 0.6}	; kg
		{area 2 2}		; m
	}
}

{ammo "ammo panzerfaust"
	{view "faust_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 1.0}	; kg
		{area 1 1}		; m
	}
}

{ammo "ammo m18"
	{view "faust_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 0.75}	; kg
		{area 1 1}		; m
	}
}
{weapon "weapon bazooka"
	{type bullet}
	{states
		{reload	"reload-bazooka"}
		{unload	"unload-bazooka"}
		{fire	"fire-bazooka"	}
		{aim 	"aim-bazooka"	}
	}
	{fireSound "smg_shot.grenade"}
	{foresight "Foresight3"}
	{minRange 1}				; m
	{spreading
		{SpreadRadius 2.5}		; m
	}
	{reactive}
	{gravity 3}
	{rechargeTime 2.5}			; s
   	{piercing  40 95}
	{speed 70}					; m/s
	{AimingTolerance 5}			; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
	{aimRange 40}
	{maxRange 40}					; m
	(mod "mp"
		{aimRange 40}
	        {piercing  40 102}
		{maxRange 40}					; m
	)
}

{weapon "weapon PIAT" from "weapon bazooka"
	{type bullet}
	{states
		{reload	"reload-bazooka"}
		{unload	"unload-bazooka"}
		{fire	"fire-bazooka"	}
		{aim 	"aim-bazooka"	}
	}
        {aimRange 32}
	{maxRange 32}					; m
	{gravity 2.0}
        {spreading
		{SpreadRadius 2.2}		; m
	}
	{rechargeTime 3.0}
        {piercing 50 130}
        {healthing  1000 200}
	{speed 80}	
}

{weapon "weapon panzershreck" 
        {type bullet}
        {states
		{reload	"reload-bazooka"}
		{unload	"unload-bazooka"}
		{fire	"fire-bazooka"	}
		{aim 	"aim-bazooka"	}
	}
	{fireSound "smg_shot.grenade"}
	{foresight "Foresight3"}
	{aimRange 50}				; m
	{minRange 1}				; m
	{maxRange 50}				; m
	{spreading
		{SpreadRadius 2.3}		; m
	}
	{gravity 3.0}
	{rechargeTime 3.0}			; s
        {piercing  50 200 }
        {healthing  1000 200}
	{speed 75}					; m/s
	{AimingTolerance 5}			; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}
{weapon "weapon type4_launcher" 
        {type bullet}
        {states
		{reload	"reload-bazooka"}
		{unload	"unload-bazooka"}
		{fire	"fire-bazooka"	}
		{aim 	"aim-bazooka"	}
	}
	{fireSound "smg_shot.grenade"}
	{foresight "Foresight3"}
	{aimRange 40}				; m
	{minRange 1}				; m
	{maxRange 40}				; m
	{spreading
		{SpreadRadius 2.3}		; m
	}
	{gravity 3.0}
	{rechargeTime 3.0}			; s
        {piercing  50 180 }
        {healthing  1000 200}
	{speed 70}					; m/s
	{AimingTolerance 5}			; degree
	{cursor "/interface/cursor/cannon_on.ebm"}
}
{weapon "weapon panzerpatrone" from "weapon bazooka"
        {fireSound "smg_shot.grenade_2"}
	{ammoLocked}
        {gravity 2.5}
       	{aimRange 25}
	{maxRange 25}
	{reactive 0}
        {spreading
		{SpreadRadius 2.0}		; m
	}
	{piercing  50 100}
        {healthing  1000 200}
	{speed 40}					; m/s
	(mod "mp"
		{aimRange 35}
		{maxRange 35}					; m
	)
}
{weapon "weapon panzerfaust" from "weapon bazooka"
        {type bullet}
	{fireSound "smg_shot.grenade_2"}
	{ammoLocked}
	{gravity 2.5}
	{maxRange 30}
	{aimRange 30}
        {spreading
		{SpreadRadius 1.8}		; m
	}
        {piercing  50 200}
        {healthing  1000 200}
	{speed 45}					; m/s
	{cursor "/interface/cursor/cannon_on.ebm"}
}
{weapon "weapon rifle_m18" from "weapon bazooka"
	{type bullet}
	{fireSound "heavy_shot.50mm"}
        {aimRange 45}
	{maxRange 45}					; m
	{gravity 0.25}
        {spreading
		{SpreadRadius 1.0}		; m
	}
	{rechargeTime 4.5}
        {piercing  40 125 }
        {healthing  1000 200}
	{speed 100}
	(mod "mp"
		{aimRange 45}
	        {piercing  40 100}
		{maxRange 45}					; m
	)	
}