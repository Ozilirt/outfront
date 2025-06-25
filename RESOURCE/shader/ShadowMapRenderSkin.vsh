;#define V_POSITION  v0
;#define V_WEIGHT  	 v1
;#define V_COLOR   	 v2
;#define V_TEX0   	 v3
;
;#define CV_SHADOWMAPPROJ_0		 2
;#define CV_SHADOWMAPPROJ_1		 15

vs.1.0

m4x4	r0, v0, c2
m4x4	r1, v0, c15
; Lerp the two positions r0 and r1 into r2
mul 	r0, r0, v1.x     ; v0 * weight
add 	r2, c1.x, -v1.x  ; r2 = 1 - weight
mad		r0, r1, r2, r0   ; pos = (1-weight)*v1 + v0*weight
mov		oPos, r0

; copy depth to diffuse alpha
rcp		r1, r0
mov		oD0.xyz, c0
mul		oD0.w, r0.z, r1.w
; pass through UVs
mov 	oT0.xy, v3
