{selector
	{units "hotchkiss_tower" "hotchkiss_stan" "hotchkiss_dot" "maxim_2" "50cal_stan" "50cal_tower" "dt_dot" "dshk_stan" "dshk_tower" "dshk_ship" "mg34_stan" "mg34_dot" "mg34_tower" "mg34_ship" "mg34_uboat" "mg42_ship" "mg42_stan" "mg42_dot" "mg42_tower" "degtyarev_stan" "degtyarev_dot" "degtyarev_tower" "wz33_stan" "wz33_dot" "wz33_tower" "vickers_stan" "vickers_dot" "vickers_tower" "vickers_ship" "besa_stan" "besa_dot" "browning_stan" "browning_dot" "browning_tower" "browning_ship" "flak38" "flak38s" "flak-38-1" "shipflak" "shipflak2" "doublecolt" "besa15mm" "twincolt"  "type1_stan" "type1_dot" "type1_tower" "type93_stan" "type93_tower" "type93_turret" "type92_stan" "type97mg_stan" "type97mg_dot" "type97mg_tower" "m45quad"}

	{group
		{select {class human}}
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}
	}

	{group
		{sort {attacking}}
		{sort distance}
	}
}
