{selector
	{units "mg34_stan" "mg34_dot" "mg34_tower" "browning_stan" "flak38" "flak-38-1" "shipflak" "doublecolt"}

	{group
		{select {class car}}
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
