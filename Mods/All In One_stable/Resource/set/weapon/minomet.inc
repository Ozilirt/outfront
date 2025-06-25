;SDL

{weapon "minomet" from "gun"
	{fireSound "heavy_shot.mortar_80"}
	{type bullet}
	{foresight "Foresight1"}
	{aimRange 120}					; m
	{maxRange 130}					; m
	{minRange 38}				; m
	{spreading
		{SpreadRadius 4.5}	; m
	}
	{rechargeTime 1.0}			; s
	{recoveryTime 0.1}			; s

	{speed 30}					; m/s
	{gravity 2.6}
	{parabolic}

	{piercing	100 10  200 10  300 10 }
	(mod "mp"
		{maxRange}					; m
		{piercing   10 2     50 2    100 2    200 2}

	)
}
{weapon "minomet_76mm" from "minomet"
	{aimRange 100}					; m
	{maxRange 110}					; m
	{spreading
		{SpreadRadius 6.0}	; m
	}
	{rechargeTime 3.5}			; s
	{recoveryTime 0.1}			; s

	{speed 34}					; m/s

	{piercing	100 10  200 10  300 10 }

	(mod "mp"
		{maxRange}					; m
		{piercing   100 10  200 10  300 10}

	)
}
{weapon "minomet_80mm" from "minomet"
	{aimRange 100}					; m
	{maxRange 110}					; m
	{spreading
		{SpreadRadius 6.0}	; m
	}
	{rechargeTime 3.5}			; s
	{recoveryTime 0.1}			; s

	{speed 34}					; m/s

	{piercing	100 10  200 10  300 10 }

	(mod "mp"
		{maxRange}					; m
		{piercing   100 10  200 10  300 10}

	)
}
{weapon "minomet_81mm" from "minomet"
	{aimRange 100}					; m
	{maxRange 110}					; m
	{spreading
		{SpreadRadius 6.0}	; m
	}
	{rechargeTime 3.5}			; s
	{recoveryTime 0.1}			; s

	{speed 34}					; m/s

	{piercing	100 10  200 10  300 10 }

	(mod "mp"
		{maxRange}					; m
		{piercing   100 10  200 10  300 10}

	)
}
{weapon "minomet_82mm" from "minomet"
	{aimRange 100}					; m
	{maxRange 110}					; m
	{spreading
		{SpreadRadius 6.0}	; m
	}
	{rechargeTime 3.5}			; s
	{recoveryTime 0.1}			; s

	{speed 34}					; m/s

	{piercing	100 10  200 10  300 10 }

	(mod "mp"
		{maxRange}					; m
		{piercing   100 10  200 10  300 10}

	)
}
{weapon "minomet_120mm" from "minomet"
	{fireSound "heavy_shot.mortar_120"}
	{aimRange 200}					; m
	{maxRange 205}					; m
	{minRange 40}				; m
	{spreading
		{SpreadRadius 6.5}	; m
	}
	{rechargeTime 4.0}			; s
	{recoveryTime 0.1}			; s

	{speed 40}					; m/s

	{piercing	100 15  200 15  300 15 }

	(mod "mp"
		{maxRange}					; m
		{piercing   100 15  200 15  300 15}

	)
}
{weapon "minomet_200mm" from "minomet"
	{fireSound "heavy_shot.type4_200"}
	{aimRange 200}					; m
	{maxRange 205}					; m
	{minRange 40}				; m
	{spreading
		{SpreadRadius 6.6}	; m
	}
	{rechargeTime 4.5}			; s
	{recoveryTime 0.1}			; s
	{speed 48}					; m/s

	{piercing	100 15  200 15  300 15 }

	(mod "mp"
		{maxRange}					; m
		{piercing   100 15  200 15  300 15}

	)
}
{ammo "ammo 76mm_mine"
	{view "mortar_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 6} ; kg
		{area 4 6}	 ; m
	}
}
{ammo "ammo 82mm_mine"
	{view "mortar_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 6} ; kg
		{area 4 6}	 ; m
	}
}
{ammo "ammo 81mm_mine"
	{view "mortar_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 6} ; kg
		{area 4 6}	 ; m
	}
}
{ammo "ammo 80mm_mine"
	{view "mortar_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 6} ; kg
		{area 4 6}	 ; m
	}
}
{ammo "ammo 120mm_mine"
	{view "mortar_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 6} ; kg
		{area 7 11}	 ; m
	}
}
{ammo "ammo 200mm_mine"
	{view "mortar_ammo"}
	{destroyViewWhenArrive}
	{damage blastwave
		{energy 7} ; kg
		{area 8 11}	 ; m
	}
}
