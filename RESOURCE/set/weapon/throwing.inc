;SDL

{weapon "thrower hand"
	{type throwing}
	{states
		{fire	"fire"  	 }
		{reload "reload"	 }
		{unload "unload"	 }
		{aim 	"aim-thrower"}
	}
	{foresight "Foresight2"}
	{AimingTolerance 3}				; degree

	{minRange 3}					; m
	{aimRange 30}					; m
	{spreading {SpreadRadius 0.0}}	; m
	{gravity  1}
	{item "m24"
		{aimRange 22}
	}
	{item "f1"
		{aimRange 25}
	}
	{item "mk1"
		{aimRange 25}
	}
	{item "m39"
		{aimRange 25}
	}
	{item "m61"
		{aimRange 25}
	}
	{item "knife"
		{aimRange 10}
		{constantSpeed 20}
	}
	{item "knife_ger"
		{aimRange 12}
		{constantSpeed 20}
	}
	{item "axe"
		{aimRange 10}
		{constantSpeed 20}
	}
	{item "chicken"
		{aimRange 15}
		{constantSpeed 20}
	}
	{item "molotov_coctail"
		{aimRange 20}
	}
	{item "rpg40"
		{aimRange 17}
	}
	{item "pwm1"
		{aimRange 17}
	}
	{item "m24x5"
		{aimRange 17}
	}
	{item "rpg43"
		{aimRange 17}
	}
	{item "n73at"
		{aimRange 17}
	}
	{item "smokegrenade"
		{aimRange 30}
	}
	{item "m18"
		{aimRange 30}
	}
}

{ammo pattern "grenade"
	{PinoffCursor "/interface/cursor/grenade.ebm"}
}

{ammo "grenade m24" from "grenade"
	{damage blastwave
		{energy 0.8} ; kg
		{area 1.5 4}	 ; m
	}
	{detonationTime 5}
}

{ammo "grenade f1" from "grenade"
	{damage blastwave
		{energy 0.6} ; kg
		{area 4 6}	 ; m
	}
	{detonationTime 5}
}

{ammo "grenade mk1" from "grenade f1"}

{ammo "grenade m39" from "grenade f1"}

{ammo "grenade m61" from "grenade f1"}

{ammo "grenade rpg40" from "grenade"
	{damage blastwave
		{energy 5} ; kg
		{area 1 3}	 ; m
	}
}

{ammo "grenade rpg43" from "grenade rpg40"
}

{ammo "grenade pwm1" from "grenade rpg40"
}

{ammo "grenade m24x5" from "grenade rpg40"
}

{ammo "grenade n73at" from "grenade rpg40"
}

{ammo "molotov_coctail"
}

{ammo "knife hand"
}

{ammo "knife_ger hand"
}

{ammo "chicken"
}

{ammo "axe"
}

{ammo "grenade smoke" from "grenade"
}

{ammo "grenade m18" from "grenade smoke"
}
