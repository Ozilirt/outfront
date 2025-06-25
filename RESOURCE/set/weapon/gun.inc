
;SDL

(include "gun_ammo.inc")

{weapon pattern "gun"
	{type bullet}
	{foresight "Foresight1"}
	{aimRange 100}				; m
	{maxRange 80}					; m
	{minRange 2}				; m
	{spreading {SpreadRadius 3.0}	}	; m
	{healthDamage 3000}
	{rechargeTime 5.0}			; s
	{speed 200}					; m/s
    {AimingTolerance 2}			; degree
    {RelaxationTime 0.5}
	{cursor "/interface/cursor/cannon_on.ebm"}
	(mod "mp"
		{maxRange}					; m
	)
}

{weapon "20mm_kwk30" from "gun"		; Pz-2, SdKfz-232
	{fireSound "heavy_shot.20mm"}
	{aimRange 80}					; m
	{maxRange 80}					; m
	{aimRange "tank"30}				; m
	{minRange 2}					; m
	{spreading {spreadradius 2}}	; m
	{rechargeTime 2}				; s
	{piercing    10 20    20 15    80 0}
	{shellEnergy 5}
	(mod "mp"

		{piercing    10 20    20 15  50 5 80 0}
		{maxRange}					; m
	)
}

{weapon "20mm_flak38" from "gun"	; Flakpanzer, SdKfz-10, Flak-38
	{fireSound "heavy_shot.20mm"}
	{aimRange 100}					; m
	{minRange 2}					; m
	{maxRange 101}					; m
	{RecoveryTime 0.1}
	{RechargeTime 4}
	{reloadSound "reload.flak38_r"}
	{spreading
		{spreadradius 	5}
		{SpreadXYRatio	4}
		{SpreadPower	3}
	}	; m
	{healthDamage 300}
	{AimingTolerance 40}
	{Automatic}

	{burst
		{min 4}
		{short 2.5 1}
		{long 7 2}
	}	
	{speed 400}						; m/s
;		{traceFreq 0.2}
	{piercing    10 20    20 15    100 0}
	{shellEnergy 5}
	(mod "mp"
		{maxRange}					; m
		{piercing    10 20    20 15    100 0}

	)
}

{weapon "37mm_pak35" from "gun"		; SdKfz-250/10
	{fireSound "heavy_shot.37mm"}
	{reloadSound "reload.pak35_r"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 60}					; m
	{spreading {SpreadRadius 1.5}}	; m
	{rechargeTime 3}				; s
	{speed 200}						; m/s
	{piercing    10 50    20 35    80 0}
	{shellEnergy 10}
	(mod "mp"
		{maxRange}					; m
		{piercing    10 50    20 35    80 0}

	)
}

{weapon "45mm_20k" from "gun"		; T-26, BT-7
	{fireSound "heavy_shot.45mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 4.0}				; s
	{speed 220}						; m/s
	{piercing	10 60     50 25    100 0}
	{shellEnergy 15}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 60     50 25    100 0}
	)
}

{weapon "50mm_kwk38" from "gun"     ; Pz-3G
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r02"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 4.0}				; s
	{speed 200}						; m/s
	{piercing    10 100     20 50    100 0}
	{shellEnergy 17}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 60     50 25    100 0}

	)
}

{weapon "57mm_OQF" from "gun"     ; Pz-3G
	{fireSound "heavy_shot.50mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 4.0}				; s
	{speed 200}						; m/s
	{piercing    10 95     20 40    80 0}
	{shellEnergy 20}
	(mod "mp"
		{maxRange}					; m
		{piercing    10 95     20 40    80 0}
	)
}

{weapon "75mm_kwk37" from "gun"     ; Pz-4D
	{fireSound "heavy_shot.75mm"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 4.5}				; s
	{speed 200}						; m/s
	{piercing	10 100     20 40    80 0}
	(mod "mp"
		{maxRange}					; m
		{piercing    10 95     20 40    80 0}
	)
}

{weapon "75mm_stuk37" from "gun"    ; StuG-3
	{fireSound "heavy_shot.75mm"}
	{aimRange 90}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 3.5}				; s
	{speed 220}						; m/s
	{piercing	10 100     20 40    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     20 40    100 0}
	)
}

{weapon "75mm_kwk40" from "gun"     ; Pz-4G
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 4.5}				; s
	{speed 200}						; m/s
	{piercing	10 100     20 80    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     20 80    100 0}
	)
}

{weapon "75mm_stuk40" from "gun"	; StuG-40
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 4}				; s
	{speed 200}						; m/s
	{piercing	10 100     30 80    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     30 80    100 0}
	)
}

{weapon "75mm_kwk42" from "gun"     ; Pz-5"Panther"
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r01"}
	{aimRange 110}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{maxRange 80}					; m
	{rechargeTime 5}				; s
	{speed 200}						; m/s
	{piercing	10 140     30 100    120 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 140     30 100    120 0}
	)
}

{weapon "75mm_pak40" from "gun"     ; Cannon Pak-40
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r03"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{maxRange 80}					; m
	{rechargeTime 5.0}				; s
	{speed 250}						; m/s
	{piercing	10 140     30 100    100  0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 140     30 100    100  0}
	)
}

{weapon "75mm_m3" from "gun"     ; Cannon Pak-40
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange "heavy tank" 15}		; m
	{aimRange "tank" 30}			; m
	{aimRange 80}					; m
	{maxRange 80}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 5.0}				; s
	{speed 250}						; m/s
	{piercing	10 90     30 40    110 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 90     30 40    110 0}
	)
}
{weapon "75mm_m6" from "gun"     ; Cannon Pak-40
	{fireSound "heavy_shot.75mm"}
	{reloadSound "reload.gun_r04"}
	{aimRange "heavy tank" 15}		; m
	{aimRange "tank" 30}			; m
	{aimRange 70}					; m
	{maxRange 60}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 5.0}				; s
	{speed 250}						; m/s
	{piercing	10 90     30 40    110 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 90     30 40    110 0}
	)
}
{weapon "76mm_kt26" from "gun"      ; BT-7A
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r04"}
	{aimRange 130}					; m
	{minRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{maxRange 120}					; m
	{rechargeTime 4.0}              ; s
	{speed 200}						; m/s
	{piercing	10 100     30 30    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     30 30    100 0}
	)
}

{weapon "75mmM3" from "gun"      ; M8 Scott
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r04"}
	{aimRange 110}					; m
	{minRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{maxRange 100}					; m
	{rechargeTime 3.0}              ; s
	{speed 190}						; m/s
	{piercing	10 100     30 30    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     30 30    100 0}
	)
}

{weapon "76mm_L11" from "gun"       ; T-34/76
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r04"}
	{aimRange 80}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 4.5}              ; s
	{speed 200}						; m/s
	{piercing	10 100     20 45    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     20 45    100 0}
	)
}

{weapon "76mm_f34" from "gun"       ; KV-1
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange "heavy tank" 20}		; m
	{aimRange "tank" 40}			; m
	{aimRange 80}					; m
	{maxRange 80}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 1.0}}	; m
	{rechargeTime 4.0}              ; s
	{speed 200}						; m/s
	{piercing	10 90     50 50    100 30    200  15}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 90     50 50    100 30    200  15}
	)
}

{weapon "76mm_zis3" from "gun"      ; Cannon ZIS-3
	{fireSound "heavy_shot.76mm"}
	{reloadSound "reload.gun_r00"}
	{aimRange 80}					; m
	{maxRange 80}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 3.5}              ; s
	{speed 200}						; m/s
	{piercing	10 100     30 60    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 100     30 60    100 0}
	)
}

{weapon "76mm_mk4" from "gun"      ; Cannon ZIS-3
	{fireSound "heavy_shot.76mm"}
	{aimRange "heavy tank" 25}		; m
	{aimRange "tank" 35}			; m
	{aimRange 80}					; m
	{maxRange 80}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 3.5}              ; s
	{speed 200}						; m/s
	{piercing	10 110     20 50    110 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 110     20 50    110 0}
	)
}
{weapon "85mm_zis53" from "gun"     ; T-34/85
	{fireSound "heavy_shot.85mm"}
	{aimRange 90}					; m
	{maxRange 80}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 4.5}              ; s
	{speed 200}						; m/s
	{piercing	10 100     20 90    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 110     20 50    110 0}
	)
}

{weapon "85mm_d5" from "gun"		; KV-85, IS-1
	{fireSound "heavy_shot.85mm"}
	{reloadSound "reload.gun_r04"}
	{aimRange "heavy tank" 40}		; m
	{aimRange "tank" 50}			; m
	{aimRange 80}					; m
	{maxRange 80}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 5.0}              ; s
	{speed 200}						; m/s
	{piercing	10 120     30 80    120 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 120     30 80    120 0}
	)
}

{weapon "88mm_kwk36" from "gun"     ; Pz-6"Tiger"
	{fireSound "heavy_shot.88mm"}
	{aimRange 90}					; m
	{maxRange 80}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 2.5}}	; m
	{rechargeTime 4.5}				; s
	{speed 220}						; m/s
	{piercing	10 170     60 90    120 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 170     60 90    120 0}
	)
}

{weapon "88mm_kwk43" from "gun"     ; Pz-6"King Tiger"
	{fireSound "heavy_shot.88mm"}
	{aimRange 140}					; m
	{maxRange 80}					; m
	{minRange 6}					; m
	{spreading {SpreadRadius 3.5}}	; m
	{rechargeTime 6}				; s
	{speed 220}						; m/s
	{piercing	10 200 		40 120	150 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 200 		40 120	150 0}
	)
}

{weapon "88mm_flak41" from "gun"    ; Cannon Flak-41
	{fireSound "heavy_shot.88mm"}
	{aimRange 100}					; m
	{minRange 5}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 4.5}				; s
	{speed 220}						; m/s
	{piercing	10 120     20 90    100 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 120     20 90    100 0}
	)
}

{weapon "88mm_pak43" from "gun"     ; "Ferdinand", "JagdPanther"
	{fireSound "heavy_shot.88mm"}
	{aimRange 110}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 3.5}}	; m
	{rechargeTime 5}				; s
	{speed 220}						; m/s
	{piercing	10 150     30 120    120 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 150     30 120    120 0}
	)
}

{weapon "90mm_m3" from "gun"     ; "Ferdinand", "JagdPanther"
	{fireSound "heavy_shot.88mm"}
	{aimRange 110}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 3.5}}	; m
	{rechargeTime 5}				; s
	{speed 220}						; m/s
	{piercing	10 150     30 110    100 90    200  0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 150     30 110    100 90    200  0}
	)
}
{weapon "122mm_d25" from "gun"      ; IS-2
	{fireSound "heavy_shot.85mm"}
	{aimRange 90}					; m
	{minRange 2}					; m
	{maxRange 80}					; m
	{spreading {SpreadRadius 2.0}}	; m
	{rechargeTime 6.0}              ; s
	{speed 200}						; m/s
	{piercing	10 200     30 120    100 90    250 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 200     30 120    100 90    250 0}
	)
}

{weapon "128mm_pak44" from "gun"    ; "JagdTiger"
	{fireSound "heavy_shot.88mm"}
	{aimRange 140}					; m
	{maxRange 80}					; m
	{minRange 2}					; m
	{spreading {SpreadRadius 4}}	; m
	{rechargeTime 6}				; s
	{speed 200}						; m/s
	{piercing	10 200     150 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 200     150 0}
	)
}

{weapon "150mm_sfh18" from "gun"    ; "Hummel"
	{fireSound "heavy_shot.150mm"}
	{aimRange 140}					; m
	{maxRange 120}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 4.0}}	; m
	{rechargeTime 10}				; s
	{gravity 0.7}
	{speed 200}						; m/s
	{piercing	10 220     150 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 220     150 0}
		{speed 32}						; m/s
	)
}

{weapon "152mm_ML20" from "gun"     ; KV-2
	{fireSound "heavy_shot.152mm"}
	{aimRange 70}					; m
	{maxRange 95}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 6.0}				; s
	{speed 160}						; m/s
	{piercing	10 200     50 100    150 0}
	(mod "mp"
		{aimRange 120}				; m
		{maxRange}					; m
		{piercing	10 200     50 100    150 0}

	)
}

{weapon "152mm_ML20_isu" from "gun"     ; isu-152
	{fireSound "heavy_shot.152mm"}
	{aimRange 100}					; m
	{maxRange 120}					; m
	{minRange 8}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 12}				; s
	{gravity 0.7}
	{speed 40}						; m/s
	{piercing	10 200     50 70    150 0}
	(mod "mp"
		{aimRange 350}					; m
		{maxRange}					; m
		{minRange 3}					; m		
		{piercing	10 200     50 70    150 0}

	)

}


{weapon "152mm_M30" from "gun"      ; Cannon M-30
	{fireSound "heavy_shot.152mm"}
	{aimRange 90}					; m
	{maxRange 70}					; m
	{minRange 5}					; m
	{spreading {SpreadRadius 3.0}}	; m
	{rechargeTime 5.0}				; s
	{speed 160}						; m/s
	{piercing	10 200     30 100    150 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 200     30 100    150 0}
	)
}

{weapon "203mm_gun" from "gun"		; "203mm Mortar"
	{fireSound "heavy_shot.203mm"}
	{aimRange 200}					; m
	{minRange 10}					; m
	{maxRange}					; m
	{spreading {SpreadRadius 4.5}}	; m
	{rechargeTime 6.0}				; s
	{speed 160}						; m/s
	{piercing	10 250     200 0}
	(mod "mp"
		{maxRange}					; m
		{piercing	10 250     200 0}
	)
}

{weapon "airborne_roket_launcher" from "20mm_kwk30"
	{aimRange 100}				; m
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
