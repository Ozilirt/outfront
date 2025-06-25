;SDL

{weapon pattern "smg" from "bullet"
	{aimRange 60}				; m
	{spreading
		{SpreadRadius 3.0}; m
		{SpreadXYRatio	2.5}
		{SpreadPower	3.0}

	}
	{recoveryTime 0.1}			; s
	{rechargeTime 2.5}			; s
	{speed 150}					; m/s
	{Automatic}
	{maxRange 50}					; m
	{traceFreq 0.4}
	{healthing 5 60 10 50 25 30 50 20 100 5}
	{piercing   10 4  30 3   70 0}
	{burst 
                {min 1}
		{short 4.5 1.5}
		{long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
;#################################################################
;############### 7.62x23(TT) ###################
;#################################################################
{weapon "ppsh" from "smg"
	{fireSound	"smg_shot.ppsh"}
	{reloadSound "reload.mp44_r"}
	{aimRange 60}				; m
	{maxRange 60}					; m
	{spreading
		{SpreadRadius 3.0}; m
		{SpreadPower	2.9}

	}
	{recoveryTime 0.075}			; s
	{rechargeTime 3.5}			; s
	{speed 140}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 55 10 50 25 35 50 20 100 5}
	{burst
                {min 1}
		{short 4.5 2.5}
		{long 7.5 3.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "ppsh35" from "smg"
	{fireSound	"smg_shot.ppsh2"}
	{reloadSound "reload.mp44_r"}
	{aimRange 60}				; m
	{maxRange 60}					; m
	{spreading
		{SpreadRadius 2.85}; m
		{SpreadPower	2.9}

	}
	{recoveryTime 0.085}			; s
	{rechargeTime 3.1}			; s
	{speed 140}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 55 10 50 25 35 50 20 100 5}
	{burst
                {min 1}
		{short 4.5 2.5}
		{long 7.5 3.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "type100" from "smg"
	{fireSound	"smg_shot.t100"}
	{reloadSound "reload.sten_r"}
	{aimRange 50}				; m
	{maxRange 50}					; m
	{spreading
		{SpreadRadius 2.85}; m
		{SpreadPower	2.9}
	}
	{recoveryTime 0.085}			; s
	{rechargeTime 3.1}			; s
	{speed 136}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 55 10 50 25 35 50 20 100 5}
	{burst
                {min 1}
		{short 4.5 2.5}
		{long 7.5 3.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "type2smg" from "smg"
	{fireSound	"smg_shot.t2"}
	{reloadSound "reload.sten_r"}
	{aimRange 50}				; m
	{maxRange 50}					; m
	{spreading
		{SpreadRadius 2.85}; m
		{SpreadPower	2.9}
	}
	{recoveryTime 0.085}			; s
	{rechargeTime 3.1}			; s
	{speed 136}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 55 10 50 25 35 50 20 100 5}
	{burst
                {min 1}
		{short 4.5 2.5}
		{long 7.5 3.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "pps" from "smg"
	{fireSound	"smg_shot.pps"}
	{reloadSound "reload.mp44_r"}
	{aimRange 50}				; m
	{maxRange 50}					; m
	{spreading
		{SpreadRadius 2.7}; m
		{SpreadPower	2.8}

	}
	{recoveryTime 0.089}			; s
	{rechargeTime 2.4}			; s
	{speed 145}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 60 10 50 25 35 50 20 100 5}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}

;#################################################################
;################ 7.92­ ###################
;#################################################################
{weapon "sg44" from "smg"    
	{fireSound	"smg_shot.mp44"}
	{reloadSound "reload.mp44_r"}
	{aimRange 80}				; m
	{maxRange 80}					; m
	{spreading
		{SpreadRadius 3.3}; m
		{SpreadXYRatio	2.5}
		{SpreadPower	2.8}

	}
	{recoveryTime 0.12}			; s
	{rechargeTime 3}			; s
	{speed 180}					; m/s
	{Automatic}
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 90 10 80 25 65 50 40 100 20 150 5}
        {burst
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "volksgewehr" from "smg"    
	{fireSound	"smg_shot.volksgewehr"}
	{reloadSound "reload.mp44_r"}
	{aimRange 70}				; m
	{maxRange 70}					; m
	{spreading
		{SpreadRadius 3.4}; m
		{SpreadXYRatio	3.0}
		{SpreadPower	3.0}

	}
	{recoveryTime 0.15}			; s
	{rechargeTime 3}			; s
	{speed 170}					; m/s
	{traceFreq 0.4}
	{piercing   10 3  30 3   200 0}
	{healthing 5 90 10 80 25 65 50 40 100 20 150 5}
	{burst
		{short 4.5 1.5}
		{long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
;#################################################################
;#############  0.45 Cal.(Colt) #################
;#################################################################
{weapon "thompson" from "smg"
        {aimRange 50}
	{maxRange 50}				; m
        {recoveryTime 0.09}			
	{rechargeTime 2.5}
	{fireSound	"smg_shot.thompson"}
	{piercing   10 3  30 3   200 0}
	{healthing 5 90 10 80 25 50 50 30 100 10}
        {burst
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}
        {speed 145}
	{spreading
		{SpreadRadius 2.82}
		{SpreadPower       4.0}
	}
        (mod "mp"
		{maxRange}					; m
	)
}
{weapon "tommy" from "smg"
	{fireSound	"smg_shot.tommy"}
        {reloadSound "reload.mp44_r"}
        {piercing   10 3  30 3   200 0}
	{healthing 5 90 10 80 25 50 50 30 100 10}
        {aimRange 50}
	{maxRange 50}
	{recoveryTime 0.095}			
	{rechargeTime 2.9}
        {burst
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}			
	{speed 142}					; m
	{spreading
		{SpreadRadius 2.9}
		{SpreadPower       3}
	}
        (mod "mp"
		{maxRange}					; m
	)
}
{weapon "m3a" from "smg"
	{fireSound	"smg_shot.m3a"}
        {reloadSound "reload.mp44_r"}
        {piercing   10 3  30 3   200 0}
	{healthing 5 60 10 50 25 30 50 10 100 5}
        {aimRange 50}
	{maxRange 50}
	{recoveryTime 0.125}			
	{rechargeTime 2.5}			
	{speed 130}					; m
	{spreading
		{SpreadRadius 2.9}
		{SpreadPower       3}
	}
        (mod "mp"
		{maxRange}					; m
	)
}
;#################################################################
;############# 9x21(Parabelum) #################
;#################################################################
{weapon "sten" from "smg"
	{fireSound	"smg_shot.sten"}
	{reloadSound "reload.sten_r"}
        {aimRange 50}
	{maxRange 50}					; m
	{spreading
		{SpreadRadius 3.0}; m
		{SpreadPower	3}
	}
	{recoveryTime 0.1}			; s
	{rechargeTime 3}			; s
	{speed 135}					; m/s
	{Automatic}
	{traceFreq 0.5}
	{piercing   10 3  30 3   200 0}
	{healthing 5 60 10 50 25 30 50 20 100 5}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "stenmk5" from "smg"
	{fireSound	"smg_shot.stenmk5"}
	{reloadSound "reload.sten_r"}
	{aimRange 60}				; m
	{maxRange 60}					; m
	{spreading
		{SpreadRadius 2.85}; m
		{SpreadPower	2.9}

	}
	{recoveryTime 0.085}			; s
	{rechargeTime 3.0}			; s
	{speed 145}					; m/s
	{Automatic}
	{traceFreq 0.5}
	{piercing   10 3  30 3   200 0}
	{healthing 5 60  10 50  25 30  50 20  100 5  150 0}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mas1938" from "smg"
        {aimRange 50}
	{maxRange 50}				; m
        {recoveryTime 0.09}			
	{rechargeTime 2.5}
	{fireSound	"smg_shot.mas1938"}
	{piercing   10 3  30 3   200 0}
	{healthing 5 90 10 80 25 50 50 30 100 10}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}
        {speed 145}
	{spreading
		{SpreadRadius 2.82}
		{SpreadPower       4.0}
	}
        (mod "mp"
		{maxRange}					; m
	)
}
{weapon "StenSilenced" from "smg"
	{fireSound	"pistol_shot_silent.welrod"}
	{reloadSound "reload.sten_r"}
	{maxRange 50}
        {aimRange 50}					; m
	{spreading
		{SpreadRadius 2.8}; m
		{SpreadPower	3.0}

	}
	{recoveryTime 0.1}			; s
	{rechargeTime 3}			; s
	{speed 125}					; m/s
	{Automatic}
	{traceFreq 0.5}
	{piercing   10 3  30 3   70 0}
	{healthing 5 60 10 50 25 30 50 20 100 5}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
{weapon "mp38" from "smg"
        {fireSound	"smg_shot.mp38"}
	{maxRange 50}
        {aimRange 50}					; m
	{recoveryTime 0.12}			
	{rechargeTime 2.3}			
	{speed 140}
	{spreading
		{SpreadRadius 2.8}; m
		{SpreadXYRatio	2.8}
		{SpreadPower	2.8}

	}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
        (mod "mp"
		{maxRange}					; m
	)
}
{weapon "mp40" from "smg"
        {fireSound	"smg_shot.mp40"}
	{maxRange 50}
        {aimRange 50}					; m
	{recoveryTime 0.115}			
	{rechargeTime 2.2}			
	{speed 140}
	{spreading
		{SpreadRadius 2.8}; m
		{SpreadXYRatio	2.8}
		{SpreadPower	2.8}

	}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
        (mod "mp"
		{maxRange}					; m
	)
}
{weapon "mp40_I" from "smg"
        {fireSound	"smg_shot.mp40_I"}
	{maxRange 50}
        {aimRange 50}					; m
	{recoveryTime 0.115}			
	{rechargeTime 2.2}			
	{speed 140}
	{spreading
		{SpreadRadius 2.9}; m
		{SpreadXYRatio	2.9}
		{SpreadPower	2.9}

	}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}	
        (mod "mp"
		{maxRange}					; m
	)
}
{weapon "mp41" from "smg"
        {fireSound	"smg_shot.mp41"}
	{maxRange 50}
        {aimRange 50}					; m
	{recoveryTime 0.115}			
	{rechargeTime 2.2}			
	{speed 140}
	{spreading
		{SpreadRadius 2.6}; m
		{SpreadXYRatio	2.5}
		{SpreadPower	2.5}

	}
        {burst
               {min 1}
	       {short 4.5 1.5}
	       {long 7.5 2.5}
	}
        (mod "mp"
		{maxRange}					; m
	)
}