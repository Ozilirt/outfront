;#define V_POSITION  v0
;#define V_WEIGHT  	 v1
;#define V_COLOR  	 v2
;#define V_TEX0   	 v3
;
;#define zBias					14
;#define CV_WORLDVIEWPROJ_0		2
;#define CV_SHADOWMAPPROJ_1		15
;#define CV_SHADOWMAPPROJ_0		6
;#define CV_UVTM		 		9

vs.1.0

;------------------------------------------------------------------------------
; Vertex blending
;------------------------------------------------------------------------------
m4x4	r0, v0, c2
m4x4	r1, v0, c15
; Lerp the two positions r0 and r1 into r2
mul 	r0, r0, v1.x     ; v0 * weight
add 	r2, c1.x, -v1.x  ; r2 = 1 - weight
mad		oPos, r1, r2, r0   ; pos = (1-weight)*v1 + v0*weight

; transform to light space
m4x4	r0, v0, c6

; apply zBias
; copy depth to diffuse alpha
rcp		r1, r0
mul		r0, r0, r1
sub		oD0.w, r0.z, c14.z

; generate automatic UVs
m4x4	r1, r0, c9
mov 	oT0.xy, r1



