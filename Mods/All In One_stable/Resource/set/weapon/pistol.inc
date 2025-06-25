  

;SDL

{weapon pattern "pistol" from "bullet"
	{aimRange 20}				; m
	{recoveryTime 0.3}			; s
	{rechargeTime 3}			; s
	{maxRange 30}				; m
	{spreading
		{SpreadRadius 2} ; m
	}
	{speed 80}					; m/s
	{healthing 5 70  10 50  25 35  50 20}
	{piercing  10 2  20 1 40 0}
	{burst
		{short 1.5 0.5}
		{long 3.5 0.5}
	}	
	(mod "mp"
		{maxRange}					; m
	)
}
;=================9x21(Parabelum)==================

{weapon "valter" from "pistol"
	{fireSound	"pistol_shot.valter"}
	{maxRange 40}				; m
	{reloadSound "reload.pistol_r"}
        {speed 90}
	{healthing 5 70  10 60  25 35  50 5}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "luger" from "pistol"
	{fireSound	"pistol_shot.luger"}
	{maxRange 40}				; m
	{reloadSound "reload.pistol_r"}
        {speed 90}
	{healthing 5 75  10 65  25 35  50 5}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "nambu" from "pistol"
	{fireSound	"pistol_shot.nambu"}
	{maxRange 38}				; m
	{reloadSound "reload.pistol_r"}
        {speed 90}
	{healthing 5 75  10 65  25 35  50 5}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "type26" from "pistol"
	{fireSound	"pistol_shot.type26"}
	{maxRange 36}				; m
	{reloadSound "reload.nagan_r"}
        {speed 80}
	{healthing 5 65  10 45  25 30  50 5}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "nambu94" from "pistol"
	{fireSound	"pistol_shot.type94"}
	{maxRange 37}				; m
	{reloadSound "reload.pistol_r"}
        {speed 84}
	{healthing 5 70  10 60  25 30  50 5}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "mauserc96" from "pistol"
	{fireSound	"pistol_shot.c96"}
	{maxRange 44}				; m
	{reloadSound "reload.c96_r"}
        {speed 90}
	{healthing 5 77  10 66  25 36  50 6}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "mauserm712" from "pistol"
	{recoveryTime 0.1}			; s
	{fireSound	"pistol_shot.c96"}
	{maxRange 44}				; m
	{reloadSound "reload.c96_r"}
        {speed 90}
	{Automatic}
	{healthing 5 77  10 66  25 36  50 6}
	{burst
                {min 1}
		{short 4.5 2.5}
		{long 7.5 3.5}
	}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
;================7.62==============================


{weapon "tt" from "pistol"
	{fireSound	"pistol_shot.tt"}
	{maxRange 40}				; m
	{reloadSound "reload.pistol_r"}
        {speed 100}
	{healthing 5 70  10 50  25 30  50 5}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "vis" from "tt"
	{fireSound	"pistol_shot.tt"}
	{maxRange 38}				; m
        {healthing 5 55  10 45  25 25  50 5}
	{reloadSound "reload.nagan_r"}
        {speed 90}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "nagan" from "tt"
	{fireSound	"pistol_shot.nagan"}
	{maxRange 35}				; m
        {healthing 5 55  10 45  25 25  50 5}
	{reloadSound "reload.nagan_r"}
        {speed 75}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "mle1935a" from "tt"
	{fireSound	"pistol_shot.mle1935a"}
	{maxRange 35}				; m
        {healthing 5 55  10 45  25 25  50 5}
	{reloadSound "reload.pistol_r"}
        {speed 85}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}
{weapon "welrod" from "tt"
	{fireSound	"pistol_shot_silent.welrod2"}
	{maxRange 30}				; m
        {healthing 5 100  10 80  25 80  50 1}
	{spreading
		{SpreadRadius 1} ; m
	}
	{reloadSound "reload.welrod_r"}
        {speed 50}
        (mod "mp"
		{maxRange 30}					; m
                {aimRange 10}
	)
}
;=====================.45cal=====================
{weapon "colt" from "pistol"
	{fireSound	"pistol_shot.colt"}
	{reloadSound "reload.colt_r"}
	{maxRange 45}				; m
	{rechargeTime 2}			; s
	{healthing 5 100  10 80  25 40  50 6}
        (mod "mp"
		{maxRange}					; m
                {aimRange 60}
	)
}
{weapon "webley" from "colt"
	{fireSound	"pistol_shot.webley"}
	{maxRange 35}				; m
	{reloadSound "reload.webley_r"}
        {healthing 5 70  10 50  25 30  50 5}
        {speed 90}
        (mod "mp"
		{maxRange}					; m
                {aimRange 50}
	)
}


{ammo "ammo pistol" from "ammo bullet"}
  

