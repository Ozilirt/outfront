;#define V_POSITION  v0
;#define V_WEIGHT  	 v1.x
;#define V_INDEX  	 v2.xy
;#define V_NORMAL  	 v3
;#define V_COLOR   	 v4
;#define V_TEX0   	 v5
;
; c0      = {1020.01, 0, 1, 0}
; c1      = light dir
; c2-c5   = view-projection matrix
; á6	  = {1/(hazeEnd - hazeStart), hazeEnd, 0, 0}
; c7	  = ambient color
; c8	  = light.diffuse
; c9-c10  = texture TM
; c11	  = camera origin
; c22-c95 = world matrix palette
;
vs.1.1

;calculate the indexed matrix constant offset
mul		r2,	v2.zyxw, c0.xxxx	; GF UBYTE4 lack compensation
;mul	r2,	v2.xy, c0.xx		; normally should be c0.x == 4.0f

mov		a0.x, r2.x
m4x3	r0, v0, c[a0.x + 22]
m3x3	r3, v3, c[a0.x + 22]
mov		a0.x, r2.y
m4x3	r1, v0, c[a0.x + 22]
m3x3	r4, v3, c[a0.x + 22]
; Lerp the two positions r0 and r1
add		r0.xyz, r0, -r1
mad		r0.xyz, v1.x, r0, r1   ; pos = (1-weight)*r1 + r0*weight = r1 - weight*(r0 - r1)
mov		r0.w, c0.z
m4x4	oPos, r0, c2

;compute dist = Distance(camera origin, vertex)
add		r1.xyz, -r0, c11
dp3		r1.x, r1, r1
rsq		r1.y, r1.x
rcp		r1.x, r1.y
; compute fog factor f = (fog_end - dist)*(1/(fog_end-fog_start))
add		r0.x, -r1.x, c6.y
mul		r0.x, r0.x, c6.x
max		r0.x, r0.x, c0.y       ; clamp fog to > 0.0
min		oFog.x, r0.x, c0.z     ; clamp fog to < 1.0

; Lerp the two normals r3 and r4
add		r3.xyz, r3, -r4
mad		r3.xyz, v1.x, r3, r4
; normalize
dp3		r3.w, r3, r3
rsq		r3.w, r3.w
mul		r3.xyz, r3, r3.w;
; Do the lighting calculation
dp3		r1.x, r3, c1  ; normal dot light
max		r1.x, r1.x, c0.y
mul		r0.xyz, r1.x, c8  ; Multiply with diffuse
mad 	r0.xyz, r0, v4, c7; Add in ambient
min		oD0.xyz, r0, c0.z ; clamp if > 1
mov		oD0.w, v4.w

mov		r0.xy, v5
mov		r0.z, c0.z
dp3 	r1.x, r0, c9
dp3 	r1.y, r0, c10
mov 	oT0.xy, r1
mov 	oT1.xy, r1
