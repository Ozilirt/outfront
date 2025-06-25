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

	{minRange 1}					; m
	{aimRange 30}					; m
	{spreading {SpreadRadius 0.5}}	; m
	{gravity  1}
	{item "m24"
		{aimRange 25}
		(mod "mp"
			{aimRange 24}
		)
	}
	{item "f1"
		{aimRange 20}
		(mod "mp"
			{aimRange 20}
		)
	}
        {item "rgd33"
		{aimRange 24}
		(mod "mp"
			{aimRange 23}
		)
	}
	{item "mk1"
		{aimRange 20}
		(mod "mp"
			{aimRange 20}
		)
	}
        {item "mk26"
		{aimRange 25}
		(mod "mp"
			{aimRange 24}
		)
	}
	{item "m39"
		{aimRange 21}
	        (mod "mp"
		        {aimRange 21}
              	)
	}
	{item "gr31"
		{aimRange 20}
	        (mod "mp"
		        {aimRange 20}
              	)
	}
	{item "m61"
		{aimRange 23}
	        (mod "mp"
		        {aimRange 23}
		)
	}
	{item "type23"
		{aimRange 21}
	        (mod "mp"
		        {aimRange 21}
              	)
	}
        {item "knife"
		{aimRange 8}
		{constantSpeed 15}
	}
	{item "knife_ger"
		{aimRange 8}
		{constantSpeed 20}
	}
	{item "axe"
		{aimRange 10}
		{constantSpeed 20}
	}
	{item "chicken"
		{aimRange 15}
		{constantSpeed 12}
	}
	{item "molotov_coctail"
		{aimRange 20}
		(mod "mp" 
			{startAngle 30}
		)
	}
	{item "an_m14"
		{aimRange 20}
		(mod "mp" 
			{startAngle 30}
		)
	}
	{item "rpg40"
		{aimRange 17}
		(mod "mp"
			{aimRange 16}
			{startAngle 20}
		)
	}
	{item "pwm1" 
		{aimRange 17}
		(mod "mp"
			{aimRange 15}
			{startAngle 20}
		)
	}
	{item "m24x5" 
		{aimRange 17}
		(mod "mp"
			{aimRange 16}
			{startAngle 20}
		)
	}
	{item "rpg43"
		{aimRange 17}
		(mod "mp"
			{aimRange 15}
			{startAngle 20}
		)
	}
	{item "rg42x3"
		{aimRange 15}
		(mod "mp"
			{aimRange 14}
			{startAngle 20}
		)
	}
	{item "n73at"
		{aimRange 17}
		(mod "mp"
			{aimRange 15}
			{startAngle 20}
		)
	}
	{item "no74_mk2"
		{aimRange 17}
		(mod "mp"
			{aimRange 16}
			{startAngle 20}
		)
	}
	{item "type3at" 
		{aimRange 17}
		(mod "mp"
			{aimRange 16}
			{startAngle 20}
		)
	}
	{item "smokegrenade"
		{aimRange 30}
		(mod "mp"
			{aimRange 20}
		)
	}
	{item "m18"
		{aimRange 30}
		(mod "mp"
			{aimRange 20}
		)
	}
	{item "50mm_mine"
		{aimRange 20}
		(mod "mp"
			{aimRange 25}
			{startAngle 30}
		)
	}
	{item "tntpack"
		{aimRange 12}
		(mod "mp"
			{aimRange 14}
		)
	}
}

{ammo pattern "grenade"
	{PinoffCursor "/interface/cursor/grenade.ebm"}
}

{ammo "grenade m24" from "grenade"
	{damage blastwave
		{energy 0.8} ; kg
		{area 1.5 6}	 ; m
	}
	{detonationTime 7}
}

{ammo "grenade f1" from "grenade"
	{damage blastwave
		{energy 0.3} ; kg
		{area 2 8}	 ; m
	}
	{detonationTime 4}
}
{ammo "grenade rgd33" from "grenade"
	{damage blastwave
		{energy 0.6} ; kg
		{area 1.5 4.5}	 ; m
	}
	{detonationTime 4}
}

{ammo "grenade gr31" from "grenade f1"}

{ammo "grenade mk1" from "grenade f1"}
{ammo "grenade type23" from "grenade f1"}

{ammo "grenade mk26" from "grenade"
	{damage blastwave
		{energy 0.5} ; kg
		{area 2 5}	 ; m
	}
	{detonationTime 6}
}

{ammo "grenade m39" from "grenade"
	{damage blastwave
		{energy 0.5} ; kg
		{area 2 6}	 ; m
	}
	{detonationTime 6}
}

{ammo "grenade m61" from "grenade"
	{damage blastwave
		{energy 0.4} ; kg
		{area 2.5 7}	 ; m
	}
	{detonationTime 5}
}
{ammo "grenade 50mm_mine" from "grenade"
	{view "mortar50_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 2} ; kg
		{area 2 5}	 ; m
	}
}
{ammo "grenade rpg40" from "grenade"
	{damage blastwave
		{energy 10} ; kg
		{area 2 5}	 ; m
	}
}
{ammo "grenade rg42x3" from "grenade rpg40"
	{damage blastwave
		{energy 12.5} ; kg
		{area 2 2}	 ; m
	}
}
{ammo "grenade rpg43" from "grenade rpg40"
	{damage blastwave
		{energy 12} ; kg
		{area 1 2}	 ; m
	}
}

{ammo "grenade pwm1" from "grenade rpg40"
	{damage blastwave
		{energy 12} ; kg
		{area 1 2}	 ; m
	}
}

{ammo "grenade m24x5" from "grenade rpg40"
	{damage blastwave
		{energy 8}
		{area 2 9}
	}
}
{ammo "grenade type3at" from "grenade rpg40"
	{damage blastwave
		{energy 11.5}
		{area 2 3}
	}
}
{ammo "grenade n73at" from "grenade rpg40"
	{damage blastwave
		{energy 10} ; kg
		{area 2 5}	 ; m
	}
}

{ammo "grenade no74_mk2" from "grenade rpg40"
	{damage blastwave
		{energy 12.5} ; kg
		{area 2 2}	 ; m
	}
}

{ammo "molotov_coctail"
}

{ammo "an_m14"
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
{ammo "tntpack" from "grenade f1"
	{damage blastwave
		{energy 20}
		{area 4 9}
	}
	{detonationTime 6}
}

