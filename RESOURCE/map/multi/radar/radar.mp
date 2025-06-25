{kh_radar
	{name 		"mission/mp/radar/name"}
	{location 	"multi\radar:kh"}
	{game 		"hill"}
	{zone 		"zone"}
	{maxPlayers "16"}
	{maxUnits 	"10"}
	{balance 	"2000"}
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
{cm_radar
	{name 		"mission/mp/radar/name"}
	{location 	"multi\radar:cm"}
	{game 		"combat"}
	{maxPlayers "16"}
	{maxUnits 	"7"}
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
{as_radar
	{name 		"mission/mp/radar/name"}
	{location 	"multi\radar:as"}
	{game 		"assault"}
	{maxUnits 	"10"}
	{balance 	"900"}
	{zone		"zone"}
	{teams
		{a "mp_settings/teama"}
		{d "mp_settings/teamd"}
	}
}
