{kh_trench
	{name 		"mission/mp/trench/name"}
	{location 	"multi/trench:kh"}
	{game 		"hill"}
	{maxPlayers "16"}
	{maxUnits 	"10"}
	{balance 	"2000"}
	{zone		"zone"}
	{wincost 	"2000"}
	{allowance 	"1000"}
	{teams
		{x "mp_settings/teamx"
			{maxPlayers "8"}
		}
		{z "mp_settings/teamz"
			{maxPlayers "8"}
		}
	}
}
{cm_trench
	{name 		"mission/mp/trench/name"}
	{location 	"multi/trench:cm"}
	{game 		"combat"}
	{maxPlayers "16"}
	{maxUnits 	"10"}
	{deathmatch "0"}
	{balance 	"900"}
	{teams
		{x "mp_settings/teamx"
			{maxPlayers "8"}
		}
		{z "mp_settings/teamz"
			{maxPlayers "8"}
		}
	}
}
{as_trench
	{name 		"mission/mp/trench/name"}
	{location 	"multi\trench:as"}
	{game 		"assault"}
	{maxUnits 	"10"}
	{balance 	"900"}
	{zone		"zone"}
	{teams
		{a "mp_settings/teama"}
		{d "mp_settings/teamd"}
	}
}
