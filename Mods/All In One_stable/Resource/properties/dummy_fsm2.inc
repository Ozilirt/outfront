{FSM
	{Request "reload" 		{priority 0}}
	{Request "unload" 		{priority 0}}
	{Request "fire" 		{priority 0}}
	{Request "fire-heavy_mgun" 		{priority 0}}
	{Request "rotate"		{priority 0}}
	{Request "recoil"			{priority 0}}
	{Request "inventory-pick"	{priority 0}}
	{Request "inventory-drop"	{priority 0}}
	{Request "aim"				{priority 0}}
	{Request "aim-heavy_mgun" 		{priority 0}}
	
    {Start "common"}
	{State "common"
		{tag "reload"}
		{tag "unload"}
		{tag "fire"}
		{tag "fire-heavy_mgun"}
		{tag "rotate"}
		{tag "inventory-pick"}
		{tag "inventory-drop"}
		{tag "recoil"}
		{tag "aim"}
		{tag "aim-heavy_mgun"}
	}
}
