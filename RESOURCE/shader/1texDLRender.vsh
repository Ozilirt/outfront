;#define V_POSITION  v0
;#define V_NORMAL  	 v1
;#define V_COLOR   	 v2
;#define V_TEX0   	 v3
;
;#define CV_PROJ_0		 2
;#define CV_OBJLIGHT_DIR 21
;#define CV_LIGHT_AMBIENT 22
;#define CV_LIGHT_DIFFUSE 23

vs.1.0

; transform to proj space
m4x4	oPos, v0, c2
dp3		r1.x, v1, -c21
max		r1.x, r1.x, c0.x
mul		r0, c23, r1.x
mad		r1, v2, r0, c22
min		oD0.xyz, r1.xyz, c1.x
mov		oD0.w, v2.w
dp4 	oT0.x, v3, c9
dp4 	oT0.y, v3, c10
mov		oFog, c0