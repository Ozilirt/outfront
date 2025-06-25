
;SDL

(include "gun_ammo.inc")

{weapon pattern "gun"
	{type bullet}
	{foresight "Foresight1"}
	{aimRange 200}				; m
	{maxRange 200}					; m
	{minRange 2}				; m
	{spreading {SpreadRadius 5.0}	}	; m
	{healthing 20 3000 50 1000 100 500 200 100 500 0}
	{rechargeTime 5.0}			; s
	{speed 200}					; m/s
	{AimingTolerance 2}			; degree
	{RelaxationTime 0.5}
	{cursor "/interface/cursor/cannon_on.ebm"}
	(mod "mp"
		{maxRange 200}					; m
	)
}

{weapon "Quad_50cal" from "gun"	; m16aa
	{fireSound "mgun_shot.50cal"}
	{reloadSound "reload.mg1_r"}
	{aimRange 275}
	{maxRange 250}			; m
	{speed 230}
	{RechargeTime 16}
	{RecoveryTime 0.09}
	{spreading
		{spreadradius 	6.8}
		{SpreadXYRatio	5.5}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
	{min 4}
	{short 2.5 1}
	{long 7 2}
	}	
	{piercing    20 12 100 10 200 8 300 5 500 2}
        {healthing  5 300 25 285 50 240 100 183 150 100 250 80}
	(mod "mp"
		{maxRange 250}
		{piercing    20 12 100 10 200 8 300 5 500 2}
		{healthing  5 300 25 285 50 240 100 183 150 100 250 80}
	)
}
{weapon "15mm_BESA" from "gun"		; Humber
	{fireSound	"mgun_shot.DSHK"}
        {reloadSound "reload.mg1_r"}
	{minRange 1.5}
	{aimRange 190}
	{maxRange 175}			; m
	{spreading {spreadradius 6}}	                ; m
        {automatic}
        {cursor "/interface/cursor/mgun_on_3.ebm"}
        {burst
		{short 5  2}
		{long  8  3}
	}
        {RecoveryTime 0.22}
	{rechargeTime 5}				; s
	{piercing    20 26 100 12 200 6 300 4 500 2}
        {healthing  5 320 25 295 50 250 100 180 150 100 250 100}
        {shellEnergy 2}
	(mod "mp"
		{piercing    20 26 100 10 200 5 300 3 500 2}
                {healthing  5 320 25 295 50 250 100 180 150 100 250 30 400 1}
		{maxRange 175}					; m
		{speed 210}
		{spreading {spreadradius 6}}	; m
	)
}
{weapon "20mm_kwk30" from "gun"		; Pz-2c
	{fireSound "heavy_shot.20mm"}
	{reloadSound "reload.pak35_r"}
	{aimRange 160}					; m
	{maxRange 160}					; m
	{aimRange "tank"50}				; m
	{minRange 2}					; m
	{spreading {spreadradius 6.2}}	; m
	{rechargeTime   2}				; s
	{piercing    20 34 100 21 200 9 500 3}
        {shellEnergy 3}
	(mod "mp"
                {maxRange 160}
	)
}
{weapon "20mm_kwk38" from "gun"		; Pz-2f, SdKfz-232
	{fireSound "heavy_shot.20mm"}
        {reloadSound "reload.mg2_r"}
	{aimRange 160}					; m
	{maxRange 160}					; m
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
	{piercing    20 34 100 21 200 9 500 3}
        {shellEnergy 3}
	(mod "mp"
		{piercing    20 34 100 21 200 9 500 3}
		{maxRange 160}					; m
		{speed 200}
		{spreading {spreadradius 6.2}}	; m
	)
}
{weapon "20mm_kwk32" from "gun"		; Bergepz
	{fireSound "heavy_shot.20mm"}
        {reloadSound "reload.mg2_r"}
	{aimRange 160}					; m
	{maxRange 160}					; m
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
	{piercing    20 34 100 21 200 9 500 3}
        {shellEnergy 3}
	(mod "mp"
		{piercing    20 34 100 21 200 9 500 3}
		{maxRange 160}					; m
		{speed 200}
		{spreading {spreadradius 6.2}}	; m
	)
}
{weapon "20mm_TNSH" from "gun"		; t-60
	{fireSound "heavy_shot.20mm_tnsh"}
        {reloadSound "reload.mg2_r"}
	{aimRange 160}					; m
	{maxRange 160}					; m
	{aimRange "tank"50}				; m
	{minRange 1.5}					; m
	{spreading {spreadradius 7}}	                ; m
        {automatic}
        {burst
		{min 3}
		{short 2.5 1}
		{long 7 2}
	}
        {RecoveryTime 0.22}
	{rechargeTime 5}				; s
	{piercing    20 28 100 15 200 8 500 2}
        {shellEnergy 3}
	(mod "mp"
		{piercing    20 28 100 15 200 8 500 2}
		{maxRange 160}					; m
		{speed 210}
		{spreading {spreadradius 7.2}}	; m
	)
}
{weapon "20mm_flak38" from "gun"	; Panzerflak, SdKfz-10/5, Flak-38, Flak-37
	{fireSound "heavy_shot.20mm"}
        {reloadSound "reload.mg2_r"}
	{aimRange 275}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{aimRange "tank"40}				; m
	{RecoveryTime 0.18}
	{RechargeTime 2}
	{reloadSound "reload.flak38_r"}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
		{min 4}
		{short 2.5 1}
		{long 7 2}
	}	
	{speed 230}						; m/s
	{piercing    20 23  100 10  200 5  500 3}
        {shellEnergy 3}
	(mod "mp"
		{maxRange 250}				; m
		{piercing    20 38 100 22 200 10 500 4}
	)
}
{weapon "20mm_flak30" from "gun"	; Panzerflak, Flak-38-1, ubgun20
	{fireSound "heavy_shot.20mm"}
        {reloadSound "reload.mg2_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{aimRange "tank"40}				; m
	{RecoveryTime 0.18}
	{RechargeTime 2}
	{reloadSound "reload.flak38_r"}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}	
	{speed 230}						; m/s
	{piercing    20 34 100 21 200 9 500 3}
        {shellEnergy 3}
	(mod "mp"
		{maxRange 200}				; m
		{piercing    20 38 100 22 200 10 500 4}
	)
}
{weapon "20mm_oerlikon" from "gun"		; CrusaderAA, shipflak2
	{fireSound "heavy_shot.20mm"}
        {reloadSound "reload.mg2_r"}
	{aimRange 275}					; m
	{maxRange 250}					; m
	{aimRange "tank"50}				; m
	{minRange 2}					; m
	{spreading {spreadradius 6.2}}	; m
        {automatic}
        {burst
		{min 4}
		{short 2.5 1}
		{long 7 2}
	}
        {RecoveryTime 0.25}
	{rechargeTime   4}				; s
	{piercing    20 34 100 21 200 9 500 3}
        {shellEnergy 3}
	(mod "mp"
		{piercing    20 34 100 21 200 9 500 3}
		{maxRange 250}				; m
		{speed 200}
		{spreading {spreadradius 6.2}}	; m
	)
}
{weapon "20mm_type2" from "gun"	; Type 2
	{fireSound "heavy_shot.20mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{aimRange "tank"40}				; m
	{RecoveryTime 0.18}
	{RechargeTime 1.6}
	{spreading {spreadradius 6.4}}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}	
	{speed 230}						; m/s
	{piercing    20 23  100 10  200 5  500 3}
        {shellEnergy 3}
	(mod "mp"
		{maxRange 200}				; m
		{piercing    20 38 100 22 200 10 500 4}
	)
}
{weapon "25mm_type96_1" from "gun"	; Type 96 single barrel
	{fireSound "heavy_shot.20mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{aimRange "tank"40}				; m
	{RecoveryTime 0.25}
	{RechargeTime 1.6}
	{spreading
		{spreadradius 	7.0}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
		{short 2.1 1}
		{long 7 2}
	}	
	{speed 230}						; m/s
	{piercing    20 35 100 29 200 22 300 13 500 6}
        {shellEnergy 3}
	(mod "mp"
		{maxRange 200}				; m
		{piercing    20 35 100 29 200 22 300 13 500 6}
	)
}
{weapon "25mm_type96_2" from "gun"	; Type 96 two barrel
	{fireSound "heavy_shot.20mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{aimRange "tank"40}				; m
	{RecoveryTime 0.17}
	{RechargeTime 2.0}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}	
	{speed 230}						; m/s
	{piercing    20 35 100 29 200 22 300 13 500 6}
        {shellEnergy 3}
	(mod "mp"
		{maxRange 200}				; m
		{piercing    20 35 100 29 200 22 300 13 500 6}
	)
}
{weapon "25mm_type96_3" from "gun"	; Type 96 triple barrel
	{fireSound "heavy_shot.20mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{aimRange "tank"40}				; m
	{RecoveryTime 0.15}
	{RechargeTime 2.5}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{Automatic}
	{burst
		{min 3}
		{short 2.5 1}
		{long 7 2}
	}	
	{speed 230}						; m/s
	{piercing    20 35 100 29 200 22 300 13 500 6}
        {shellEnergy 3}
	(mod "mp"
		{maxRange 200}				; m
		{piercing    20 35 100 29 200 22 300 13 500 6}
	)
}
{weapon "25mm_SA35" from "gun"		; Panhard 178
	{fireSound "heavy_shot.20mm"}
	{reloadSound "reload.pak35_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 2}				; s
	{speed 180}						; m/s
	{piercing  20 35 100 29 200 22 300 13 500 6}
	(mod "mp"
                {aimRange 200}	
		{maxRange 200}					; m
		{rechargeTime 2}				; s
		{piercing  20 35 100 29 200 22 300 13 500 6}
	)
}
{weapon "37mm_A7" from "gun"		; 7TP
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.pak35_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 3}				; s
	{speed 185}						; m/s
	{piercing  20 64 100 34 200 29 300 24 500 10}
	(mod "mp"
		{maxRange 200}					; m
		{rechargeTime 2}				; s
		{piercing  20 55 100 48 200 42 300 31 500 17}
	)
}
{weapon "37mm_pak35" from "gun"		; SdKfz-250/10
	{fireSound "heavy_shot.37mm"}
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
{weapon "37mm_KwK38" from "gun"		; pz-38t
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.pak35_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 3}				; s
	{speed 185}						; m/s
	{piercing  20 41 100 34 200 29 300 24 500 10}
        {shellEnergy 10}
	(mod "mp"
		{maxRange 200}					; m
		{rechargeTime 2}				; s
		{piercing  20 41 100 34 200 29 300 24 500 10}
	)
}
{weapon "37mm_m6" from "gun"		; m8 Grayhound 
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 3}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 8.0}}	; m
	{rechargeTime 3}				; s
	{speed 200}						; m/s
	{piercing  20 43 100 30 200 26 300 20 500 10}
	{shellEnergy 10}
	(mod "mp"
		{maxRange 200}					; m
		{rechargeTime 2}				; s
		{piercing  20 43 100 30 200 26 300 20 500 10}
	)
}
{weapon "37mm_sa18" from "gun"		; H35 
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 3}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 8.0}}	; m
	{rechargeTime 3}				; s
	{speed 200}						; m/s
	{piercing  20 43 100 30 200 26 300 20 500 10}
	{shellEnergy 10}
	(mod "mp"
		{maxRange 200}					; m
		{rechargeTime 2}				; s
		{piercing  20 43 100 30 200 26 300 20 500 10}
	)
}
{weapon "37mm_type94" from "gun"	; Ha-Go
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
{weapon "37mm_61k" from "gun"		; Zis42-61k , m1939-61k
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 275}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{aimRange "tank"40}					; m
	{RecoveryTime 0.3}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{automatic}
	{burst
		{min 3}
		{short 2.5 1}
		{long 7 2}
	}
	{rechargeTime 6}				; s
	{speed 280}						; m/s
	{piercing    20 42  100 30   200 20  300 10 500 7}
	{shellEnergy 11}
	(mod "mp"
		{maxRange 250}					; m
		{rechargeTime 1}				; s
		{piercing    20 42  100 30   200 20  300 10 500 7}
	)
}
{weapon "37mm_flak43" from "gun"		; Ostwind
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 275}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{aimRange "tank"40}					; m
	{RecoveryTime 0.25}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{automatic}
	{burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}
	{rechargeTime 2}				; s
	{speed 300}						; m/s
	{piercing    20 45  100 33   200 21  300 10 500 7}
	{shellEnergy 11}
	(mod "mp"
		{maxRange 250}					; m
		{rechargeTime 1}				; s
		{piercing    20 45  100 33   200 21  300 10 500 7}
	)
}
{weapon "37mm_gun_m1" from "gun"		; 37mmgunm1
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{RecoveryTime 0.25}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{automatic}
	{burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}
	{rechargeTime 3.5}				; s
	{speed 300}						; m/s
	{piercing    20 45  100 33   200 21  300 10 500 7}
	{shellEnergy 10}
	(mod "mp"
		{maxRange 250}					; m
		{rechargeTime 2.5}				; s
		{piercing    20 45  100 33   200 21  300 10 500 7}
	)
}
{weapon "40mm_mk1" from "gun"		; BOfors
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.flak38_r"}
	{aimRange 275}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{RecoveryTime 0.2}
	{spreading
		{spreadradius 	7.2}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{AimingTolerance 40}
	{automatic}
	{burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}
	{rechargeTime 4.5}				; s
	{speed 300}						; m/s
	{piercing    20 52  100 38   200 24  300 12 500 9}
	{shellEnergy 10}
	(mod "mp"
		{maxRange 250}					; m
		{rechargeTime 2.5}				; s
		{piercing    20 52  100 38   200 24  300 12 500 9}
	)
}
{weapon "OQF 2-pdr" from "gun"		; mk2 Daimler
	{fireSound "heavy_shot.45mm"}
	{reloadSound "reload.pak35_r"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 7.5}}	; m
	{rechargeTime 3}				; s
	{speed 200}						; m/s
	{piercing  20 59 100 43 200 28 300 21 500 14}
	{shellEnergy 12}
	(mod "mp"
		{maxRange 200}					; m
		{rechargeTime 2.0}				; s
		{piercing  20 59 100 43 200 28 300 21 500 14}
	)
}
{weapon "45mm_20k" from "gun"		; T-26, BT-7, Vickers-b
	{fireSound "heavy_shot.45mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 8}}	; m
	{rechargeTime 4.0}				; s
	{speed 200}						; m/s
	{piercing  20 43 100 31 200 28 300 17 500 9}
        {shellEnergy 15}
	(mod "mp"
		{maxRange 200}					; m
		{piercing  20 43 100 31 200 28 300 17 500 9}
		{rechargeTime 3.0}				; s
	)
}
{weapon "45mm_53k" from "gun"		; 45mm m1937, T-70
	{fireSound "heavy_shot.45mm_53k"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.0}				; s
	{speed 205}						; m/s
	{piercing  20 51 100 38 200 35 300 20 500 15}
	(mod "mp"
		{maxRange 200} 				; m
		{piercing  20 51 100 38 200 31 300 20 500 12}
		{rechargeTime 3.0}				; s
	)
}
{weapon "45mm_m42" from "gun"		; 45mm m1942
	{fireSound "heavy_shot.45mm_m42"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 5}}	; m
	{rechargeTime 2.0}				; s
	{speed 220}						; m/s
	{piercing   20 65 100 52 200 38 300 30 500 18}
        {shellEnergy 12}
	(mod "mp"
		{maxRange 200}					; m
		{piercing  20 65 100 52 200 38 300 30 500 18}
		{rechargeTime 2.0}				; s
	)
}
{weapon "45mm_m38" from "gun"
	{fireSound "heavy_shot.47mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.0}				; s
	{speed 205}						; m/s
	{piercing  20 51 100 38 200 35 300 20 500 15}
	(mod "mp"
		{maxRange 200} 				; m
		{piercing  20 51 100 38 200 31 300 20 500 12}
		{rechargeTime 3.0}				; s
	)
}
{weapon "45mm_mod.42" from "gun"
	{fireSound "heavy_shot.47mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 5}}	; m
	{rechargeTime 2.0}				; s
	{speed 220}						; m/s
	{piercing   20 65 100 52 200 38 300 30 500 18}
        {shellEnergy 12}
	(mod "mp"
		{maxRange 200}					; m
		{piercing  20 65 100 52 200 38 300 30 500 18}
		{rechargeTime 2.0}				; s
	)
}
{weapon "47mm_pak" from "gun"		; pzjager-1 
	{fireSound "heavy_shot.47mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.0}				; s
	{speed 240}						; m/s
	{piercing  20 76 100 55 200 47 300 35 500 18}
        {shellEnergy 15}
	(mod "mp"
		{maxRange 200}					; m
		{piercing  20 76 100 55 200 47 300 35 500 18}
		{rechargeTime 3.8}				; s
	)
}
{weapon "47mm_type1" from "gun"		; Chi-Ha47
	{fireSound "heavy_shot.47mmj"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 5.5}}	; m
	{rechargeTime 4.0}				; s
	{speed 250}						; m/s
	{piercing  20 76 100 55 200 47 300 35 500 18}
        {shellEnergy 15}
	(mod "mp"
		{maxRange 200}					; m
		{piercing  20 76 100 55 200 47 300 35 500 18}
		{rechargeTime 3.8}				; s
	)
}
{weapon "47mm_Sa35" from "gun"		; Char B1bis, S35
	{fireSound "heavy_shot.47mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}
	{minRange 2}					; m
	{maxRange 200}					; m
	{spreading {SpreadRadius 4.5}}	; m
	{rechargeTime 4.5}				; s
	{speed 230}						; m/s
	{piercing  20 56 100 45 200 35 300 26 500 15}
	(mod "mp"
		{maxRange 200}					; m
		{piercing  20 56 100 45 200 35 300 26 500 15}
		{rechargeTime 3.5}				; s
	)
}
{weapon "50mm_kwk38" from "gun"     ; Pz-3G,
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 7}}	; m
	{rechargeTime 4.0}				; s
	{speed 170}						; m/s
	{piercing  20 68 100 50 200 42 300 26 500 12}
        {shellEnergy 17}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 68 100 50 200 42 300 26 500 12}
	)
}
{weapon "50mm_kwk39" from "gun"     ; Pz-3L 
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 4.2}				; s
	{speed 250}						; m/s
	{piercing  20 99 100 75 200 57 300 33 500 20}
        {shellEnergy 17}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 99 100 75 200 57 300 33 500 20}
	)
}
{weapon "50mm_Pak39" from "gun"     ; Pak39 
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 5.5}}	; m
	{rechargeTime 3.8}				; s
	{speed 255}						; m/s
	{piercing  20 102 100 78 200 61 300 37 500 20}
        {shellEnergy 17}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 102 100 78 200 61 300 37 500 20}
	)
}
{weapon "50mm_Pak38" from "gun"     ; Pak38 
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 5.5}}	; m
	{rechargeTime 3.8}				; s
	{speed 255}						; m/s
	{piercing  20 102 100 78 200 61 300 37 500 20}
        {shellEnergy 17}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 102 100 78 200 61 300 37 500 20}
	)
}
{weapon "57mm_OQF" from "gun"     ; Crusader
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.2}				; s
	{speed 240}						; m/s
	{piercing  20 89 100 73 200 62 300 36 500 22}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 89 100 73 200 62 300 36 500 22}
	)
}
{weapon "57mm_m1" from "gun"     ; 57mmUS
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.2}				; s
	{speed 240}						; m/s
	{piercing  20 89 100 73 200 62 300 36 500 22}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 89 100 73 200 62 300 36 500 22}
	)
}
{weapon "57mm" from "gun"     ; Ke-Nu, Chi-Ha57
	{fireSound "heavy_shot.57mmj"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 210}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.2}				; s
	{speed 150}						; m/s
	{piercing  20 69 100 53 200 42 300 16 500 10}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 69 100 53 200 42 300 16 500 10}
	)
}
{weapon "57mm_zis2" from "gun"      ; SU_57, Zis-2
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 210}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 3.8}              ; s
	{speed 290}						; m/s
	{piercing  20 131 100 115 200 105 300 75 500 42}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 131 100 115 200 105 300 75 500 42}
	)
}
{weapon "57mm_zis4" from "gun"      ; T-34-57
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 210}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.2}              ; s
	{speed 280}						; m/s
	{piercing  20 108 100 98 200 90 300 62 500 36}
	(mod "mp"
		{maxRange 210}					; m
		{piercing  20 108 100 98 200 90 300 62 500 36}
	)
}
{weapon "75mm_kwk37" from "gun"     ; Pz-4D, PzIIIN
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{maxrange 240}
	{minRange 2}					; m
	{spreading {SpreadRadius 7}}	; m
	{rechargeTime 4.5}				; s
	{speed 120}						; m/s
	{piercing  20 51 100 46 200 41 300 25 500 15}
	(mod "mp"
                {aimRange 200}	
		{maxRange 240}					; m
		{piercing  20 51 100 46 200 41 300 25 500 15}
	)
}
{weapon "75mm_L25" from "gun"
	{fireSound "heavy_shot.75"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{maxrange 240}
	{minRange 2}					; m
	{spreading {SpreadRadius 7}}	; m
	{rechargeTime 5}				; s
	{speed 135}						; m/s
	{piercing  20 51 100 46 200 41 300 25 500 15}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 56 100 48 200 42 300 24 500 14}
	)
}
{weapon "75mm_stuk37" from "gun"    ; StuG-3B
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 9}}	; m
	{rechargeTime 4.3}				; s
	{speed 60}
	{gravity 0.7}						; m/s
	{piercing  20 51 100 46 200 41 300 25 500 15}
	(mod "mp"
                {aimRange 200}	
		{maxRange 240}					; m
		{piercing  20 51 100 46 200 41 300 25 500 15}
	)
}
{weapon "75mm_LelG18" from "gun"    ; LelG18
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{minRange 2}					; m
	{maxRange 250}					; m
	{spreading
		{spreadradius 	15.0}
		{SpreadXYRatio	6}
		{SpreadPower	4}
	}	; m
	{rechargeTime 5.5}
        {gravity 1}				; s
	{speed 80}					; m/s
	{piercing  20 38 100 26 200 21 300 15 500 5}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  20 38 100 26 200 21 300 10 500 5}
	)
}
{weapon "75mm_L36" from "gun"     ; Naval Gun 7.5cm c/34 
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.3}}	; m
	{rechargeTime 5.0}				; s
	{speed 230}						; m/s
	{piercing  20 120 100 106 200 82 300 62 500 31}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 120 100 106 200 82 300 62 500 31}
	)
}
{weapon "75mm_type90" from "gun"     ; type 90 cannon, 
	{fireSound "heavy_shot.75mmj4"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.2}}	; m
	{rechargeTime 4.8}				; s
	{speed 220}						; m/s
	{piercing  20 120 100 106 200 82 300 62 500 31}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 120 100 106 200 82 300 62 500 31}
	)
}
{weapon "75mm_kwk40" from "gun"     ; Pz-4G 
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.3}}	; m
	{rechargeTime 5.0}				; s
	{speed 240}						; m/s
	{piercing  20 120 100 106 200 82 300 62 500 31}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 120 100 106 200 82 300 62 500 31}
	)
}
{weapon "75mm_kwk40/L48" from "gun"     ; Pz-4H
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 5.0}				; s
	{speed 250}						; m/s
	{piercing  20 132 100 113 200 92 300 66 500 40}
        {shellEnergy 28}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 132 100 113 200 92 300 66 500 40}
	)
}
{weapon "75mm_stuk40" from "gun"	; StuG-3F
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.3}}	; m
	{rechargeTime 4.5}				; s
	{speed 240}						; m/s
	{piercing  20 120 100 106 200 82 300 62 500 31}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 120 100 106 200 82 300 62 500 31}
	)
}
{weapon "75mm_stuk40/L48" from "gun"	; StuG-40
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 4.5}				; s
	{speed 250}						; m/s
	{piercing  20 132 100 113 200 92 300 66 500 40}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 132 100 113 200 92 300 66 500 40}
	)
}
{weapon "75mm_pak39/L48" from "gun"	; hetzer
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.3}}	; m
	{rechargeTime 4.8}				; s
	{speed 250}						; m/s
	{piercing  20 132 100 113 200 92 300 66 500 40}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 132 100 113 200 92 300 66 500 40}
	)
}
{weapon "75mm_kwk42" from "gun"     ; Pz-5
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 220}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 4.5}}	; m
	{maxRange 240}					; m
	{rechargeTime 5.0}				; s
	{speed 300}						; m/s
	{piercing  20 178 100 160 200 149 300 109 500 62}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 178 100 160 200 149 300 109 500 62}
	)
}
{weapon "75mm_type5" from "gun"     ; Chi-to
	{fireSound "heavy_shot.75mmj1"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 6.1}}			; m
	{rechargeTime 5.0}				; s
	{speed 245}						; m/s
	{piercing  20 130 100 110 200 90 300 64 500 40}
	(mod "mp"
		{maxRange 245}					; m
		{piercing  20 130 100 110 200 90 300 64 500 40}
	)
}
{weapon "75mm_kwk42/2" from "gun"     ; Maus
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 4.5}}	; m
	{maxRange 240}					; m
	{rechargeTime 5.0}				; s
	{speed 300}						; m/s
	{piercing  20 178 100 160 200 149 300 109 500 62}
	{cursor "/interface/cursor/cannon_on_2.ebm"}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 178 100 160 200 149 300 109 500 62}
	)
}
{weapon "75mm_pak40" from "gun"     ; Cannon Pak-40
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 205}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 5.5}}	; m
	{maxRange 240}					; m
	{rechargeTime 4.5}				; s
	{speed 250}						; m/s
	{piercing  20 134 100 113 200 97 300 68 500 40}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 134 100 113 200 97 300 68 500 40}
	)
}
{weapon "75mm_m3" from "gun"     ; m4a2, Cromwell, Churchill
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 7.0}}	; m
	{rechargeTime 5.0}				; s
	{speed 200}						; m/s
	{piercing  20 96 100 84 200 73 300 51 500 33}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 96 100 84 200 73 300 51 500 33}
	)
}
{weapon "75mm_m6" from "gun"     ; Chaffee
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 8.0}}	; m
	{rechargeTime 4.5}				; s
	{speed 180}						; m/s
	{piercing  20 79 100 70 200 64 300 42 500 25}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 79 100 70 200 64 300 42 500 25}
	)
}
{weapon "75mmM3" from "gun"      ; M8 Scott
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 14}}	; m
	{rechargeTime 3.0}              ; s
	{speed 50}						; m/s
        {gravity 1.0}
	{piercing  20 22 100 16 200 12 300 8 500 8}
	(mod "mp"
		{aimRange 200}
		{spreading {SpreadRadius 10.0}}	; m
		{maxRange 240}
		{speed 50}		
		{piercing  20 22 100 16 200 12 300 8 500 8}
	)
}
{weapon "75mmM8" from "gun"      ; cannon M8 
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 16}}	; m
	{rechargeTime 3.0}              ; s
	{speed 70}						; m/s
        {gravity 1.0}
	{piercing  20 22 100 16 200 12 300 8 500 8}
	(mod "mp"
		{maxRange 250}					; m
		{spreading {SpreadRadius 10.0}}	; m
		{speed 50}		
		{piercing  20 22 100 16 200 12 300 8 500 8}
	)
}
{weapon "76mm_kt26" from "gun"      ; BT-7A
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 14}}	; m
	{rechargeTime 3.5}              ; s
	{speed 60}								; m/s
        {gravity 1.0}
	{piercing  20 24 100 20 200 16 300 12 500 10}
	(mod "mp"
		{spreading {SpreadRadius 12.0}}	; m
                {aimRange 200}
		{maxRange 240}
		{speed 60}
		{piercing  20 24 100 20 200 16 300 12 500 10}
	)
}
{weapon "76mm_f24" from "gun"      ; cannon 76mm mod 43 
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 16}}	; m
	{rechargeTime 3.0}              ; s
	{speed 85}						; m/s
        {gravity 0.7}
	{piercing  20 22 100 16 200 12 300 8 500 8}
	(mod "mp"
		{maxRange 240}					; m
		{spreading {SpreadRadius 10.0}}	; m
		{speed 50}		
		{piercing  20 22 100 16 200 12 300 8 500 8}
	)
}
{weapon "76mm_L11" from "gun"       ; T-34/76
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 200}					; m
	{minRange 2}					; m
	{maxRange 240}					; m
	{spreading {SpreadRadius 9.0}}	; m
	{rechargeTime 5.0}              ; s
	{speed 190}						; m/s
	{piercing  20 73 100 62 200 56 300 34 500 15}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 73 100 62 200 56 300 34 500 15}
	)
}
{weapon "76mm_f34" from "gun"       ; KV-1, T34/43
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 8.0}}	; m
	{rechargeTime 5.0}              ; s
	{speed 200}						; m/s
	{piercing  20 86 100 75 200 63 300 48 500 25}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 86 100 75 200 63 300 48 500 25}
	)
}
{weapon "76mm_zis3" from "gun"      ; Cannon ZIS-3
	{fireSound "heavy_shot.cannon"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 7.0}}	; m
	{rechargeTime 3.5}              ; s
	{speed 190}						; m/s
	{piercing  20 82 100 75 200 67 300 50 500 31}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 82 100 75 200 67 300 50 500 31}
	)
}
{weapon "76mm_f22" from "gun"      ; Cannon pak-36
	{fireSound "heavy_shot.cannon"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 6.5}}	; m
	{rechargeTime 4.2}              ; s
	{speed 190}						; m/s
	{piercing  20 90 100 81 200 72 300 55 500 34}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 90 100 81 200 72 300 55 500 34}
	)
}
{weapon "76mm_mk4" from "gun"      ; M4A3
	{fireSound "heavy_shot.76a_mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 5.7}}	; m
	{rechargeTime 4.5}              ; s
	{speed 240}						; m/s
	{piercing  20 138 100 123 200 106 300 78 500 48}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 138 100 123 200 106 300 78 500 48}
	)
}
{weapon "76mm_m7" from "gun"      ; Volverine
	{fireSound "heavy_shot.76a_mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 5.6}}	; m
	{rechargeTime 4.5}              ; s
	{speed 240}						; m/s
	{piercing  20 131 100 120 200 110 300 70 500 40}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 131 100 120 200 110 300 70 500 40}
	)
}
{weapon "76mm_m1A2" from "gun"      ; hellcat
	{fireSound "heavy_shot.76a_mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 205}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 4.5}              ; s
	{speed 240}						; m/s
	{piercing  20 142 100 129 200 118 300 85 500 54}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 142 100 129 200 118 300 85 500 54}
	)
}
{weapon "77mm_OQF" from "gun"      ; Comet 
        {fireSound "heavy_shot.76a_mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 4.8}              ; s
	{speed 290}						; m/s
	{piercing  20 150 100 135 200 120 300 90 500 62}
	(mod "mp"
		{maxRange 240}					; m
		{piercing  20 150 100 135 200 120 300 90 500 62}
	)
}
{weapon "76mm_OQF" from "gun"      ; Firefly, 17-Pound, Achilles, Star
	{fireSound "heavy_shot.76a_mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 200}					; m
	{maxRange 240}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 4.5}}	; m
	{rechargeTime 5.0}              ; s
	{speed 300}						; m/s
	{piercing   20 158  100 142 200 122 300 92 500 71}
	(mod "mp"
		{maxRange 240}					; m
		{piercing   20 158  100 142 200 122 300 92 500 71}
	)
}

{weapon "85mm_zis53" from "gun"     ; T-34/85
	{fireSound "heavy_shot.85mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 220}					; m
	{maxRange 250}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 6.5}              ; s
	{speed 250}						; m/s
	{piercing  20 120 100 102 200 89 300 69 500 51}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  20 120 100 102 200 89 300 69 500 51}
	)
}
{weapon "85mm_d5" from "gun"		; KV-85, IS-85
	{fireSound "heavy_shot.85mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 220}					; m
	{maxRange 250}					; m
	{minRange 5.5}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 6.5}              ; s
	{speed 250}						; m/s
	{piercing  20 120 100 102 200 89 300 69 500 51}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  20 120 100 102 200 89 300 69 500 51}
	)
}
{weapon "88mm_kwk36" from "gun"     ; Pz-6, Pz-6e
	{fireSound "heavy_shot.88mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 220}					; m
	{maxRange 250}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 4.5}}	; m
	{rechargeTime 6.0}				; s
	{speed 280}						; m/s
	{piercing 20 154 100 130 200 119 300 99 500 70}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 154 100 130 200 119 300 99 500 70}
	)
}
{weapon "88mm_kwk43" from "gun"     ; Pz-6b "King Tiger", Jugdpather
	{fireSound "heavy_shot.88mm"}
	{aimRange 182}					; m
	{maxRange 96}					; m
	{minRange 6}					; m
	{spreading {SpreadRadius 3.5}}	; m
	{rechargeTime 6}				; s
	{speed 220}						; m/s
	{piercing	10 260 		40 156	180 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 200 		40 120	 60 95  100  35}
	)
}
{weapon "88mm_flak41" from "gun"    ; Flak-41
	{fireSound "heavy_shot.88mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 4.8}}	; m
	{rechargeTime 5.5}				; s
	{speed 280}						; m/s
	{piercing 20 154 100 130 200 119 300 99 500 70}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 154 100 130 200 119 300 99 500 70}
	)
}
{weapon "88mm_pak43" from "gun"     ; Ferdinand, JagdPanther
	{fireSound "heavy_shot.88mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 220}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 4.4}}	; m
	{rechargeTime 6.0}				; s
	{speed 300}						; m/s
	{piercing 20 203 100 185 200 165 300 128 500 97}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 203 100 185 200 165 300 128 500 97}
	)
}
{weapon "88mm_type99" from "gun"     ; Chi-Ri
	{fireSound "heavy_shot.88mmj"}
	{reloadSound "reload.gun_r03"}
	{aimRange 220}					; m
	{maxRange 250}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 4.1}}	; m
	{rechargeTime 6.2}				; s
	{speed 290}						; m/s
	{piercing 20 175 100 150 200 124 300 100 500 75}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 175 100 150 200 124 300 100 500 75}
	)
}
{weapon "90mm_m3" from "gun"     ; m36 Jackson, m26 Pershing
	{fireSound "heavy_shot.88mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.2}}	; m
	{rechargeTime 7}				; s
	{speed 280}						; m/s
	{piercing 20 151 100 142 200 121 300 104 500 69}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 151 100 142 200 121 300 104 500 69}
	)
}
{weapon "90mm_t15e2" from "gun"     ; SuperPershing
	{fireSound "heavy_shot.88mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 7}				; s
	{speed 280}						; m/s
	{piercing 20 201 100 178 200 149 300 114 500 89}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 201 100 178 200 149 300 114 500 89}
	)
}
{weapon "95mm_QQF" from "gun"      ; mkivchurchill-95
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 300}					; m
	{maxRange 300}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 14}}	; m
	{rechargeTime 7.0}				; s
	{gravity 1.0}
	{speed 100}						; m/s
	{piercing 20 50 100 39 200 34 300 30 500 26}
	(mod "mp"
		{maxRange 300}					; m
		{aimRange 300}				; m
		{piercing 20 50 100 39 200 34 300 30 500 26}
		{speed 70}					; m/s
	)
}
{weapon "93mm_QQF" from "gun"     ; A39
	{fireSound "heavy_shot.88mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 2}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 7}				; s
	{speed 280}						; m/s
	{piercing 20 190 100 185 200 129 300 104 500 79}
	(mod "mp"
		{maxRange 250}					; m
		{piercing 20 190 100 185 200 129 300 104 500 79}
	)
}
{weapon "87mm_QQF" from "gun"      ; mkivchurchill-95, 25 pdr
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 300}					; m
	{maxRange 300}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 14}}	; m
	{rechargeTime 7.0}				; s
	{gravity 1.0}
	{speed 100}						; m/s
	{piercing 20 50 100 39 200 34 300 30 500 26}
	(mod "mp"
		{maxRange 300}					; m
		{aimRange 300}				; m
		{piercing 20 50 100 39 200 34 300 30 500 26}
		{speed 70}					; m/s
	)
}
{weapon "100mm_D10_L54" from "gun"      ; SU-100
	{fireSound "heavy_shot.88mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 8}				; s
	{speed 320}						; m/s
	{piercing  10 164 100 155 200 135 300 105 500 80}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  10 164 100 155 200 135 300 105 500 80}
	)
}
{weapon "100mm_wz14/19" from "gun"      ; cannon_100
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 8}				; s
	{speed 290}						; m/s
	{piercing  10 164 100 155 200 135 300 105 500 80}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  10 164 100 155 200 135 300 105 500 80}
	)
}
{weapon "101mm/50" from "gun"      ; cannon_105
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 8}				; s
	{speed 290}						; m/s
	{piercing  10 164 100 155 200 135 300 105 500 80}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  10 164 100 155 200 135 300 105 500 80}
	)
}
{weapon "105mm_type6" from "gun"      ; Ho-Ri
	{fireSound "heavy_shot.105mmatj"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 7.5}				; s
	{speed 300}						; m/s
	{piercing  20 203 100 185 200 165 300 128 500 97}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  20 203 100 185 200 165 300 128 500 97}
	)
}
{weapon "105mm_m2a1" from "gun"      ; m7 Priest
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 330}					; m
	{maxRange 330}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 17}}	; m
	{rechargeTime 8}				; s
	{gravity 1.0}
	{speed 55}						; m/s
	{piercing 20 40 100 29 200 24 300 20 500 16}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing 20 40 100 29 200 24 300 20 500 16}
		{speed 55}					; m/s
	)
}
{weapon "105mm_stuh42" from "gun"      ; stuh42
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 330}					; m
	{maxRange 330}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 15}}	; m
	{rechargeTime 8}				; s
	{gravity 1.0}
	{speed 60}						; m/s
	{piercing 20 63 100 59 200 54 300 40 500 36}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing 20 63 100 59 200 54 300 40 500 36}
		{speed 70}					; m/s
	)
}
{weapon "105mm_leFH18" from "gun"      ; wespe
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 340}					; m
	{maxRange 340}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 15}}	; m
	{rechargeTime 7}				; s
	{gravity 1.0}
	{speed 65}						; m/s
	{piercing 20 63 100 59 200 54 300 40 500 36}
	(mod "mp"
		{maxRange 340}					; m
		{aimRange 340}				; m
		{piercing 20 63 100 59 200 54 300 40 500 36}
		{speed 70}					; m/s
	)
}
{weapon "105mm" from "gun"      ; M4a3_105
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 330}					; m
	{maxRange 330}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 9}}	; m
	{rechargeTime 8}				; s
	{gravity 1.0}
	{speed 110}						; m/s
	{piercing 20 102 100 49 200 34 300 30 500 26}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing 20 102 100 49 200 34 300 30 500 26}
		{speed 90}					; m/s
	)
}
{weapon "105mm_type91" from "gun"      ; Canon type91, Ho-Ni II
	{fireSound "heavy_shot.105mmj"}
        {reloadSound "reload.gun_r01"}
	{aimRange 330}					; m
	{maxRange 330}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 9}}	; m
	{rechargeTime 8}				; s
	{gravity 1.0}
	{speed 110}						; m/s
	{piercing 20 102 100 49 200 34 300 30 500 26}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing 20 102 100 49 200 34 300 30 500 26}
		{speed 90}					; m/s
	)
}
{weapon "105mm_naval" from "gun"      ; 105mm naval
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 7}				; s
	{speed 300}						; m/s
	{piercing  10 164 100 155 200 135 300 105 500 80}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  10 164 100 155 200 135 300 105 500 80}
	)
}
{weapon "105mm_T5E2" from "gun"      ; T29
	{fireSound "heavy_shot.105mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 7.2}				; s
	{speed 320}						; m/s
	{piercing  20 213 100 195 200 175 300 138 500 99}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  20 213 100 195 200 175 300 138 500 99}
	)
}
{weapon "120mm_type10" from "gun"      ; Chi-ha120
	{fireSound "heavy_shot.120mmj"}
        {reloadSound "reload.gun_r01"}
	{aimRange 220}					; m
	{minRange 5}					; m
	{maxRange 250}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 7}				; s
	{speed 300}						; m/s
	{piercing  10 160 100 150 200 130 300 100 500 80}
	(mod "mp"
		{maxRange 250}					; m
		{piercing  10 160 100 150 200 130 300 100 500 80}
	)
}
{weapon "122mm_d25" from "gun"      ; IS-2
	{fireSound "heavy_shot.122mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 225}					; m
	{minRange 2}					; m
	{maxRange 260}					; m
	{spreading {SpreadRadius 6.0}}	; m
	{rechargeTime 12.5}              ; s
	{speed 300}						; m/s
	{piercing 20 170 100 152 200 142 300 122 500 82}
	(mod "mp"
		{maxRange 260}					; m
		{piercing 20 170 100 152 200 142 300 122 500 82}
	)
}
{weapon "127mm" from "gun"      ; 4.7 Naval Gun
	{fireSound "heavy_shot.122mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 225}					; m
	{minRange 5}					; m
	{maxRange 260}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 10}				; s
	{speed 300}						; m/s
	{piercing  20 170 100 152 200 142 300 122 500 82}
	(mod "mp"
		{maxRange 260}					; m
		{piercing  20 170 100 152 200 142 300 122 500 82}
	)
}
{weapon "128mm_pak44" from "gun"    ; Jadgtiger
	{fireSound "heavy_shot.122mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 225}					; m
	{maxRange 260}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 5.0}}	; m
	{rechargeTime 10.5}				; s
	{speed 300}						; m/s
	{piercing 20 199 100 171 200 148 300 117 500 88}
	(mod "mp"
		{maxRange 260}					; m
		{piercing 20 199 100 171 200 148 300 117 500 88}
	)
}
{weapon "140mm_type11" from "gun"      ; Naval Gun 14Cm
	{fireSound "heavy_shot.150mmj"}
        {reloadSound "reload.gun_r01"}
	{aimRange 260}					; m
	{minRange 5}					; m
	{maxRange 270}					; m
	{spreading {SpreadRadius 7.0}}	; m
	{rechargeTime 8.5}				; s
	{speed 200}						; m/s
	{piercing  10 170 100 140 200 110 300 90}
	(mod "mp"
		{maxRange 270}					; m
		{piercing  10 170 100 140 200 110 300 90}
	)
}
{weapon "150mm_sfh18" from "gun"    ; Hummel
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 330}					; m
	{maxRange 330}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 25}}	; m
	{rechargeTime 13}				; s
	{gravity 0.7}
	{speed 50}						; m/s
	{piercing	50 160         500 20}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing	50 160         500 20}
		{speed 50}					; m/s
	)
}
{weapon "150mm_type38" from "gun"    ; Ho-Ro
	{fireSound "heavy_shot.150mmj"}
        {reloadSound "reload.gun_r01"}
	{aimRange 300}					; m
	{maxRange 300}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 15}}	; m
	{rechargeTime 13}				; s
	{gravity 1}
	{speed 75}						; m/s
	{piercing	30 145         500 20}
	(mod "mp"
		{maxRange 300}					; m
		{aimRange 300}				; m
		{piercing	50 145         500 20}
		{speed 50}					; m/s
	)
}
{weapon "150mm_sIG33" from "gun"    ; Bison
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 300}					; m
	{maxRange 300}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 15}}	; m
	{rechargeTime 13}				; s
	{gravity 1}
	{speed 80}						; m/s
	{piercing	10 150         500 20}
	(mod "mp"
		{maxRange 300}					; m
		{aimRange 300}				; m
		{piercing	50 145         500 20}
		{speed 50}					; m/s
	)
}
{weapon "150mm_mortar" from "gun"    ; 15cm Mortar
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 300}					; m
	{maxRange 300}					; m
	{minRange 10}					; m
	{spreading {SpreadRadius 20}}	; m
	{rechargeTime 11}				; s
	{gravity 1}
	{speed 130}						; m/s
	{piercing	10 150         200 0}
	(mod "mp"
		{maxRange 320}					; m
		{piercing	10 150         200 0}
	)
}
{weapon "152mm_ML20" from "gun"     ; KV-2
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 300}					; m
	{maxRange 300}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 10}}	; m
	{rechargeTime 15.0}				; s
	{speed 130}						; m/s
	{gravity 1}
	{piercing 20 95 100 87 200 82 300 68 500 50}
	(mod "mp"
		{aimRange 320}				; m
		{maxRange 320}					; m
		{piercing 20 95 100 87 200 82 300 68 500 50}
	)
}
{weapon "152mm_ML20_isu" from "gun"     ; isu-152
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 320}					; m
	{maxRange 320}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 24}}	; m
	{rechargeTime 15}				; s
	{gravity 1}
	{speed 100}						; m/s
	{piercing 20 95 100 87 200 82 300 68 500 50}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing 20 105 100 97 200 92 300 80 500 60}
		{speed 60}					; m/s
	)
}
{weapon "152mm_M30" from "gun"      ; 
	{fireSound "heavy_shot.122mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 320}					; m
	{maxRange 320}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 20}}	; m
	{gravity 1}
	{rechargeTime 11.0}				; s
	{speed 60}						; m/s
	{piercing 20 78 100 67 200 62 300 58 500 50}
	(mod "mp"
		{maxRange 330}					; m
                {aimRange 330}	
		{piercing 20 78 100 67 200 62 300 58 500 50}
	)
}
{weapon "155mm" from "gun"     ; long tom
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 320}					; m
	{maxRange 320}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 23}}	; m
	{rechargeTime 15}				; s
	{gravity 1}
	{speed 100}						; m/s
	{piercing 20 95 100 87 200 82 300 68 500 50}
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing 20 135 100 120 200 92 300 88 500 60}
		{speed 60}					; m/s
	)
}
{weapon "203mm_gun" from "gun"		; 203mm Mortar
	{fireSound "heavy_shot.203mm"}
	{aimRange 400}					; m
	{minRange 10}					; m
	{maxRange 400}					; m
	{spreading {SpreadRadius 26}}	; m
	{rechargeTime 26.0}				; s
	{speed 160}						; m/s
	{piercing	10 250     200 0}
	(mod "mp"
		{maxRange 400}					; m
		{piercing	10 250     200 0}
	)
}
{weapon "220mm_gun" from "gun"		; 220mm Mortar
	{fireSound "heavy_shot.203mm"}
	{aimRange 400}					; m
	{minRange 12}					; m
	{maxRange 400}					; m
	{spreading {SpreadRadius 26}}	; m
	{rechargeTime 26.0}
	{gravity 1}				; s
	{speed 90}						; m/s
	{piercing	10 250     200 0}
	(mod "mp"
		{maxRange 400}					; m
		{piercing	10 250     200 0}
	)
}
{weapon "airborne_roket_launcher" from "20mm_kwk30"
	{aimRange 400}				; m
	{Spreading
		{SpreadRadius 0.5}
	}
	{foresight "Foresight3"}
	{recoveryTime 0.1}			; s
	{rechargeTime 5.0}			; s
	{speed 40}					; m/s
	{gravity 0.6}
	{piercing   10 7     50 5    100 3 200 0}
	{automatic}
	(mod "mp"
		{maxRange}					; m
		{piercing   10 7     50 5    100 3 200 0}
	)
}
{weapon "torp_launcher" from "20mm_kwk30"
	{fireSound "smg_shot.grenade_2"}
	{reloadSound "reload.pak35_r"}
	{aimRange 210}				; m
	{minRange 10}				; m
	{maxRange 250}				; m
	{foresight "Foresight3"}
	{recoveryTime 0.1}			; s
	{rechargeTime 5.0}			; s
	{speed 10}					; m/s
	{gravity 0}
   	{piercing  80 95	100 80}
	(mod "mp"
		{aimRange 210}
		{maxRange 250}					; m
   		{piercing  80 95	100 80}
	)
}
{weapon "300mm_ha-to" from "gun"    ; ha-to
	{fireSound "heavy_shot.152mm"}
        {reloadSound "reload.gun_r01"}
	{aimRange 330}					; m
	{maxRange 330}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 25}}	; m
	{rechargeTime 20}				; s
	{gravity 0.7}
	{speed 50}						; m/s
	{piercing	100 120  200 100  300 50 }
	(mod "mp"
		{maxRange 330}					; m
		{aimRange 330}				; m
		{piercing	100 120  200 100  300 50 }
		{speed 50}					; m/s
	)
}
{weapon "460mm_type94" from "gun"		; 46cm Yamato
	{fireSound "heavy_shot.203mm"}
	{aimRange 400}					; m
	{minRange 12}					; m
	{maxRange 400}					; m
	{spreading {SpreadRadius 26}}	; m
	{rechargeTime 26.0}
	{gravity 1}				; s
	{speed 99}						; m/s
	{piercing	100 120  200 100  300 75  400 50}
	(mod "mp"
		{maxRange 400}					; m
		{piercing	100 120  200 100  300 75  400 50}
	)
}
