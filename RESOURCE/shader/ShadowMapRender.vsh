;#define V_POSITION  v0
;#define V_NORMAL  	 v1
;#define V_COLOR   	 v2
;#define V_TEX0   	 v3
;
;#define CV_SHADOWMAPPROJ_0		 2

vs.1.0

; transform to light space
m4x4	r0, v0, c2
mov		oPos, r0
; copy depth to diffuse alpha
rcp		r1, r0
mov		oD0.xyz, c0
mul		oD0.w, r0.z, r1.w
; pass through UVs
mov 	oT0.xy, v3
