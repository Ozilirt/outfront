;SDL

{State "boarding"
	{tag "onboard"}
}
;{State "unboarding_to_ground"
;	{condition "unboard-to-ground"}
;	{to "stand"}
;	{tag "onboard"}
;}
;{State "unboarding_to_water"
;	{condition "unboard-to-water"}
;	{to "swim_idle"}
;	{tag "onboard"}
;}
{State "board"
	{condition "board"}
	{from "stand"}
;	{to "unboarding_to_ground"}
;	{to "unboarding_to_water"}
	{tag "board"}
	{tag "onboard"}
	{tag "stored"}
}
