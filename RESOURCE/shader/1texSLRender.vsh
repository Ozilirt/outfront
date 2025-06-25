;#define V_POSITION  v0
;#define V_COLOR   	 v2
;#define V_TEX0   	 v3
;
;#define CV_PROJ_0		 2

vs.1.0

; transform to proj space
m4x4	oPos, v0, c2
mov		oD0, v2
dp4 	oT0.x, v3, c9
dp4 	oT0.y, v3, c10
mov		oFog, c0
