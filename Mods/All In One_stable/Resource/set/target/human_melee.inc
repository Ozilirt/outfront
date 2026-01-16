{selector
	{unit "human" "melee"}

	{group
		{sort {attacking}}
		{sort {class human} {weapon "bullet"}}
		{sort {class human} {weapon "melee"}}		
		{sort {class human} {weapon}}
		{sort {class tank}}
		{sort {weapon}}
		{sort {class human}}
		{sort distance}
	}
	{group
		{sort distance}
	}
}