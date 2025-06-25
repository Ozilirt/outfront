;#define V_POSITION  v0
;#define V_NORMAL    v1
;
;#define CV_ZERO				 0
;#define CV_ONE					 1
;#define CV_WORLD				 2
;#define CV_VIEWPROJ			 6
;#define CV_LIGHT_POS_OSPACE     21
;#define CV_LIGHT_POS_WSPACE	 22
;#define 1/CV_LIGHT_POS_WSPACE	 23
;#define CV_WORLD_MIN_Z			 24

vs.1.0

; N dot L
dp3 r4, c21, -v1

; If r4 < 0 then vertex faces away from light, so 
;  move it along the direction to the light to extrude the
;  shadow volume.

; r5 = (N dot L) < 0 ? 1 : 0
slt  r5, r4, c0

; world vertex position
m4x3 r1, v0, c2
mov r1.w, c1.x

;lightDir * (v0.z - minZ) / lightDir.z
add r2.z, r1.z, -c24.z
mul r2, r2.z, c23.z
mul r2, r2, -c22

; extrude back-facing shadow volume points 
mad r2, r2, r5, r1

; transform to hclip space
m4x4 oPos, r2, c6
