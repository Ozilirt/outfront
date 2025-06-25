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
; c13 - direction, spot falloff
; c14 - omni parameters (range, att0, att1, att2)
; c15 - spot parameters (cos F/2, cos T/2, cos T/2 - cos F/2, 1)
; c16 - diffuse color
; ----- third light -----
; c17 - position
; c18 - direction, spot falloff
; c19 - omni parameters (range, att0, att1, att2)
; c20 - spot parameters (cos F/2, cos T/2, cos T/2 - cos F/2, 1)
; c21 - diffuse color
; ------------------------
; c22-c94 = world matrix palette
; c95	  = {0,0,1,0}
vs.1.1

;calculate the indexed matrix constant offset
mul		r2,	v2.zyxw, c0.x	; GF UBYTE4 lack compensation
;mul	r2.xy,	v2.xy, c0.x		; normally should be c0.x == 4.0f

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
;add		r1.xyz, -r0, c11
;dp3		r1.x, r1, r1
;rsq		r1.y, r1.x
;rcp		r1.x, r1.y  ; mul r1.x, r1.x, r1.y
; compute fog factor f = (fog_end - dist)*(1/(fog_end-fog_start))
;add		r1.x, -r1.x, c6.y
;mul		r1.x, r1.x, c6.x
;max		r1.x, r1.x, c0.y       ; clamp fog to > 0.0
;min		oFog.x, r1.x, c0.z     ; clamp fog to < 1.0
mov		oFog.x, c0.z

; Lerp the two normals r3 and r4
add		r3.xyz, r3, -r4
mad		r3.xyz, v1.x, r3, r4
; normalize
;dp3		r3.w, r3, r3
;rsq		r3.w, r3.w
;mul		r3, r3, r3.w;
; Do the lighting calculation
dp3		r1.x, r3, c1  ; normal dot light
max		r1.x, r1.x, c0.y
mul		r2.xyz, r1.x, c8  ; Multiply with diffuse

;--------------------------------------------------------------
; dynamic lights
;mul r6, v1.x, c22
;mad r8, v1.y, c23, r6
;mad r10, v1.z, c24, r8
;dp4 r10.w, r10, r10
;rsq r10.w, r10.w
;mul r5.xyz, r10, r10.w		; r5->r3 (normal)

;mul r0.xyz, v0.x, c22
;mad r2.xyz, v0.y, c23, r0
;mad r4.xyz, v0.z, c24, r2
;mad r6.xyz, v0.w, c25, r4	; r6->r0 (position)

add r8.xyz, -r0, c12
add r5.xyz, -r0, c17
dp3 r8.w, r8, r8
rsq r9.w, r8.w
mul r5.w, r9.w, r8.w
mul r8.w, r8.w, c14.w
rcp r3.w, r5.w
mul r8.xyz, r8, r3.w
dp3 r3.w, r3, r8
max r3.w, r3.w, c0.y
mad r6.w, r5.w, c14.z, c14.y
slt r5.w, r5.w, c14.x
add r8.w, r8.w, r6.w
rcp r8.w, r8.w
mul r3.w, r3.w, r8.w
dp3 r2.w, -c13, r8
add r4.w, r2.w, -c15.x
slt r11.w, c15.x, r2.w
rcp r0.w, c15.z
mul r1.w, r4.w, r0.w
log r10.w, r1.w
mul r6.w, r10.w, c13.w
exp r8.w, r6.w
mul r7.w, r3.w, r8.w
mad r4.w, r11.w, r7.w, -r3.w
slt r11.w, c15.x, c15.w	;--------
mad r3.w, r4.w, r11.w, r3.w
mul r1, r3.w, c16
mul r10, r5.w, r1
dp3 r5.w, r5, r5
rsq r1.w, r5.w
mul r3.w, r1.w, r5.w
mul r5.w, r5.w, c19.w
slt r6.w, r3.w, c19.x
slt r8.w, c20.x, c20.w	;--------
rcp r7.w, r3.w
mul r5.xyz, r5, r7.w
dp3 r2.w, -c18, r5
dp3 r9.w, r3, r5
slt r4.w, c20.x, r2.w
max r11.w, r9.w, c0.y
mad r0.w, r3.w, c19.z, c19.y
add r1.w, r5.w, r0.w
rcp r7.w, r1.w
mul r3.w, r11.w, r7.w
add r2.w, r2.w, -c20.x
rcp r9.w, c20.z
mul r11.w, r2.w, r9.w
log r0.w, r11.w
mul r1.w, r0.w, c18.w
exp r7.w, r1.w
mul r5.w, r3.w, r7.w
mad r9.w, r4.w, r5.w, -r3.w
mad r3.w, r8.w, r9.w, r3.w
mul r11, r3.w, c21
mad r10, r6.w, r11, r10

add	r0.xyz, r10, r2
;--------------------------------------------------------------
;mad 	r0.xyz, r0, v4, c7    ; Add in ambient
;min	oD0.xyz, r0, c0.z 	  ; clamp if > 1
mad 	oD0.xyz, r0, v4, c7   ; Add in ambient
mov		oD0.w, v4.w

add		r0.xyz, v5, c95
dp3 	r1.x, r0, c9
dp3 	r1.y, r0, c10
mov 	oT0.xy, r1
mov 	oT1.xy, r1
