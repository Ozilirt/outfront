;SDL
;SDL

{weapon pattern "mgun" from "bullet"
	{aimRange 50}				; m
	{Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.1}			; s
	{rechargeTime 6.0}			; s
	{speed 200}					; m/s
	{piercing   10 4     30 3    100 0}
	{healthing  5 100 25 80 50 70 100 60 150 30}
	{traceFreq 0.8}
	{Automatic}
	{burst
		{short 5 2}
		{long 8 3}
	}	
	(mod "mp"
		{maxRange}					; m
	)

}
{weapon "browning" from "mgun"
	{fireSound	"mgun_shot.browning"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}
        {Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.11}			; s
	{rechargeTime 8.0}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	{speed 200}					; m/s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "browning100" from "mgun"
	{fireSound	"mgun_shot.browning"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}
        {Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.12}			; s
	{rechargeTime 8.0}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	{speed 200}					; m/s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mle1914" from "mgun"
	{fireSound	"mgun_shot.mle"}
	{reloadSound "reload.mg2_r"}
	{maxRange 150}
        {Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.16}			; s
	{rechargeTime 8.0}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	{speed 200}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "type1hmg" from "mgun"
	{fireSound	"mgun_shot.mle"}
	{reloadSound "reload.mg2_r"}
	{maxRange 150}
        {Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.135}			; s
	{rechargeTime 7.5}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	{speed 200}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "reibel" from "mgun"
	{fireSound	"mgun_shot.reibel"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}
        {Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.12}			; s
	{rechargeTime 8.0}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	{speed 200}					; m/s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "browning_tower" from "mgun"
	{fireSound	"mgun_shot.browning"}
	{reloadSound "reload.mg1_r"}
	{maxRange 200}					; m
	{aimRange 200}
        {Spreading
		{SpreadRadius 6.8}
	}
	{recoveryTime 0.1}
        {healthing  5 100 25 90 50 80 100 50 150 35 200 18}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "m1919a6" from "mgun"
	{fireSound	"mgun_shot.browning"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}					; m
        {Spreading
		{SpreadRadius 6.0}
		{BurstAccuracy 0 0 0 0 0}
	}
	{recoveryTime 0.11}			; s
	{rechargeTime 8.0}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	{speed 200}					; m/s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mg34" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{reloadSound "reload.mg1_r"}	
	{maxRange 150}		
	{Spreading
		{SpreadRadius 6.2}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.11}			; s
	{rechargeTime 7.5}			; s
        {healthing  5 100 25 90 50 80 100 60 150 40}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "dual_mg34" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{reloadSound "reload.mg1_r"}	
	{maxRange 150}				; m
	{Spreading
		{SpreadRadius 6.1}
		{BurstAccuracy 0 0 0 0 0}
	}
        {burst
		{min 2}
		{short 2.5 1}
		{long 7 2}
	}
        {recoveryTime 0.08}			; s
	{rechargeTime 9.0}			; s
        {healthing  5 100 25 90 50 80 100 60 150 40}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mg34_tower" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{reloadSound "reload.mg1_r"}
	{maxRange 200}					; m
	{aimRange 200}
	{Spreading
		{SpreadRadius 6.0}
	}
        {recoveryTime 0.1}
        {healthing  5 100 25 90 50 80 100 50 150 35 200 18}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "mg42_tower" from "mgun"
	{fireSound	"mgun_shot.mg42"}
	{reloadSound "reload.mg1_r"}
	{maxRange 200}
	{aimRange 200}	
	{Spreading
		{SpreadRadius 5.5}
	}
        {recoveryTime 0.1}
        {healthing  5 100 25 90 50 80 100 50 150 35 200 18}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "dt" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 150}
	{Spreading
		{SpreadRadius 6.5}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 6.5}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "ds" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 150}					; m
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mgdt" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 150}					; m
	{aimRange 150}
	{Spreading
		{SpreadRadius 6.0}
	}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "ds_tower" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 200}					; m
	{aimRange 200}
	{Spreading
		{SpreadRadius 6.3}
	}
        {recoveryTime 0.1}
        {healthing  5 100 25 90 50 80 100 50 150 35 200 18}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "maxim" from "mgun"
	{fireSound	"mgun_shot.maxim"}
	{reloadSound "reload.dt1_r"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.25}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 6.5}			; s
        {healthing  5 100 25 90 50 80 100 60 150 35}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mg34i" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}
	{Spreading
		{SpreadRadius 5.5}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 5.0}			; s
        {healthing  5 100 25 90 50 80 100 50 150 35}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mg34s" from "mgun"
	{fireSound	"mgun_shot.mg42"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}
	{Spreading
		{SpreadRadius 5.5}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 5.0}			; s
        {healthing  5 100 25 90 50 80 100 50 150 35}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mg42" from "mgun"
	{fireSound	"mgun_shot.mg42"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}	
	{Spreading
		{SpreadRadius 5.5}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 5.0}			; s
        {healthing  5 100 25 90 50 80 100 50 150 35}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "doublecolt" from "mgun"
	{fireSound	"mgun_shot.mg34"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 7.0}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.11}			; s
	{rechargeTime 6.0}			; s
        {healthing  5 100 25 90 50 80 100 50 150 30}
	{reloadSound "reload.mg1_r"}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "besa" from "mgun"
	{fireSound	"mgun_shot.besa"}		
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 7.0}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 10.0}
        {healthing  5 100 25 80 50 70 100 45 150 35}
	(mod "mp"
		{maxRange 150}				
	)
}
{weapon "Vickers_K_N2_Mk_I" from "mgun"
	{fireSound	"mgun_shot.besa"}			
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.0}
	}
        {recoveryTime 0.088}			; s
	{rechargeTime 3.2}			; s
        {healthing  5 100 25 80 50 70 100 45 150 35}
	(mod "mp"
		{maxRange 150}
	)
}
{weapon "Vickers_Mk_I" from "mgun"
	{fireSound	"mgun_shot.vickers"}
	{reloadSound "reload.dt1_r"}			
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.1}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 3.2}			; s
        {healthing  5 100 25 80 50 70 100 45 150 35}
	(mod "mp"
		{maxRange 150}
	)
}
{weapon "wz33" from "mgun"
	{fireSound	"mgun_shot.vickers"}
	{reloadSound "reload.mg1_r"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.1}
	}
        {recoveryTime 0.1}			; s
	{rechargeTime 3.2}			; s
        {healthing  5 100 25 80 50 70 100 45 150 35}
	(mod "mp"
		{maxRange 150}
	)
}
{weapon "Vickers_tower" from "mgun"
	{fireSound	"mgun_shot.vickers"}
	{reloadSound "reload.dt1_r"}			
	{maxRange 200}					; m
	{aimRange 200}				; m
	{Spreading
		{SpreadRadius 6.0}
	}
        {recoveryTime 0.1}
        {healthing  5 100 25 90 50 80 100 50 150 35 200 18}
	(mod "mp"
		{maxRange 200}
	)
}
{weapon "dp" from "mgun"
	{fireSound	"mgun_shot.dt"}
	{reloadSound "reload.dt1_r"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.3}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.115}			; s
	{rechargeTime 5.5}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "rpd" from "mgun"
	{fireSound	"mgun_shot.rpd"}
	{reloadSound "reload.dt1_r"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.3}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.115}			; s
	{rechargeTime 5.5}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "bren" from "mgun"
	{fireSound	"mgun_shot.bren"}
	{maxRange 150}      					; m
        {healthing  5 100 25 90 50 75 100 50 150 35}
	{Spreading
		{SpreadRadius 5.5}
	}
        {recoveryTime 0.11}			; s
	{rechargeTime 3.0}			; s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "type99" from "mgun"
	{fireSound	"mgun_shot.type99"}
	{maxRange 150}      					; m
        {healthing  5 100 25 90 50 75 100 50 150 35}
	{Spreading
		{SpreadRadius 5.7}
	}
        {recoveryTime 0.12}			; s
	{rechargeTime 3.1}			; s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "type97" from "type99"
        {recoveryTime 0.11}			; s
	{rechargeTime 2.6}			; s
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "johnsonlightgun" from "mgun"
	{fireSound	"mgun_shot.johnsonlightgun"}
	{reloadSound "reload.bar_r"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 5.0}
	}
        {recoverytime 0.1}
        {rechargeTime 2.5}			; s
        {healthing  5 100 25 90 50 75 100 50 150 35}	
	(mod "mp"
		{maxRange 150}					; m
	) 
}
{weapon "ZB-26-30" from "mgun"
	{fireSound	"mgun_shot.ZB-26-30"}
	{reloadSound "reload.mg2_r"}
	{maxRange 150}     					; m
	{Spreading
		{SpreadRadius 5.8}
	}
        {recoveryTime 0.125}			; s
	{rechargeTime 3.0}			; s
        {healthing  5 100 25 80 50 70 100 60 150 30}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "mg13" from "mgun"
	{fireSound	"mgun_shot.MG13"}
	{reloadSound "reload.mg2_r"}		
	{maxRange 150}      					; m
	{Spreading
		{SpreadRadius 4.0}
	}
        {recoveryTime 0.125}			; s
	{rechargeTime 3.0}			; s
        {healthing  5 100 25 85 50 75 100 65 150 35}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "bar" from "mgun"
	{fireSound	"mgun_shot.bar"}
	{reloadSound "reload.bar_r"}
	{rechargeTime 2.0}			; s
	{recoverytime 0.13}			; s
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 4.5}
	}
        {healthing  5 100 25 90 50 80 100 70 150 40}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "rkm" from "mgun"
	{fireSound	"mgun_shot.bar"}
	{reloadSound "reload.bar_r"}
	{rechargeTime 2.0}			; s
	{recoverytime 0.13}			; s
	{maxRange 150}				; m
	{Spreading
		{SpreadRadius 4.5}
	}
        {healthing  5 100 25 90 50 80 100 70 150 40}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "empty" from "mgun"
	{fireSound	"mgun_shot.ZB-26-30"}		
	{maxRange 1}      					; m
	{Spreading
		{SpreadRadius 100}
	}
        {recoveryTime 100}			; s
	{rechargeTime 100}			; s
        {healthing  5 1 25 1 50 1 100 1 150 1}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "chm1924" from "mgun"
	{fireSound	"mgun_shot.chm1924"}
	{reloadSound "reload.dt1_r"}
	{rechargeTime 2.8}			; s
	{recoverytime 0.13}			; s
	{maxRange 150}				; m
	{Spreading
		{SpreadRadius 5.0}
	}
        {healthing  5 100 25 90 50 80 100 70 150 40}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "lewis" from "mgun"
	{fireSound	"mgun_shot.lewis"}
	{reloadSound "reload.lewis_r"}
	{maxRange 150}					; m
	{Spreading
		{SpreadRadius 6.3}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.14}			; s
	{rechargeTime 5.5}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	(mod "mp"
		{maxRange 150}					; m
	)
}
{weapon "lewis_tower" from "mgun"
	{fireSound	"mgun_shot.lewis"}
	{reloadSound "reload.lewis_r"}
	{maxRange 200}					; m
	{aimRange 200}				; m
	{Spreading
		{SpreadRadius 6.3}
		{BurstAccuracy 0 0 0 0 0}
	}
        {recoveryTime 0.14}			; s
	{rechargeTime 5.5}			; s
        {healthing  5 100 25 85 50 70 100 60 150 30}
	(mod "mp"
		{maxRange 200}					; m
	)
}
{weapon "flamethrower" from "mgun"
	{fireSound	"flamethrower_shot_muted.flamethrower"}
	{reloadSound "reload.flame_r"}
	{aimRange 20}				; m
	{recoveryTime 0.5}			; s
	{rechargeTime 1.5}			; s
	{speed 15}					; m/s
        {gravity 0.3}
	{maxRange 23}					; m
	{spreading
		{SpreadRadius 2.0}		; m
	}
	{piercing   10 0     30 0    150 0}
	{healthing 10 200 50 50 100 0 200 0}
	{burst
		{short 3 3}
		{long 3 3}
	}	
	(mod "mp"
                {aimRange 24}
		{maxRange 24}					; m
	)
}
{weapon "usflamethrower" from "mgun"
	{fireSound	"flamethrower_shot_muted.flamethrower"}
	{reloadSound "reload.flame_r"}
        {cursor "/interface/cursor/flamethrower.ebm"}
	{aimRange 20}				; m
	{recoveryTime 0.5}			; s
	{rechargeTime 1.5}			; s
	{speed 15}					; m/s
        {gravity 0.3}
	{maxRange 23}					; m
	{spreading
		{SpreadRadius 2.0}		; m
	}
	{piercing   10 0     30 0    150 0}
	{healthing 10 200 50 50 100 0 200 0}
	{burst
		{short 3 3}
		{long 3 3}
	}	
	(mod "mp"
                {aimRange 24}
		{maxRange 24}					; m
	)
}
{weapon "japflamethrower" from "mgun"
	{fireSound	"flamethrower_shot_muted.flamethrower"}
	{reloadSound "reload.flame_r"}
        {cursor "/interface/cursor/flamethrower.ebm"}
	{aimRange 20}				; m
	{recoveryTime 0.5}			; s
	{rechargeTime 1.5}			; s
	{speed 15}					; m/s
        {gravity 0.3}
	{maxRange 23}					; m
	{spreading
		{SpreadRadius 2.0}		; m
	}
	{piercing   10 0     30 0    150 0}
	{healthing 10 200 50 50 100 0 200 0}
	{burst
		{short 3 3}
		{long 3 3}
	}	
	(mod "mp"
                {aimRange 24}
		{maxRange 24}					; m
	)
}
{weapon "gerflamethrower" from "mgun"
	{fireSound	"flamethrower_shot_muted.flamethrower"}
	{reloadSound "reload.flame_r"}
        {cursor "/interface/cursor/flamethrower.ebm"}
	{aimRange 20}				; m
	{recoveryTime 0.5}			; s
	{rechargeTime 1.5}			; s
	{speed 15}					; m/s
        {gravity 0.3}
	{maxRange 23}					; m
	{spreading
		{SpreadRadius 2.0}		; m
	}
	{piercing   10 0     30 0    150 0}
	{healthing 10 200 50 50 100 0 200 0}
	{burst
		{short 3 3}
		{long 3 3}
	}	
	(mod "mp"
                {aimRange 24}
		{maxRange 24}					; m
	)
}
{weapon "bigflamethrower" from "mgun"
	{fireSound	"flamethrower_shot_muted.flamethrower"}
	{reloadSound "reload.flame_r"}
	{aimRange 20}				; m
	{recoveryTime 0.5}			; s
	{rechargeTime 1.5}			; s
	{speed 15}					; m/s
        {gravity 0.3}
	{maxRange 23}					; m
	{spreading
		{SpreadRadius 2.0}		; m
	}
	{piercing   10 0     30 0    150 0}
	{healthing 10 200 50 50 100 0 200 0}
	{burst
		{short 3 3}
		{long 3 3}
	}	
	(mod "mp"
                {aimRange 30}
		{maxRange 30}					; m
	)
}
{ammo "ammo mgun" from "ammo bullet"}
{ammo "ammo fire" from "ammo bullet"
	{view "fire_ammo"
		{tail "flamethrower_fx" "tail"}
	}
	{destroyViewWhenArrive}
	{damage fire
		{radius 3}
		{time 4}
		{heating 3}
	}
}
