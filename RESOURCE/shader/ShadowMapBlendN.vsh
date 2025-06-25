;#define V_POSITION  v0
;#define V_NORMAL  	 v2
;#define V_TEX0   	 v3
;
;#define zBias					14
;#define CV_WORLDVIEWPROJ_0		2
;#define CV_SHADOWMAPPROJ_0		6
;#define CV_UVTM		 		9

vs.1.0

; transform to proj space
m4x4	oPos, v0, c2
; transform to light space
m4x4	r0, v0, c6
; ckeck for light backface
dp3		r1.x, v2, c21
slt  	r5.x, r1.x, c0.x
; apply zBias
; copy depth to diffuse alpha
rcp		r1, r0
mul		r0, r0, r1
;sub		oD0.w, r0.z, c14.z
mad		oD0.w, r0.z, r5.x, -c14.z
; generate automatic UVs
m4x4	r1, r0, c9
mov 	oT0.xy, r1
