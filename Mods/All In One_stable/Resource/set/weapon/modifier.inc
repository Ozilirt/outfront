{modifier "running"
	{SpreadRadius		mul 2}
	{SpreadXYRatio		set 50}
	{SpreadPower		set 2}
	{BurstRecoveryTime	mul 2}
	{BurstAccuracy		70 60 30 10 5}
}
{modifier "sitting"
	{SpreadRadius	 	mul 0.5}
	{SpreadXYRatio		set 1}
	{SpreadPower		set 0.5}
	{BurstRecoveryTime	mul 0.5}
	{BurstAccuracy		set 95 60 30 10 5}
}

{modifier "human.forceful"
;		{SpreadRadius		mul 2}
;		{SpreadXYRatio		set 50}
;		{SpreadPower		set 2}
;		{BurstRecoveryTime	mul 2}
}
{modifier "human.tired"
	{SpreadRadius		mul 2}
;		{SpreadXYRatio		mul 2}
;		{SpreadPower		mul 2}
	{burstSpreadDelta mul 2}
	{burstSpreadWidth mul 2}
	{BurstRecoveryTime	mul 2}
}
{modifier "human.exhausted"
	{SpreadRadius		mul 5}
	{burstSpreadCount 	7}
	{burstSpreadDelta mul 5}
	{burstSpreadWidth mul 5}
;		{SpreadXYRatio		mul 10}
;		{SpreadPower		mul 4}
	{BurstRecoveryTime	mul 5}
}
