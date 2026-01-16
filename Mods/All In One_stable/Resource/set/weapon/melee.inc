;SDL

{weapon pattern "melee"
	;{type bullet}
	{maxRange 1}
	{states
		{fire	"fire"}
;		{fire	"blow"}
		{reload "reload"}
		{unload "unload"}
		{aim 	"aim-thrower"}
		;{aim 	"aim"}
	}
	{foresight "Foresight2"}
	{AimingTolerance 5}				; degree
  
	{aimRange 8}					; m
	{spreading {SpreadRadius 0.0}}	; m
	{gravity  1}
	{item "szabla"}
}

