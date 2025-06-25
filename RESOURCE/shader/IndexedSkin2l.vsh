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
; ----- second light -----
; c12 - position
; c13 - direction
; c14 - omni parameters (range, att0, att1, att2)
; c15 - spot parameters (cos F/2, cos T/2, cos T/2 - cos F/2, falloff)
; c16 - diffuse color
; ------------------------
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
add		r1.x, -r1.x, c6.y
mul		r1.x, r1.x, c6.x
max		r1.x, r1.x, c0.y       ; clamp fog to > 0.0
min		oFog.x, r1.x, c0.z     ; clamp fog to < 1.0

; Lerp the two normals r3 and r4
add		r3.xyz, r3, -r4
mad		r3.xyz, v1.x, r3, r4
; normalize
dp3		r3.w, r3, r3
rsq		r3.w, r3.w
mul		r3.xyz, r3, r3.w
; Do the lighting calculation
dp3		r1.x, r3, c1  			; normal dot light
max		r1.x, r1.x, c0.y
mul		r11.xyz, r1.x, c8  		; Multiply with diffuse

;--------------------------------------------------------------
; dynamic light
add r8.xyz, -r0, c12
dp3 r8.w, r8, r8
rsq r11.w, r8.w
mul r5.w, r11.w, r8.w
mul r8.w, r8.w, c14.w
rcp r3.w, r5.w
mul r8.xyz, r8, r3.w
dp3 r10.w, r3, r8
max r0.w, r10.w, c0.y
slt r2.w, r5.w, c14.x
mad r9.w, r5.w, c14.z, c14.y
add r8.w, r8.w, r9.w
rcp r8.w, r8.w
mul r8.w, r0.w, r8.w
dp3 r4.w, -c13, r8
add r6.w, r4.w, -c15.x
slt r1.w, c15.x, r4.w
rcp r5.w, c15.z
mul r3.w, r6.w, r5.w
log r10.w, r3.w
mul r0.w, r10.w, c15.w
exp r7.w, r0.w
mul r9.w, r8.w, r7.w
mad r6.w, r1.w, r9.w, -r8.w
mov r0.w, c0.z				  ; <-- r0.w = 1, used in min oD0, r0, c0.z
slt r1.w, c15.x, r0.w
mad r8.w, r6.w, r1.w, r8.w
mad	r0.xyz, r8.w, c16, r11.xyz
;--------------------------------------------------------------
mad 	r0.xyz, r0, v4, c7    ; Add in ambient
min		oD0, r0, c0.z 	  ; clamp if > 1

mov		r0.xy, v5
mov		r0.z, c0.z
dp3 	r1.x, r0, c9
dp3 	r1.y, r0, c10
mov 	oT0.xy, r1
mov 	oT1.xy, r1
