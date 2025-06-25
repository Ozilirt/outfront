{selector
	{unit "human" "bullet"}

	{group
		{sort {class human}}
		{sort {class cannon}}
		{sort {class car}}
		{sort {class tank}}
		{sort distance}
	}

	{group
		{select {weapon "bullet"}}
		{select {weapon "grenade ap"}}
		{select {weapon "grenade fg"}}

		{sort {weapon "bullet"} {attacking}}
		{sort {weapon "grenade fg"} {attacking}}
		{sort {weapon "bullet"} {threating}}
		{sort {weapon "grenade fg"} {threating}}
		{sort {weapon "grenade ap"} {threating}}
		{sort distance}
	}
}